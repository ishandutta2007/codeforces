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
    int n, k;
    cin >> n >> k;
    vector<vector<char>> ans(n, vector<char>(n, 'G'));
    vector<vector<int>> a(n, vector<int>(n, 0));
    vector<array<int, 3>> vals;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cin >> a[i][j];
            vals.push_back({-a[i][j], i, j});
        }
    }
    sort(all(vals));
    vector<int> mn(4, 1e9);

    for(auto [u, x, y]:vals) {
        ll mx = -1e9;
        vector<ll> sums;
        for(int i=0;i<4;++i) {
            ll sum = 0;
            sum += (i & 1 ? 1: -1) * x;
            sum += (i & 2 ? 1: -1) * y;
            amax(mx, sum - mn[i]);
            sums.push_back(sum);
        }
        if(mx <= k) {
            ans[x][y] = 'M';
            for(int i=0;i<4;++i) {
                amin(mn[i], sums[i]);
            }
        }
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout << ans[i][j];
        }
        cout << "\n";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}