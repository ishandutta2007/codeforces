#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
   ios_base::sync_with_stdio(0);
   int a[26],M;
   long int sum=0;
   int i=25,k;
   string s;
   cin>>s>>k>>a[0];
   M=a[0];
   for(i=1;i<26;i++)
   {
       cin>>a[i];
       M=max(M,a[i]);
   }
   int t=s.length();
   for(i=0;i<t;i++)
   {
       sum+=a[s[i]-97]*(i+1);
   }
   cout<<sum+M*((t+k)*(t+k+1)/2-t*(t+1)/2);
   
   
    return 0;
}