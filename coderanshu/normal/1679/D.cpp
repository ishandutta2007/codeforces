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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for(int i=1;i<=m;++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    auto search = [&](int x) {
        vector<int> dp(n + 1, 0), vis(n + 1, 0);
        int got = 0;

        function<void(int)> dfs = [&](int s) {
            vis[s] = 2;
            dp[s] = 1;
            for(auto &j:g[s]) {
                if(a[j] > x) {
                    continue;
                }
                if(!vis[j]) {
                    dfs(j);
                    amax(dp[s], dp[j] + 1);
                }
                else if(vis[j] == 2) {
                    got = 1;
                }
                else {
                    amax(dp[s], dp[j] + 1);
                }
            }
            vis[s] = 1;
        };

        for(int i=1;i<=n;++i) {
            if(a[i] <= x) {
                dfs(i);
            }
        }
        int mx = 0;
        for(int i=1;i<=n;++i) {
            amax(mx, dp[i]);
        }
        return got || mx >= k;
    };
    int lo = 1, hi = 1e9, ans = -1;
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        if(search(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initncr();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}