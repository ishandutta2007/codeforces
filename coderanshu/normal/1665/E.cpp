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

map<int, vector<int>> mp[31], l[31], r[31];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<31;++i) {
        mp[i].clear();
        l[i].clear();
        r[i].clear();
    }
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        ll cur = 0;
        for(int j=30;j>=0;--j) {
            cur |= (1 << j);
            mp[j][a[i] & cur].push_back(i);
        }
    }
    // debug(mp[3][0]);
    for(int t=1;t<31;++t) {
        for(auto &[j, v]:mp[t]) {
            int n = v.size();
            int prv = (1 << 30);
            int k = j | (1 << (t - 1));
            int mn = (1 << 30);
            for(int i=0;i<n;++i) {
                if((a[v[i]] & k) == j) {
                    mn = (1 << 30);
                    prv = a[v[i]];
                }
                else {
                    amin(mn, prv | a[v[i]]);   
                }
                l[t][j].push_back(mn);
            }
            mn = prv = (1 << 30);
            for(int i=n-1;i>=0;--i) {
                if((a[v[i]] & k) == j) {
                    mn = (1 << 30);
                    prv = a[v[i]];
                }
                else {
                    amin(mn, prv | a[v[i]]);
                }
                // if(t == 3 && j == 0 && i == 0) {
                    // debug(prv, mn);
                // }
                r[t][j].push_back(mn);
            }
            reverse(all(r[t][j]));
            // if(t == 3 && j == 0) {
                // debug(v, l[t][j], r[t][j]);
            // }
        }
    }

    auto get = [&](int i, int x, int l, int r) {
        if(!mp[i].count(x)) {
            return 0;
        }
        return int(upper_bound(all(mp[i][x]), r) - lower_bound(all(mp[i][x]), l));
    };

    int Q;
    cin >> Q;
    for(int t=1;t<=Q;++t) {
        int lx, rx;
        cin >> lx >> rx;
        int cur = 0;
        int ans = (1 << 30), bit = 29, el = -1;
        for(int i=29;i>=0;--i) {
            bit = i + 1;
            // counting in off bits
            int u = get(i, cur, lx, rx);
            if(u == 0 || u == rx - lx + 1) {
                if(u == 0) {
                    cur |= (1 << i);
                }
                continue;
            }
            if(u == 1) {
                el = *lower_bound(all(mp[i][cur]), lx);
                int it = upper_bound(all(mp[bit][cur]), rx) - mp[bit][cur].begin() - 1;
                amin(ans, l[bit][cur][it]);
                it = lower_bound(all(mp[bit][cur]), lx) - mp[bit][cur].begin();
                amin(ans, r[bit][cur][it]);
                cur |= (1 << i);
            }
        }
        if(mp[0].count(cur) && mp[0][cur].size() >= 2) {
            amin(ans, cur);
        }
        cout << ans << "\n";
    }

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