#include<iostream>
using namespace std;
main(){
    long long n,m,s,an;
    cin>>n>>m>>s;
    an=((n-1)%s+1)*((m-1)%s+1)*((n+s-1)/s)*((m+s-1)/s);
    cout<<an<<endl;
}