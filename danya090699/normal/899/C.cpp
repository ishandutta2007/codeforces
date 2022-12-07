#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n%4==0) cout<<"0\n"<<n/2;
    if(n%4==1) cout<<"1\n"<<n/2;
    if(n%4==2) cout<<"1\n"<<n/2<<" "<<1;
    if(n%4==3) cout<<"0\n"<<n/2<<" "<<3;
    for(int a=n%4+1; a<(n+n%4+1-a); a+=2) cout<<" "<<a<<" "<<n+n%4+1-a;
}