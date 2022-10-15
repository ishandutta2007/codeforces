#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000+5;
const int LG=40;

int n;
ll v[N];

int cnt=1,nxt[LG*N][2];

inline void add(ll x)
{
    int poz=1;
    for(int bit=LG-1;bit>=0;bit--)
    {
        int bb=0;
        if(x&(1LL<<bit))
            bb=1;
        if(!nxt[poz][bb])
            nxt[poz][bb]=++cnt;
        poz=nxt[poz][bb];
    }
}

inline ll gt(ll x)
{
    ll ans=0;
    int poz=1;
    for(int bit=LG-1;bit>=0;bit--)
    {
        int bb=0;
        if(x&(1LL<<bit))
            bb=1;
        if(nxt[poz][1-bb])
        {
            ans+=(1LL<<bit);
            poz=nxt[poz][1-bb];
            continue;
        }
        if(nxt[poz][bb]==0)
            return ans;
        poz=nxt[poz][bb];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    ll prefix=0,sufix=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        prefix^=v[i];
    }
    ll ans=0;
    for(int last=n;last>=0;last--)
    {
        add(sufix);
        ans=max(ans,gt(prefix));
        sufix^=v[last];
        prefix^=v[last];
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/