//  228

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    bool c=true;
    int temp=0;
    int n=2;
    int x;
    int y;
    cin>>x;
    cin>>y;
    for(int i=2;i<x;i++)
    {
        if(x%i==0)
        {
            cout<<"NO";
            return 0;
        }
    }
     for(int i=x;i<y;i++)
    {
        if(y%i==0)
        {
            cout<<"NO";
            return 0;
        }
    }
      temp=x+1;
     while(c)
     {
      c=false;

         for(n=2;n<temp;n++)
         {
           if(temp%n==0)
           {
               c=true;
           }
         }
         temp++;

     }
     if(y==temp-1)
     {
         cout<<"YES";
     }
     else
     {
         cout<<"NO";
     }




}