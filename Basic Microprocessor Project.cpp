#include <iostream>
#include <windows.h>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <conio.h>
#include <ctime>
#include <dos.h>
#include <iomanip>
#include <sstream>
using namespace std;
int A=0;
int B=0;
int C=0;
int D=0;
int E=0;
int H=0;
int L=0;
int SP=28;
int M[50];

class Format
{
    public:
        void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    string Hx(long int num)
    {
        char hexdigit[]="0123456789ABCDEF";
        int rem,index=0;
        char hexno[99];
        while(num!=00)
        {
            rem=num%16;
            hexno[index]=hexdigit[rem];
            num=num/16;
            index++;
        }
        hexno[index]='\0';
        strrev(hexno);
        return (hexno);
    }

        void LINE_HOR(int column1, int column2, int row, char c)
        {

        for ( column1; column1<=column2; column1++ )
        {
        gotoxy(column1,row);
        cout <<c ;
        }
    }
    void LINE_VER(int row1, int row2, int column, char c)
    {
        for ( row1; row1<=row2; row1++)
        {
        gotoxy(column,row1) ;
        cout <<c ;
        }
    }
    //**********************************************************
    // FUNCTION TO DRAW BOX LINE
        //**********************************************************

    void  BOX(int column1, int row1, int column2, int row2, char c)
        {
        char ch=218 ;
        char c1, c2, c3, c4 ;
        char l1=196, l2=179 ;
        if (c == ch)
        {
            c1=218 ;
            c2=191 ;
            c3=192 ;
            c4=217 ;
            l1 = 196 ;
            l2 = 179 ;
        }
        else
        {
        c1=c ;
        c2=c ;
        c3=c ;
        c4=c ;
        l1 = c ;
        l2 = c ;
        }
        gotoxy(column1,row1) ;
        cout <<c1 ;
        gotoxy(column2,row1) ;
        cout <<c2 ;
            gotoxy(column1,row2) ;
        cout <<c3 ;
        gotoxy(column2,row2) ;
        cout <<c4 ;
        column1++ ;
        column2-- ;
        LINE_HOR(column1,column2,row1,l1) ;
        LINE_HOR(column1,column2,row2,l1) ;
        column1-- ;
        column2++ ;
        row1++ ;
        row2-- ;
        LINE_VER(row1,row2,column1,l2);
        LINE_VER(row1,row2,column2,l2);
    }
    void Memory()
        {
            BOX(44,19,78,50,218);//Memory Dividers
            LINE_VER(20,49,53,179);
            LINE_VER(20,49,61,179);
            LINE_VER(20,49,70,179);
            LINE_HOR(45,77,21,196);
            gotoxy(46,18);
            cout<<"Memory";
            gotoxy(45,20);
            cout<<"Address";
            gotoxy(55,20);
            cout<<"Data";
            gotoxy(62,20);
            cout<<"Address";
            gotoxy(72,20);
            cout<<"Data";
            for(int i=1;i<=28;i++)
            {

                ::M[i]=0;//initiall set data 0 to all available memory address
            }

            int x=47,y=22;
            for(int i=1;i<=28;i++)
            {
                gotoxy(x,y);
                cout<<i;//output a hex converted address
                gotoxy(x+8,y);//goto place where next address has to writE
                cout<<(::M[i]);//output hex value of memory
                if(i==14)
                {
                    x=64;//for next row of memory
                    y=20;
                }
                x=x;
                y=y+2;
            }
            gotoxy(7,57);
        }
        void Flags()
        {
            BOX(57,5,63,8,218);//Accumulator
          //  LINE_VER(6,7,75,179);
           // LINE_VER(6,7,72,179);
           // LINE_VER(6,7,69,179); // Accumulator divider
           // LINE_VER(6,7,66,179);
            //LINE_VER(6,7,63,179);
            LINE_VER(6,7,60,179);
           // LINE_VER(6,7,78,179);
            gotoxy(56,3);//for flags
            cout<<"Flags";
            gotoxy(58,4);
            cout<<"s";
            gotoxy(61,4);
            cout<<"z";
             LINE_VER(1,50,82,179);// seprator line

        }
        void Registers()
        {
            BOX(40,5,50,15,218);//registers
            LINE_VER(6,12,45,179);//dividing registers
            LINE_HOR(41,49,7,196);
            LINE_HOR(41,49,9,196);
            LINE_HOR(41,49,11,196);
            LINE_HOR(41,49,13,196);
            gotoxy(38,1);
            cout<<"Basic Computer Registers and Accumulator";
            gotoxy(39,6);
            cout<<"A";
            gotoxy(51,6);
            cout<<"F";
            gotoxy(39,8);
            cout<<"B";
            gotoxy(51,8);
            cout<<"C";
            gotoxy(39,10);
            cout<<"D";
            gotoxy(51,10);
            cout<<"E";
            gotoxy(39,12);
            cout<<"H";
            gotoxy(51,12);
            cout<<"L";
            gotoxy(38,14);
            cout<<"SP";//initialize registers

        }
        void Codepart()//place where we write source code
        {
            int x=3,y=9;
            BOX(0,2,28,50,218);//coding part
           // LINE_VER(9,55,5,179);//to seprate code number
            gotoxy(2,1);
            cout<<"\tSource code here";
           /* for(int i=1;i<=24;i++)
            {
                gotoxy(x,y);
                cout<<i;
                y=y+2;//Numbering the coding part
            }
            */
            gotoxy(0,9);
        }
            void Refreshout()
            {
               gotoxy(46,6);
               if(::A<0&&::A==0)
                      cout<<3;
                else if(::A<0&&::A!=0)
                    cout<<2;
                else if(::A>0&&::A==0)
                    cout<<1;
                else if(::A>0&&::A!=0) //all these code for value of F register which holds flag values.
                    cout<<0;

            gotoxy(46,8);
            cout<<::C;
            gotoxy(46,10);
            cout<<::E;
            gotoxy(46,12);
            cout<<::L;
            gotoxy(42,6);
            cout<<::A;
            gotoxy(42,8);
            cout<<::B;
            gotoxy(42,10);
            cout<<::D;
            gotoxy(42,12);
            cout<<::H;
            gotoxy(42,14);
            cout<<::SP;
           // gotoxy(56,3);//for flags
           // cout<<"Flags";
            gotoxy(58,7);
            if(::A<0)
            cout<<"1";
            else cout<<"0";
            gotoxy(61,7);
            if(::A==0)
            cout<<"1";
            else cout<<"0";
            gotoxy(64,7);
            //cout<<"0";
            gotoxy(67,7);
            //cout<<"1";
            gotoxy(70,7);
            //cout<<"0";
            gotoxy(73,7);
            //cout<<"0";
            gotoxy(76,7);
            //cout<<"0";
            gotoxy(79,7);
            //cout<<"0";
            //for memory data refresh
            int x=47,y=22;
            for(int i=1;i<=28;i++)
            {
               // gotoxy(x,y);
               // cout<<Hx(i);//converting to hexadecimal
                gotoxy(x+8,y);//goto place where next address has to write
                cout<<(::M[i]);//output a hex converted value
                if(i==14)
                {
                    x=64;//for next row of memory
                    y=20;
                }
                x=x;
                y=y+2;
            }
             gotoxy(7,57);
        }
};

