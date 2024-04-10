#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin>>n;
   if(n>=0)
   cout<<n;
   else
   {
       n*=-1;
       n=(n/100)*10+min(n%10,(n/10)%10);
       n*=-1;
       cout<<n;
   }
    return 0; 
}