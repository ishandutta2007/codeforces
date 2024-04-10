#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int a[MAXN];
int d[MAXN];
vector<int> g[MAXN];
int dp[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int,vector<int> > m;
    map<int,vector<int> > m2;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        m[a[i]].push_back(i);
        m2[-a[i]].push_back(i);
    }

    for(int i=0;i<n;i++)
    {
        if(i<n-1)
            g[i].push_back(i+1);
        d[i]=-1;
    }
    for(auto y : m2)
    {
        for(auto p : y.s)
        {
            if(p<n-1 && a[p+1]>a[p])
            {
                int sz=-d[find(p+1)];
                if(p+sz<n-1)
                    g[p].push_back(p+sz+1);
            }
            if(p && a[p-1]>a[p])
            {
                int sz=-d[find(p-1)];
                if(p-sz>0)
                    g[p-sz-1].push_back(p);
            }
        }

        for(auto p : y.s)
        {
            if(p<n-1 && a[p+1]>a[p])
                join(p,p+1);
            if(p && a[p-1]>=a[p])
                join(p,p-1);
        }
    }

    for(int i=0;i<n;i++)
        d[i]=-1;
    for(auto y : m)
    {
        for(auto p : y.s)
        {
            if(p<n-1 && a[p+1]<a[p])
            {
                int sz=-d[find(p+1)];
                if(p+sz<n-1)
                    g[p].push_back(p+sz+1);
            }
            if(p && a[p-1]<a[p])
            {
                int sz=-d[find(p-1)];
                if(p-sz>0)
                    g[p-sz-1].push_back(p);
            }
        }

        for(auto p : y.s)
        {
            if(p<n-1 && a[p+1]<a[p])
                join(p,p+1);
            if(p && a[p-1]<=a[p])
                join(p,p-1);
        }
    }

    for(int i=0;i<n;i++)
        dp[i]=oo;
    dp[0]=0;
    for(int i=0;i<n-1;i++)
        for(auto v : g[i])
            dp[v]=min(dp[v],dp[i]+1);

    db(dp[n-1])

    return 0;
}