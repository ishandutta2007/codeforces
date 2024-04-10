#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=(ll)1e5+7;

ll n;
ll v[N];

struct info
{
        ll i;
        ll dif;
};

bool cmp(info a,info b)
{
        return a.dif<b.dif;
}

info a[N];

struct question
{
        ll i;
        ll x;
};

bool cmp2(question a,question b)
{
        return a.x<b.x;
}

ll cntq;
question q[N];

ll t[N];
ll st[N];
ll dr[N];
ll res[N];
ll total=0LL;

ll get(ll a)
{
        if(a==t[a])
        {
                return a;
        }
        else
        {
                return t[a]=get(t[a]);
        }
}

ll comp=0;

void unite(ll a,ll b)
{
        a=get(a);
        b=get(b);
        if(a==b) return;
        total-=res[a];
        total-=res[b];
        t[a]=b;
        st[b]=min(st[a],st[b]);
        dr[b]=max(dr[a],dr[b]);
        comp--;
        res[b]=(dr[b]-st[b]+1);
        total+=res[b];
}

ll sol[N];

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(ll i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        sort(v+1,v+n+1);
        for(ll i=1;i<=n;i++)
        {
                comp++;
                res[i]=1;
                st[i]=dr[i]=v[i];
                total+=res[i];
                t[i]=i;
        }
        for(ll i=1;i<n;i++)
        {
                a[i].i=i;
                a[i].dif=v[i+1]-v[i];
        }
        sort(a+1,a+n,cmp);
        cin>>cntq;
        for(ll i=1;i<=cntq;i++)
        {
                q[i].i=i;
                ll a,b;
                cin>>a>>b;
                q[i].x=b-a;
        }
        sort(q+1,q+cntq+1,cmp2);
        ll p=1;
        for(ll i=1;i<=cntq;i++)
        {
                while(p<n && a[p].dif<=q[i].x)
                {
                        unite(a[p].i,a[p].i+1);
                        p++;
                }
                sol[q[i].i]=total+(comp)*(q[i].x);
        }
        for(ll i=1;i<=cntq;i++)
        {
                cout<<sol[i]<<" ";
        }
        cout<<"\n";
        return 0;
}
/**

**/