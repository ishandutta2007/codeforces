#include<iostream>
using namespace std;
int main()
{
int n,x,y,z;
static int a,b,c;

cin>>n;
while(n--)
{
cin>>x>>y>>z;
a+=x;
b+=y;
c+=z;

}

if(a==0 && b==0 && c==0)
cout<<"YES"<<endl;
else
cout<<"NO"<<endl;

//cin>>a;
return 0;
}