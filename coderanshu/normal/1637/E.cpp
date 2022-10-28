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
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    auto b = a;
    sort(all(b));
    vector<int> mp(n + 2, 0), freq(n + 2, 0), rev(n + 2, 0);
    for(int i=0;i<n;++i) {
        int t = a[i];
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
        rev[a[i]] = t;
        assert(a[i] <= n and a[i] >= 1);
    }
    debug(a);
    vector<vector<int>> g(n+1), c(n+1);
    for(int i:a) {
        ++mp[i];
        ++freq[i];
    }
    for(int i=1;i<=n;++i) {
        if(mp[i] > 0) {
            c[mp[i]].push_back(i);
        }
        mp[i] = 0;
    }
    vector<int> t;
    for(int i=1;i<=n;++i) {
        sort(all(c[i]), greater<int>());
        if(sz(c[i]) > 0) {
            t.push_back(i);
        }
    }
    for(int i=1;i<=m;++i) {
        int x, y;
        cin >> x >> y;
        x = lower_bound(all(b), x) - b.begin() + 1, y = lower_bound(all(b), y) - b.begin() + 1;
        g[x].push_back(y), g[y].push_back(x);
    }

    ll ans = 0;
    vector<bool> vis(n+1, 0);
    for(int i=0;i<n;++i) {
        if(vis[a[i]]) {
            continue;
        }
        // debug(a[i]);
        vis[a[i]] = 1;
        for(auto &k:g[a[i]]) {
            mp[k] = 1;
        }
        mp[a[i]] = 1;
        for(auto &j:t) {
            for(auto &k:c[j]) {
                if(mp[k]) {
                    continue;
                }
                // debug(a[i], k);
                amax(ans, (freq[a[i]] + freq[k]) * 1ll * (rev[a[i]] + rev[k]));
                break;
            }
        }

        for(auto &k:g[a[i]]) {
            mp[k] = 0;
        }
        mp[a[i]] = 0;
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
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}