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
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    ll ans = 0;
    ll lx = INF, rx = -INF;
    ll lc = INF, rc = INF;
    ll longest = INF, len = 0;
    for(int i=1;i<=n;++i) {
        int l, r, c;
        cin >> l >> r >> c;
        if(r - l + 1 == len) {
            amin(longest, c);
        }
        else if(r - l + 1 > len) {
            longest = c;
            len = r - l + 1;
        }
        if(r > rx) {
            rc = c;
            rx = r;
        }
        else if(r == rx) {
            amin(rc, c);
        }
        if(l < lx) {
            lc = c;
            lx = l;
        }
        else if(l == lx) {
            amin(lc, c);
        }
        ll ans = lc + rc;
        if(rx - lx + 1 == len) {
            amin(ans, longest);
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}