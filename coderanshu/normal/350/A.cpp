#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m,Maxi,mini,mini2,i,x;
   cin>>n>>m;
   for(i=0;i<n;i++)
   {
       cin>>x;
       if(i==0)
       {
           Maxi=x;mini=x;
       }
       else
       {
       Maxi=max(Maxi,x);
       mini=min(mini,x);
       }
   }
   for(i=0;i<m;i++)
   {
       cin>>x;
       if(i==0)
       {
            mini2=x;
       }
       else mini2=min(mini2,x);
   }
   Maxi=max(Maxi,2*mini);
   if(Maxi>=mini2)
   {
       cout<<-1;
   }
   else
   cout<<Maxi;
    return 0;
}