class Item:protected Format
{
char opcode[50]; //  opcode
char code[50] ; // code

public:
void readdata(void) ;
int writedata(int comp) ;
int values (string);
string retopcode()
{
    return (opcode);
}

} ;
void Item:: readdata(void) // read from keyboard.
{
cin>>opcode;

cin>>code;
}

 int Item:: values (string oprand)
                {
                    if(oprand=="A")
                    return ::A;
                    else if(oprand=="B")
                   return ::B;
                    else if(oprand=="C")
                   return ::C;
                    else if(oprand=="D")
                   return ::D;
                    else if(oprand=="E")
                   return ::E;
                    else if(oprand=="H")
                   return ::H;
                    else if(oprand=="L")
                   return ::L;
                    else if(oprand=="M")
                   return ::M[H];
                   else
                   {
                   char coprand[5];
                   int i;
                for(int i=0;i<=3;i++) //let change string operands into character
    {
        coprand[i]=oprand[i];
    }

    //let change characters operands into integers

    int ioprand=atoi (coprand);

    return (ioprand);
                   }


                }

int Item:: writedata(int comp) // for display.
{



  string str (code);
  string subwhen (",");

  // let's replace the first string code:
  str.replace(str.find(subwhen),subwhen.length()," ");
    istringstream iss(str);

            string oprand1;
        iss >> oprand1;
        int v1;
        v1=values(oprand1);
        int v2;



      if(iss!=0)
       {
           string oprand2;
           iss >> oprand2;
           int i;
           v2=values(oprand2);

       }

        string OPCODE;

        OPCODE=retopcode();
        int t1,t2;
    if (OPCODE=="LDA")
            {
                ::A=::M[v1];
               // cout<<"A= "<<A<<endl;
            }
        else if(OPCODE=="LXI")
            {

                if(v1==H)
                    ::H=M[v2];

              else if (v1==D)
                ::H=M[v2];
                else
                    return (1);
            }
        else if(OPCODE=="MOV"||OPCODE=="MVI")
            {
               if (v1==A)
               {
                   ::A=v2;
               }

                else if(v1==B)
                {
                    ::B=v2;
                }

              else if (v1==C)
              {
                  ::C=v2;
              }

              else if (v1==D)
              {
                  ::D=v2;
              }

                else if (v1==E)
                {
                    ::E=v2;
                }

                else if (v1==H)
                {
                    ::H=v2;
                }

                else if (v1=='M')
                {
                    M[H]=v2;
                }
                else
                    return (1);

            }
            else if(OPCODE=="PUSH")
            {
                ::SP=::SP-1;
                ::M[::SP]=v1;

            }
             else if(OPCODE=="POP")
            {
                v1=::M[::SP];
                ::SP=::SP+1;
            }
             else if(OPCODE=="STA")
            {
                ::M[v1]=::A;
            }
             else if(OPCODE=="XCHG")
            {
                t1=D;
                t2=E;
                D=H;
                E=L;
                H=t1;
                L=t2;
            }
            else if(OPCODE=="ADD"||OPCODE=="ADI"||OPCODE=="ADC")
            {
                ::A=::A+v1;
            }
            else if(OPCODE=="SUB"||OPCODE=="SBI"||OPCODE=="SBB")
            {
                ::A=::A-v1;
            }
            else if(OPCODE=="INR"||OPCODE=="INX")
            {
                 if(v1==B)
                ::B=::B+1;
              else if (v1==C)
                ::C=::C+1;
              else if (v1==D)
                ::D=::D+1;
                else if (v1==E)
                ::E=::E+1;
                else if (v1==H)
                ::H=::H+1;
                else if (v1==L)
                ::L=::L+1;
                else if (v1==A)
                ::A=::A+1;
                else if (v1=='M')
                ::M[H]=::M[H]+1;
                else
                    return (1);

            }
            else if(OPCODE=="DCR"||OPCODE=="DCX")
            {
                 if(v1==B)
                ::B=::B-1;
              else if (v1==C)
                ::C=::C-1;
              else if (v1==D)
                ::D=::D-1;
                else if (v1==E)
                ::E=::E-1;
                else if (v1==H)
                ::H=::H-1;
                else if (v1==L)
                ::L=::L+1;
                else if (v1==A)
                ::A=::A-1;
                else if (v1=='M')
                ::M[H]=::M[H]-1;
                else
                    return (1);

            }
             else if(OPCODE=="ANI"||OPCODE=="ANA")
            {
                ::A=::A & v1;
            }
            else if(OPCODE=="ORI"||OPCODE=="ORA")
            {
                ::A=::A | v1;
            }
            else if(OPCODE=="XRI"||OPCODE=="XRA")
            {
                ::A=::A | v1;
            }
            else if(OPCODE=="CMA"||OPCODE=="CMI")
            {
                ::A=~::A;
            }
            else if(OPCODE=="CMP")
            {
                if (::A<v1)

                ::A=v1;
            }
            else if(OPCODE=="JMP")
            {
                //wait you wii get your operation later
            }
            else if(OPCODE=="HLT")
            {
                //wait you wii get your operation later
            }


            else
            {
                //cout<<"code not registered:\n";
                return (1);
            }
        if(comp!=2)
        {
            Refreshout();
        }
        else
        {
            Memory();
            ::A=::B=::C=::D=::E=::H=::L=0;
        }



//cout<<opcode<<"\t"<<code<<endl ;
}

