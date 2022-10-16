#include <iostream>
using namespace std;
int n,k,x,B,i;
int M(int P){return (P%n==0)?n:(P%n);}
int A(int P){cout<<"? "<<P<<endl,cin>>x;return x;} 
int main(){cin>>n>>k;B=(n>700)?320:1;for (i=1;i<=B;i++)A(1);for (i=1;A(i)==k;i=M(i+B));while(A(i)<k)i=M(i+1+(n>5));while(A(i)!=k||A(i)!=k)i=M(i-1);cout<<"! "<<i;}