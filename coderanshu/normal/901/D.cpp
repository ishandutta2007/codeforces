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
    vector<int> par_edge(n+1),par(n+1),dep(n+1),vis(n+1),c(n+1);   
    vector<vector<pii>> g(n+1);

    vector<ll> ans(m+1,0);

    for(int i=1;i<=n;++i)
        cin>>c[i];
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
        g[y].push_back({x,i});
    }

    vector<array<int,3>> back;
    vector<ll> cnt(2,0);

    function<void(int,int)> dfs = [&](int s,int p)
    {
        vis[s] = true;
        par[s] = p;
        cnt[dep[s] & 1] += c[s];
        for(auto &[j,k]:g[s])
        {
            if(!vis[j])
            {
                dep[j] = dep[s] + 1;
                par_edge[j] = k;
                dfs(j,s);
            }
            else if(j != p)
                back.push_back({j,s,k});
        }
    };
    dfs(1,0);

    // debug(cnt);

    for(auto &[u,v,id]:back)
    {
        if((dep[u] & 1) == (dep[v] & 1))
        {
            if(dep[u] & 1)
                ans[id] = (cnt[1] - cnt[0])/2,c[u] -= (cnt[1] - cnt[0])/2, c[v] -= (cnt[1] - cnt[0])/2;
            else
                ans[id] = (cnt[0] - cnt[1])/2,c[u] -= (cnt[0] - cnt[1])/2, c[v] -= (cnt[0] - cnt[1])/2;
            cnt[0] = cnt[1];
            break;
        }
    }
    if(cnt[0] != cnt[1])
    {
        cout<<"NO\n";return 0;
    }

    vis.assign(n+1,false);
    function<int(int,int)> dfs2 = [&](int s,int p)
    {
        vis[s] = true;
        ll sum = 0;
        for(auto &[j,k]:g[s])
        {
            if(!vis[j])
                sum += dfs2(j,s);
        }
        ans[par_edge[s]] = c[s] - sum;
        return ans[par_edge[s]];
    };

    assert(dfs2(1,0) == 0);

    cout<<"YES\n";
    for(int i=1;i<=m;++i)
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