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
    vector<vector<int>> g(n+1);
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    ll sum = 0;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        a[i] -= x;
        sum += a[i];
    }
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y),g[y].push_back(x);
    }
    if(sum % 2 != 0)
    {
        cout<<"NO\n";return 0;
    }
    vector<ll> cnt(2,0);
    auto bfs = [&]()
    {
        vector<bool> vis(n+1,false);
        vector<int> dep(n+1,-1);
        dep[1] = 0;
        vector<int> q{1};
        vis[1] = true;
        for(int i=0;i<sz(q);++i)
        {
            int u = q[i];
            cnt[dep[u]] += a[u];
            for(auto &j:g[u])
            {
                if(!vis[j])
                {
                    vis[j] = true;
                    dep[j] = dep[u] ^ 1;
                    q.push_back(j);
                }
                else if(vis[j] && dep[j] == dep[u])
                    return false;
            }
        }
        return true;
    };
    if(bfs())
    {
        // debug("Yo\n");
        if(cnt[0] == cnt[1])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else
        cout<<"YES\n";
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