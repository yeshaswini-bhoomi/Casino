#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;
void rules()
{
    system("cls");
    cout<<"\t\t\t\t      CASINO NUMBER GUESSING RULES\n";
    cout<<"\t1. Choose a number between 1 to 10\n";
    cout<<"\t2. Winner gets 10 times of the money bet\n";
    cout<<"\t3. Wrong bet, and you lose the amount you bet\n\n";
}
int main()
{
    string Name;
    int bal,bettingamt,guess,dice;
    char choice;
    srand(time(0));
    cout<<"\n\t\t\t\t\tWELCOME TO CASINO WORLD\n\n";
    rules();
    cout<<"\n\nEnter your name: ";
    getline(cin,Name);
    cout<<"\n\nEnter the starting balance to play the game: $";
    cin>>bal;
    do
    {
        cout<<"\n\nYour current balance is $ "<<bal<<"\n\n\n";
        do
        {
            cout<<"Hey, "<<Name<<" , enter the amount to bet: $";
            cin>>bettingamt;
            if(bettingamt>bal)
            {
                cout<<"Betting balance can't be more than current balance!\n"<<"\n"<<"Re-enter balance\n\n";
            }
        }while(bettingamt>bal);
        do
        {
            cout<<"Guess a number between 1-10: ";
            cin>>guess;
            if(guess<=0||guess>10)
            {
                cout<<"\nNumber should be between 1-10\n"<<"Re-enter number: \n";
            }
        }while(guess<=0 || guess>10);
        dice=rand()%10+1;
        if(dice==guess)
        {
            cout<<"\n\nYou are in luck!! $"<<bettingamt*10;
        }
        else
        {
            cout<<"Oops, better luck next time!! You lost $"<<bettingamt<<"\n";
            bal-=bettingamt;
        }
        cout<<"\nThe winning number was: "<<dice<<"\n";
        cout<<"\n"<<Name<<" ,you have balance of $"<<bal<<"\n";
        if(bal==0)
        {
            cout<<"You have no money left to play ";
            break;
        }
        cout<<"\n\n\t\t\tDo you want to play again (Y/N)?\n";
        cin>>choice;
    }while(choice =='Y'|| choice=='y');
    cout<<"\n";
    cout<<"Thanks for playing the game. Your balance is $"<<bal<<"\n\n";
    return 0;
}