void Insert() // function to write in a binary file.
{
ofstream file;
file.open("instruction.dat ", ios::binary);
Item obj;
//cout<<"Enter your source code\n";
do{
obj.readdata();
file.write((char*)&obj, sizeof(obj));

}while(obj.retopcode()!="HLT");

file.close();
}

void Display(int sel=1) // function to display records of file on screen, formatted output.
{
    int error;
ifstream file;
file.open("instruction.dat ", ios::binary);
Item obj;
while(file.read((char*)&obj, sizeof(obj)))
{
   error=obj.writedata(sel);

        if(sel==1||sel==2)
        {

        }
            if(sel==4)
            getch();
            else
            Sleep(sel);
}

        cout<<"Compile Success"<<setw(25);
        if(error==1)
        {
            cout<<"\With Error in source code "<<endl;
        }
        else
            cout<<"With No Error"<<endl;


file.close();
}


int main()
{
    Format F1;
    int r,choice;
    char ch;
    F1.Registers();
    F1.Flags();
    F1.Memory();
    F1.Codepart();
do
{
    F1.gotoxy(83,5);
    cout<<".................................."<<endl;
    F1.gotoxy(83,6);
    cout<<".................................."<<endl;
    F1.gotoxy(84,7);
    cout<<"***************MENU*************"<<endl;
    F1.gotoxy(86,9);
    cout<<"1.WRITE SOURCE CODE"<<endl;
    F1.gotoxy(86,11);
    cout<<"2.COMPILE/ASSEMBLE"<<endl;
    F1.gotoxy(86,13);
    cout<<"3.RUN CODE"<<endl;
    F1.gotoxy(86,15);
    cout<<"4.SINGLE STEP"<<endl;
    F1.gotoxy(86,17);
    cout<<"5.SET DELAY"<<endl;
    F1.gotoxy(86,19);
    cout<<"6.WRITE DATA IN MEMORY"<<endl;
    F1.gotoxy(86,21);
    cout<<"7.EXIT"<<endl;
    F1.gotoxy(86,23);
    cout<<"ENTER YOUR CHOICE: "<<endl;
    F1.gotoxy(86,25);
    cin>>choice;
    F1.gotoxy(86,27);

//getch();

switch(choice)
{
case 1:
F1.gotoxy(0,4);
Insert();
break;
case 2:
F1.gotoxy(5,57);
Display(2);

break;
case 3:
Display();
break;
case 4:
    Display(4);
    break;
case 5:
    int delay;
    cout<<"ENTER DELAY IN MILISECOND";
    F1.gotoxy(86,29);
    cin>>delay;
    Display(delay);
    break;
    case 6:
        int mad,mdata;
    F1.gotoxy(86,31);
    cout<<"ENTER MEMERY ADDRESS THEN DATA"<<endl;
    F1.gotoxy(86,33);
    cin>>mad;
    F1.gotoxy(86,35);
    cin>>mdata;
    (M[mad])=mdata;
    break;
    case 7:
    F1.gotoxy(5,60);
    exit(0);
}
} while(1);
  getch();
    return (0);
}
