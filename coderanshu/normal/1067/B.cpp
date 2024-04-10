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
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n+1);
    vector<int> deg(n+1,0);
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
        ++deg[x],++deg[y];
    }
    for(int i=1;i<=n;++i)
    {
        if(deg[i] == 1 || deg[i] >= 3)
            continue;
        cout<<"No\n";return 0;
    }
    vector<int> par(n+1,0),dep(n+1,0);
    function<void(int,int)> dfs = [&](int s,int p)
    {
        par[s] = p;
        for(auto &j:g[s])
            if(j!=p)
                dep[j] = dep[s] + 1,dfs(j,s);
    };
    dfs(1,0);
    int root = 1;
    for(int i=1;i<=n;++i)
        if(dep[root] < dep[i])
            root = i;
    dep[root] = 0;
    dfs(root,0);
    int down = 1;
    for(int i=1;i<=n;++i)
        if(dep[i] > dep[down])
            down = i;
    int center = down;
    int up = dep[down]/2;
    while(up--)
        center = par[center];
    auto check = [&](int ver)
    {
        vector<int> q;
        q.push_back(ver);
        vector<bool> vis(n+1,false);
        vis[ver] = true;
        for(int i=1;i<=k;++i)
        {
            vector<int> tmp;
            for(auto &j:q)
            {
                int cnt = 0;
                for(auto &l:g[j])
                {
                    if(vis[l])
                        continue;
                    vis[l] = true;
                    tmp.push_back(l);
                    ++cnt;
                }
                // debug(tmp);
                if(cnt < 3)
                {
                    cout<<"No\n";exit(0);
                }
            }
            q = tmp;
        }
        for(auto &j:q)
        {
            if(deg[j] != 1)
            {
                cout<<"No\n";exit(0);
            }
        }
        cout<<"Yes\n";
        exit(0);
    };
    check(center);
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