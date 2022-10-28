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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
        g[y].push_back({x,i});
    }
    vector<bool> vis(n+1,false);
    vector<int> dp(n+1,0),dep(n+1),par_edge(n+1),par(n+1);
    vector<array<int,3>> back;
    function<void(int,int,int)> dfs = [&](int s,int p,int edge)
    {
        // debug(s);
        par[s] = p;
        par_edge[s] = edge; 
        vis[s] = true;
        for(auto &[j,k]:g[s])
        {
            if(!vis[j])
            {
                dep[j] = dep[s] + 1;
                dfs(j,s,k);
                dp[s] += dp[j];
            }
            else if(dep[j] < dep[s] && j != p)
                ++dp[s],--dp[j],back.push_back({s,j,k});
        }
    };
    for(int i=1;i<=n;++i)
        if(!vis[i])
            dfs(i,i,0);
    vis.assign(n+1,false);
    function<void(int)> dfs2 = [&](int s)
    {
        vis[s] = true;
        for(auto &[j,k]:g[s])
        {
            if(!vis[j])
            {
                if(dp[j] == 1)
                    dp[j] = dp[s];
                else
                    dp[j] = dep[j];
                dfs2(j);
            }
        }
    };
    for(int i=1;i<=n;++i)
        if(!vis[i])
            dfs2(i);

    vector<int> ans;

    for(auto &[v,u,w]:back)
    {
        // debug(u,v,w,dp[v]);
        if(dp[v] <= dep[u])
        {
            ans.push_back(w);
            while(v != u)
            {
                // debug(v);
                ans.push_back(par_edge[v]),v = par[v];
            }
        }
    }
    sort(all(ans));
    cout<<sz(ans)<<"\n";
    for(auto &j:ans)
        cout<<j<<" ";
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}