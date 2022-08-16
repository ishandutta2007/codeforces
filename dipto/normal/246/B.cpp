#include<iostream>
using namespace std;

int main()
{
int n,t,s=0;
cin>>n;

for(int i=0;i<n;i++)
{cin>>t;
s+=t;}

int ans=(s%n)?(n-1):n;
cout<<ans;


return 0;
}