#include <iostream>
#include <cstring>
#include <cstdlib>
#include <windows.h>
using namespace std;


 void SetColor(int value){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  value);    //for color output

 /*   1: Blue
2: Green
3: Cyan
4: Red
5: Purple
6: Yellow (Dark)
7: Default white
8: Gray/Grey
9: Bright blue
10: Brigth green
11: Bright cyan
12: Bright red
13: Pink/Magenta
14: Yellow
15: Bright white
-Numbers after 15 are background colors-

   */
}

void init();
void layout();
void scoreBoard();
void turn();
void getInput();
void logic(int);
void displayMessage();


int winner();
void reset();


int Turn=1;
 int input;
 char option[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
int Count[9]={0,0,0,0,0,0,0,0,0};
 int k=0;

int p1=0,p2=0;


int main(){
   loop2:


    system("cls");

      layout();

         SetColor(18);
    if( winner()==1){
        goto loop2;
    }

SetColor(7);

      turn();

      getInput();

      logic(Turn);
       reset();
       goto loop2;

return 0;

}


void layout()
{
   SetColor(4);
   scoreBoard();
   SetColor(14);

    cout<<"\t\t-----------------------------------------------------------------------"<<endl<<endl<<endl;
    cout<<" \t\t\t\t\t   "<<option[0]<<"  |  "<<option[1]<<"  |  "<<option[2]<<endl;
    cout<< "  \t\t\t\t\t -----|-----|-----    "<<endl;
     cout<<" \t\t\t\t\t   "<<option[3]<<"  |  "<<option[4]<<"  |  "<<option[5]<<endl;
    cout<< "  \t\t\t\t\t -----|-----|-----    "<<endl;
     cout<<" \t\t\t\t\t   "<<option[6]<<"  |  "<<option[7]<<"  |  "<<option[8]<<endl<<endl<<endl<<endl;



SetColor(7);
}
void scoreBoard()
{

    cout<<endl<<endl<<endl;

    cout<<"\t\t\t player1  : ";
      SetColor(7);
    cout<<"X";
    cout<<"\t\t\t\t player1 score: ";
    SetColor(2);
    cout<<p1<<endl;

    SetColor(1);

    cout<<"\t\t\t player2  : ";
    SetColor(7);
    cout<<"O";
     cout<<"\t\t\t\t player2 score: ";
     SetColor(5);
     cout<<p2<<endl;

}

void turn(){

cout<<"\tplayer "<<Turn<<" turn    :"<<endl<<endl;
if(Turn==1){
    Turn++;
}
else
    Turn--;

}

void getInput()
{

    loop:
        cout<<"\t\t";
        SetColor(4);
    cin>>input;
        SetColor(7);

       int a=(input-1);

    if(input>9){

        cout<<"wrong input"<<endl;
        cout<<"enter again"<<endl;
        goto loop;
    }

          Count[a]++;

    if(Count[a]>1){
            Count[a]--;

        cout<<"wrong input"<<endl;
        cout<<"already selected "<<endl;
        goto loop;
           }
}
 void logic(int T){
   int a=(input-1);
switch(T){

 case 1:
    option[a]='O';
   break;

case 2:
    option[a]='X';
     break;
default:
    cout<<"system error"<<endl;
}

}
int winner(){
if((option[0]=='O'&& option[1]=='O'&& option[2] =='O')||
   (option[3]=='O'&&option[4]=='O'&& option[5] =='O')||     //for rows
   (option[6]=='O'&& option[7]=='O'&& option[8] =='O')||

   (option[0]=='O' && option[4]=='O'&& option[8] =='O')||
   (option[2]=='O'&& option[4]=='O' && option[6] =='O')||   //for diagonal

   (option[0]=='O'&& option[3]=='O'&& option[6] =='O')||
   (option[1]=='O'&&option[4]=='O'&& option[7] =='O')||     //for columns
   (option[2]=='O'&& option[5]=='O'&& option[8] =='O')


   ){

    cout<<"player two is the winner "<<endl;

      SetColor(7);
     system("pause");
    init();
    p2++;
    return 1;


   }
   else if((option[0]=='X'&& option[1]=='X'&& option[2]=='X')||
           (option[3]=='X'&&option[4]=='X'&& option[5]=='X')||    //for rows
           (option[6]=='X'&& option[7]=='X' && option[8]=='X')||

           (option[0]=='X'&& option[4]=='X' && option[8] =='X')||
           (option[2]=='X'&& option[4]=='X'&& option[6] =='X') ||  //for diagonal

           (option[0]=='X'&& option[3]=='X'&& option[6]=='X')||
           (option[1]=='X'&&option[4]=='X'&& option[7]=='X')||    //for columns
           (option[2]=='X'&& option[5]=='X' && option[8]=='X')


           ){

    cout<<"player one is the winner "<<endl;

     SetColor(15);

    system("pause");
     p1++;
    displayMessage();
    return 1;

   }


}



void reset(){


int a;
k=0;

for(a=0;a<9;a++){


if(Count[a]==1)
{
  k++;

}
}

if(k==9){

   displayMessage();
}

}

void init(){
    int i;
    for (i=0;i<9;i++){
     option[i]=' ';
     Count[i]=0;
    }
    k=0;
}


void displayMessage(){
 char op;

cout<<" G  A  M  E    O V E R "<<endl;
    cout<<"do you want to play again"<<endl;
    cout<<" press 'y' for yes and 'n' for no"<<endl;
    cin>>op;
    switch(op){
case 'y':
     init();
    break;

case 'n':
    exit(1);
    }



}
