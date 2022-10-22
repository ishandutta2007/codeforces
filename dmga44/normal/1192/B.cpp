#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
typedef pair<pii,ll> ppi;
typedef pair<pii,pii> ppp;
typedef pair<ld,ll> pli;
typedef pair<pii,string> pps;
typedef pair<char,ll> pci;
typedef complex<double> point;
typedef vector<point> polygon;
#define pi (acos(-1))
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define MAXN 200005
#define oo (ll(1ll<<62))
#define x 450

vector<ppi> g[MAXN];
ll t[MAXN],lims[MAXN][2],sz[MAXN],mk[MAXN],a[MAXN],bucket[x][5],ma[x][2],lazy[x],res,n;
vector<ll> euler;

void dfs(ll u,ll d)
{
    mk[u]=1;
    lims[u][0]=euler.size();
    a[euler.size()]=d;
    euler.push_back(u);
    for(auto y : g[u])
    {
        ll id=y.second;
        ll w=y.first.second;
        ll v=y.first.first;
        if(!mk[v])
        {
            t[id]=v;
            dfs(v,d+w);
            a[euler.size()]=d;
            euler.push_back(u);
        }
    }
    lims[u][1]=euler.size();
}

void recalc(ll b,ll l,ll r)
{
    bucket[b][0]=oo;
    bucket[b][1]=-oo;
    bucket[b][2]=-oo;
    bucket[b][3]=-oo;
    bucket[b][4]=0;

    vector<ll> aux;
    for(ll i=l;i<=r;i++)
    {
        a[i]+=lazy[b];
        bucket[b][4]=max(bucket[b][4],a[i]);
        bucket[b][0]=min(bucket[b][0],a[i]);
        bucket[b][1]=max(bucket[b][1],bucket[b][4]-2*a[i]);
        aux.push_back(bucket[b][1]);
    }

    bucket[b][4]=0;
    for(ll i=r;i>=l;i--)
    {
        bucket[b][4]=max(bucket[b][4],a[i]);
        bucket[b][2]=max(bucket[b][2],bucket[b][4]-2ll*a[i]);
        bucket[b][3]=max(bucket[b][3],aux[i-l]+bucket[b][4]);
    }
    lazy[b]=0;
}

ll marcelo()
{
    res=0;
    for(ll i=0;i<(n+x);i+=x)
        ma[i/x][0]=ma[i/x][1]=0;

    for(ll i=0;i<n;i+=x)
    {
        ma[i/x][0]=max(ma[i/x][0],bucket[i/x][4]+lazy[i/x]);
        ma[(i/x)+1][0]=ma[i/x][0];
    }

    for(ll i=n-1;i>=0;i-=x)
    {
        ma[i/x][1]=max(ma[i/x][1],bucket[i/x][4]+lazy[i/x]);
        if(i>=x)
            ma[(i/x)-1][1]=ma[i/x][1];
    }

    for(ll i=0;i<=((n-1)/x);i++)
    {
        ll ml=0,mr=0;
        if(i)
            ml=ma[i-1][0];
        if(i<((n-1)/x))
            mr=ma[i+1][1];
        res=max(res,ml+mr-2ll*(bucket[i][0]+lazy[i]));
        res=max(res,mr+bucket[i][1]-lazy[i]);
        res=max(res,ml+bucket[i][2]-lazy[i]);
        res=max(res,bucket[i][3]);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll q,wt,u,v,w;
    cin >> n >> q >> wt;
    for(ll i=0;i<n-1;i++)
    {
        cin >> u >> v >> w;
        sz[i]=w;
        u--,v--;
        g[u].push_back(ppi(pii(v,w),i));
        g[v].push_back(ppi(pii(u,w),i));
    }

    dfs(0,0);

    ll nn=n;
    n=euler.size();
    for(ll i=0;i<n;i+=x)
    {
        if(i/x!=(n-1)/x)
            recalc(i/x,i,i+x-1);
        else
            recalc(i/x,i,n-1);
    }

    ll last=0;
    while(q--)
    {
        ll e,d;
        cin >> d >> e;
        d=(d+last)%(nn-1);
        e=(e+last)%wt;

        ll mul=e-sz[d];
        sz[d]=e;
        ll l=lims[t[d]][0],r=lims[t[d]][1]-1;
        if(l/x==r/x)
        {
            for(ll i=l;i<=r;i++)
                a[i]+=mul;
            recalc(l/x,(l/x)*x,min(((l/x)*x)+x-1,n-1));
        }
        else
        {
            for(ll i=(l/x)+1;i<(r/x);i++)
                lazy[i]+=mul;

            for(ll i=l;i/x==l/x;i++)
                a[i]+=mul;
            recalc(l/x,(l/x)*x,min(((l/x)*x)+x-1,n-1));

            for(ll i=r;i/x==r/x;i--)
                a[i]+=mul;
            recalc(r/x,(r/x)*x,min(((r/x)*x)+x-1,n-1));
        }
        last=marcelo();
        db(last)
    }

    return 0;
}