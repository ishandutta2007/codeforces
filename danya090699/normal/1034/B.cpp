#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    if(n>m) swap(n, m);
    if(n==1)
    {
        int q=m/6, os=m%6;
        if(os<4) cout<<q*6;
        else if(os==4) cout<<q*6+2;
        else if(os==5) cout<<q*6+4;
    }
    else if(n==2)
    {
        if(m<3) cout<<0;
        else if(m==3) cout<<4;
        else if(m==7) cout<<12;
        else cout<<((n*m)/2)*2;
    }
    else cout<<((n*m)/2)*2;
}