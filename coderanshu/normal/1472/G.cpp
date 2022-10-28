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

const int N = 200005;

vector<int> v[N];
vector<int> g[N];

int dep[N];
bool vis[N];
int dp[N];

void dfs(int s)
{
    vis[s] = true;
    dp[s] = dep[s];
    for(auto j:v[s])
    {
        amin(dp[s],dep[j]);
    }
    for(auto j:g[s])
    {
        if(!vis[j])
            dfs(j);
        amin(dp[s],dp[j]);
    }
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        vis[i] = false;
        v[i].clear();
        g[i].clear();
        dep[i] = 1e9;
        dp[i] = 1e9;
    }
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    dep[1] = 0;
    vector<int> q;
    q.pb(1);
    vis[1] = true;
    for(int i=0;i<sz(q);++i)
    {
        int u = q[i];
        for(auto &j:v[u])
        {
            if(!vis[j])
            {
                vis[j] = true;
                dep[j] = dep[u]+1;
                q.pb(j);
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(auto &j:v[i])
        {
            if(dep[j]>dep[i])
                g[i].pb(j);
        }
    }
    for(int i=1;i<=n;++i)
    {
        vis[i] = false;
    }
    vector<int> ans(n+1,1e8);
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
            dfs(i);
    }
    for(int i=1;i<=n;++i)
        cout<<dp[i]<<" ";
    cout<<"\n";
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