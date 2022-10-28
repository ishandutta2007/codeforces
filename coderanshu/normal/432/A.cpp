#include<bits/stdc++.h>
using namespace std;
int main()
{
 
   int n,k,input,count=0;
   cin>>n>>k;
   for(int i=0;i<n;i++)
   {
       cin>>input;
       if(input<=5-k)
       {
           count++;
       }
   }
    cout<<count/3;
    return 0; 
}