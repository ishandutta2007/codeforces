#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=(ll)1e6+7;

ll n;
ll v[N];
ll id[N];

bool cmp(ll a,ll b)
{
        return v[a]<v[b];
}

ll lb(ll i)
{
        return i&(-i);
}

ll aib[2][N];

void add(ll t,ll p,ll val)
{
        for(ll i=p;i<=n;i+=lb(i))
        {
                aib[t][i]+=val;
        }
}

ll prefix(ll t,ll p)
{
        ll res=0;
        for(ll i=p;i>=1;i-=lb(i))
        {
                res+=aib[t][i];
        }
        return res;
}

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
                cin>>v[i];
                id[i]=i;
        }
        sort(id+1,id+n+1,cmp);
        for(ll i=1;i<=n;i++)
        {
                v[id[i]]=n+1-i;
        }
        ll res=0LL;
        for(ll i=1;i<=n;i++)
        {
                res+=prefix(1,v[i]);
                add(1,v[i],prefix(0,v[i]));
                add(0,v[i],1);
        }
        cout<<res<<"\n";
        return 0;
}
/**

**/