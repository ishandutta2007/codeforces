//  228

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   int arr[6];
   for(int i=0;i<6;i++) arr[i]=0;
   int m , a, b,i;
   cin>>m;
   for(i=0;i<m;i++)
   {
    cin>>a>>b;
    arr[a]++;
    arr[b]++;
   }
   int ans1=0,ans0=0;
   for(i=1;i<=5;i++)
   {
    if(arr[i]>=3) ans1++;
    else if(arr[i]<=1) ans0++;
   }
   if(ans1>0 || ans0>0)
   {
    cout<<"WIN";
   }
   else cout<<"FAIL";
}