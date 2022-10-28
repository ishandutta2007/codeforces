#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005;

vector<int> v[N];
bool pvt[N];
int par[N], dep[N],dp[N],inpath[N],mxdep[N];
bool yo[N];

int L;

void dfs1(int s,int p)
{
    par[s] = p;
    dp[s] = dep[s];
    for(auto &j:v[s])
        if(j!=p)
            dep[j] = dep[s] + 1,dfs1(j,s), amax(dp[s],dp[j]);
}

void dfs2(int s,int p,int val)
{
    multiset<int> deps;
    vector<int> t;
    for(auto j:v[s])
    {
        if(j!=p)
        {   
            deps.insert(dp[j]);
            t.pb(dp[j]-dep[s]);
        }
    }
    t.pb(val);
    sort(all(t));
    if(sz(t)>=3)
    {
        if(t[sz(t)-3]>=L-1)
            pvt[s] = true;
    }
    for(auto j:v[s])
    {
        if(j!=p)
        {
            deps.erase(deps.find(dp[j]));
            int fx = val+1;
            if(!deps.empty())
                amax(fx,*deps.rbegin()-dep[s]+1);
            dfs2(j,s,fx);
            deps.insert(dp[j]);
        }
    }
}

void dfs3(int s,int p,int h,int r)
{
    amax(mxdep[r],h);
    yo[r] |= pvt[s];
    for(auto j:v[s])
    {
        if(j!=p && !inpath[j])
            dfs3(j,s,h+1,r);
    }
}

int _runtimeTerror_()
{
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;++i)
    {
        pvt[i] = false,par[i] = 0,dep[i] = 0,dp[i] = 0;
        inpath[i] = 0;
        mxdep[i] = 0;
        yo[i] = 0;
        v[i].clear();
    }
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dep[a] = 0;
    dfs1(a,0);
    L = dep[b] + 1;
    dfs2(a,0,0);
    vector<int> path;
    int u = b;
    while(u!=a)
        path.pb(u),u = par[u];
    path.pb(a);
    for(auto &j:path)
        inpath[j] = 1;
    for(auto &j:path)
        dfs3(j,0,0,j);
    int l = 0,r = L-1;
    int lft = 0,rgt = 0;
    while(l<r)
    {
        int pl = l,pr = r;
        amax(lft,mxdep[path[l]]-l);
        amax(rgt,mxdep[path[r]]-(L-1-r));
        amin(r,L-1-lft);
        amax(l,rgt);
        if(pl == l && pr == r)
            break;
        while(pl<=l && pl<L)
            amax(lft,mxdep[path[pl]]-pl),++pl;
        while(pr>=r && pr>=0)
            amax(rgt,mxdep[path[pr]]-(L-1-pr)),--pr;
    }
    bool ans = false;
    for(int i=0;i<=min(L-1,l);++i)
        ans |= yo[path[i]];
    for(int i=L-1;i>=max(0,r);--i)
        ans |= yo[path[i]];
    cout<<(ans?"YES":"NO")<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}