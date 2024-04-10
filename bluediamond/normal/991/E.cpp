#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;
ll e[15];
ll ap[15],len;
ll fact[105];
ll ans=0;

void bkt(ll strat)
{
    if(strat==9)
    {
        ll add=fact[len];
        for(ll i=0;i<=9;i++)
        {
            if(e[i] && ap[i]==0)return;
            add/=fact[ap[i]];
        }
        if(ap[0])
        {
            ap[0]--;
            ll scad=fact[len-1];
            for(ll i=0;i<=9;i++)
            {
                scad/=fact[ap[i]];
            }
            add-=scad;
            ap[0]++;
        }
        ans+=add;
    }
    else
    {
        for(ll j=0;j<=e[strat+1];j++)
        {
            len+=j;
            ap[strat+1]=j;
            bkt(strat+1);
            len-=j;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=1;
    for(ll i=1;i<=100;i++)
        fact[i]=(ll)fact[i-1]*i;
    cin>>n;
    while(n)
    {
        e[n%10]++;
        n/=10;
    }
    bkt(-1);
    cout<<ans<<"\n";
    return 0;
}
/**



**/