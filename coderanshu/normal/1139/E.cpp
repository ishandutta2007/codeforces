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

bool dfs(int u,vector<vector<int>> &g,vector<int> &match,vector<bool> &vis)
{
    if(vis[u])
        return 0;
    vis[u] = 1;
    for(auto j:g[u])
    {
        if(match[j] == -1 || dfs(match[j],g,match,vis))
        {
            match[j] = u;
            return true;
        }
    }
    return 0;
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<int> left(n+1,0),p(n+1),c(n+1);
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=n;++i)
        cin>>c[i];
    int D;
    cin>>D;
    vector<int> q(D+1),ans(D+1);
    for(int i=1;i<=D;++i)
    {
        cin>>q[i];
        left[q[i]] = 1;
    }
    vector<bool> vis(n+1,false);
    vector<vector<int>> g(n+1);
    vector<int> match(m+1,-1);
    for(int i=1;i<=n;++i)
        if(!left[i] && p[i] <= n)
            g[p[i]].push_back(c[i]);
    int mex = 0;
    while(dfs(mex,g,match,vis))
        ++mex,vis.assign(n+1,false);
    vis.assign(n+1,false);
    ans[D] = mex;
    for(int i=D;i>=2;--i)
    {
        if(p[q[i]] <= n)
            g[p[q[i]]].push_back(c[q[i]]);
        while(dfs(mex,g,match,vis))
            ++mex,vis.assign(n+1,false);;
        vis.assign(n+1,false);
        ans[i-1] = mex;
    }
    for(int i=1;i<=D;++i)
        cout<<ans[i]<<"\n";
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