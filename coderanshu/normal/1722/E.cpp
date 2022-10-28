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
    int n, Q;
    cin >> n >> Q;
    vector<vector<ll>> a(1001, vector<ll>(1001, 0));
    while(n--) {
        int x, y;
        cin >> x >> y;
        a[x][y] += y;
    }
    for(int i=1;i<=1000;++i) {
        for(int j=1;j<=1000;++j) {
            a[i][j] += a[i][j - 1];
        }
    }
    while(Q--) {
        ll ans = 0;
        int hs, hb, ws, wb;
        cin >> hs >> ws >> hb >> wb;
        for(int i=hs+1;i<hb;++i) {
            ans += i * (a[i][wb - 1] - a[i][ws]);
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