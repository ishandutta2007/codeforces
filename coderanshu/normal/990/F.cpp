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
    int n;
    cin>>n;
    vector<int> s(n+1);
    vector<int> pos,neg;
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        s[i] = -s[i];
        if(s[i] > 0)
            pos.push_back(i);
        else if(s[i] < 0)
            neg.push_back(i);
    }
    ll sum = accumulate(all(s),0ll);
    if(sum != 0)
    {
        cout<<"Impossible\n";
        return 0;
    }
    int m;
    cin>>m;
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
        g[y].push_back({x,-i});
    }
    vector<int> ans(m+1,0);
    vector<vector<int>> par(n+1,vector<int>(20));
    vector<ll> up(n+1,0),down(n+1,0);
    vector<int> dep(n+1,0),vis(n+1,0);
    function<void(int,int)> dfs = [&](int s,int p)
    {
        vis[s] = 1;
        par[s][0] = p;
        for(int i=1;i<20;++i)
            par[s][i] = par[par[s][i-1]][i-1];

        for(auto &[j,k]:g[s])
        {
            if(!vis[j])
                dep[j] = dep[s] + 1,dfs(j,s);
        }
    };
    dfs(1,0);
    auto lca = [&](int x,int y)
    {
        if(dep[x] > dep[y])
            swap(x,y);
        int d = dep[y] - dep[x];
        for(int i=0;i<20;++i)
            if(d&(1<<i))
                y = par[y][i];
        if(x == y)
            return x;
        for(int i=19;i>=0;--i)
        {
            if(par[x][i] != par[y][i])
                x = par[x][i],y = par[y][i];
        }
        return par[x][0];
    };
    while(!pos.empty() && !neg.empty())
    {
        int u = pos.back(),v = neg.back();
        int l = lca(u,v);
        int push = min(s[u],-s[v]);
        up[u] += push;
        up[l] -= push;
        down[l] -= push;
        down[v] += push;
        if(push == s[u] && push == -s[v])
            pos.pop_back(),neg.pop_back();
        else if(push == s[u])
            pos.pop_back(),s[v] += push;
        else
            neg.pop_back(),s[u] -= push;
    }
    vis.assign(n+1,false);
    function<void(int,int)> dfs2 = [&](int s,int edge)
    {
        vis[s] = 1;
        for(auto &[j,k]:g[s])
        {
            if(vis[j])
                continue;
            dfs2(j,k);
            up[s] += up[j];
            down[s] += down[j];
        }
        if(edge > 0)
            ans[edge] -= up[s],ans[edge] += down[s];
        else
            ans[-edge] += up[s],ans[-edge] -= down[s];
    };
    dfs2(1,0);
    cout<<"Possible\n";
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