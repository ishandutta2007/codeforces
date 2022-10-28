// Har Har Mahadev
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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> h(n+1);
    for(int i=1;i<=n;++i) {
        cin >> h[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<ll> dp(n+1, 0);
    function<void(int, int)> dfs = [&](int s, int p) {
        dp[s] = h[s];
        for(auto &j:g[s]) {
            if(j != p) {
                dfs(j, s);
                amax(dp[s], dp[j]);
            }
        }
    };
    dfs(1, 0);
    ll ans = 0;
    function<void(int, int, int)> dfs2 = [&](int s, int p, int u) {
        vector<ll> tmp;
        for(auto &j:g[s]) {
            if(j != p) {
                tmp.push_back(dp[j]);
            }
        }
        int n = sz(tmp);
        vector<int> pref(n+1, 0), suf(n + 2, 0);
        for(int i=1;i<=n;++i) {
            pref[i] = pref[i-1];
            amax(pref[i], tmp[i - 1]);
        }
        for(int i=n;i>=1;--i) {
            suf[i] = suf[i + 1];
            amax(suf[i], tmp[i - 1]);
        }
        int cur = 1;
        for(auto &j:g[s]) {
            if(j != p) {
                dfs2(j, s, max({h[s], pref[cur - 1], suf[cur + 1], u}));
                ++cur;
            }
        }
        tmp.push_back(u);
        tmp.push_back(0);
        sort(all(tmp), greater<ll>());
        ans += max(h[s] - tmp[0], 0ll);
        ans += max(h[s] - tmp[1], 0ll);
    };
    dfs2(1, 0, 0);
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