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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    ll mn_val = 0;
    auto solve = [&](vector<array<int, 3>> &a) {
        int n = sz(a);
        vector<vector<ll>> dp(n+1, vector<ll>(205, INF));
        vector<int> ans;
        ll mn = INF;

        dp[0][0] = 0;
        for(int i=1;i<=n;++i) {
            for(int j=0;j<=200;++j) {
                dp[i][j] = dp[i-1][j];
                if(j >= a[i-1][1]) {
                    amin(dp[i][j], dp[i-1][j - a[i-1][1]] + a[i-1][0]);
                }
            }
        }
        int val = 100;
        for(int i=100;i<=200;++i) {
            if(dp[n][i] < mn) {
                mn = dp[n][i];
                val = i;
            }
        }
        for(int i=n;i>=1;--i) {
            ll x = dp[i][val];
            // can use
            if(val >= a[i-1][1] && dp[i-1][val - a[i-1][1]] + a[i-1][0] == x) {
                ans.push_back(a[i-1][2]);
                val -= a[i-1][1];
            }
            else {
                assert(dp[i-1][val] == x);
            }
        }
        // assert(val == 0);
        mn_val = mn;
        return ans;
    };
    vector<vector<array<int, 3>>> g(n+1);
    for(int i=1;i<=m;++i) {
        int e, t, p;
        cin >> e >> t >> p;
        g[e].push_back({t, p, i});
    }
    int prev = 0;
    vector<int> ans;
    for(int i=1;i<=n;++i) {
        auto u = solve(g[i]);
        if(mn_val <= a[i] - prev) {
            ans.insert(ans.end(), all(u));
        }
        else {
            cout << "-1\n";
            return 0;
        }
        prev += mn_val;
    }
    cout << sz(ans) << "\n";
    for(int i:ans) {
        cout << i << " ";
    }
    cout << "\n";
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
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}