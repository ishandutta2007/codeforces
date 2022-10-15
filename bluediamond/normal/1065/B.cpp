#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline bool ok(ll m,ll g)
{
    ll x=g*(g-1)/2;
    return (x>=m);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<max(0LL,n-m*2)<<" ";
    ll r=-1,pas=(1<<16);
    while(pas)
    {
        if(r+pas<=n && ok(m,r+pas)==0)
            r+=pas;
        pas/=2;
    }r++;
    cout<<n-r<<"\n";
    return 0;
}
/**
**/