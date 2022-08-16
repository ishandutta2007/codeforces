#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
if(n<=2) cout<<"-1";
else
{
cout<<"5 5 ";
for(int i=0;i<n-2;i++)
cout<<1<<' ';
}

return 0;
}