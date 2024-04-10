#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

inline ll sum(ll x)
{
    if(x==0)
    {
        return 0LL;
    }
    else
    {
        ll cntp=x/2;
        ll cnti=x-cntp;
        return cntp*(cntp+1)-cnti*cnti;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        ll st;
        ll dr;
        cin>>st>>dr;
        cout<<sum(dr)-sum(st-1)<<"\n";
    }
    return 0;
}
/**

**/