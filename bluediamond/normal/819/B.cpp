#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=(ll)1e6+7;

ll n;
ll v[2*N];

unordered_map<ll,ll>f;

ll gt(ll p,ll i)
{
    return v[i]-(p-1);
}

ll res=(1LL<<60),id;

void calc()
{
    ll cnt=0;
    ll tot=0;
    for(ll i=1;i<=n;i++)
    {
        if(gt(1,i)>0)
        {
            cnt++;
            tot+=gt(1,i);
        }
        f[v[i]]++;
    }
    for(ll st=1;st<=n+1;st++)
    {
        ll dr=st+n-1;
        if(st>1)
        {
            if(gt(st,dr)>0)
            {
                tot+=gt(st,dr);
            }
            cnt-=f[st-1];
        }
        ll alpha=0;
        for(ll j=st;j<=dr;j++)
        {
            if(gt(st,j)>0)
            {
                alpha+=gt(st,j);
            }
        }
        alpha++;
        ll now=2*tot;
        res=min(res,now);
        if(res==now)
        {
            id=st-1;
        }
        tot-=cnt;
        /// delete st
        f[v[st]]--;
        if(gt(st,st)>0)
        {
            tot-=gt(st,st);
            cnt--;
        }
        /// add dr+1
        f[v[dr+1]]++;
        if(gt(st,dr+1)>0)
        {
            cnt++;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++)
    {
        cin>>v[i];
        v[i+n]=v[i];
    }
    for(ll i=1;i<=2*n;i++)
    {
        v[i]=i-v[i];
    }
    calc();
    id%=n;
    id=n-id;
    id%=n;
    cout<<res<<" "<<id<<"\n";
    return 0;
}