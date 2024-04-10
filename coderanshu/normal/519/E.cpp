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

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005,LOGN = 20;

vector<int> v[N];

int dep[N],par[N][LOGN];
int sub[N];

void dfs(int s,int p)
{
    par[s][0] = p;
    for(int i=1;i<LOGN;++i)
        par[s][i] = par[par[s][i-1]][i-1];

    sub[s] = 1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs(j,s);
            sub[s] += sub[j];
        }
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    int m;
    cin>>m;
    auto lca = [&](int u,int v)
    {
        int l = dep[u] - dep[v];
        for(int i=0;i<LOGN;++i)
            if(l&(1<<i))
                u = par[u][i];
        if(u==v)
            return u;
        for(int i=LOGN-1;i>=0;--i)
        {
            if(par[u][i] != par[v][i])
                u = par[u][i],v = par[v][i];
        }
        return par[u][0];
    };
    auto kth = [&](int x,int k)
    {
        for(int i=0;i<LOGN;++i)
            if(k&(1<<i))
                x = par[x][i];
        return x;
    };
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<n<<"\n";
            continue;
        }
        if(dep[x]<dep[y])
            swap(x,y);
        int u = lca(x,y);
        int pl = dep[x] + dep[y] - 2*dep[u];
        if(pl&1)
        {
            cout<<"0\n";continue;
        }
        pl >>= 1;
        if(dep[x] == dep[y])
        {
            int xx = kth(x,pl-1);
            int yy = kth(y,pl-1);
            cout<<n - sub[xx] - sub[yy]<<"\n";
        }
        else
        {
            int xx = kth(x,pl-1);
            int yy = kth(x,pl);
            cout<<sub[yy] - sub[xx]<<"\n";
        }
    }
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}