#include<bits/stdc++.h>
using namespace std;

int main()
{
   long int y,k,n,x,i;
   cin>>y>>k>>n;
   x=k-y%k;
   if(x+y>n)
   {
       cout<<-1;
       return 0;
   }
   while(y+x<=n)
   {
       cout<<x<<" ";
       x+=k;
   }
    return 0;
}