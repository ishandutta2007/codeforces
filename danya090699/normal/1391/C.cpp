#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1;
    cin>>n;
    for(int a=1; a<=n; a++) an=1ll*a*an%mod;
    int st=1;
    for(int a=0; a<n-1; a++) st=2*st%mod;
    an-=st;
    if(an<0) an+=mod;
    cout<<an;
}