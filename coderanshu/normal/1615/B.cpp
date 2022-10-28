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

const int N = 2e5 + 5;

int cnt[N][20];

int _runtimeTerror_()
{
    int l, r;
    cin >> l >> r;
    int mx = 0;
    for(int i=0;i<20;++i) {
        amax(mx, cnt[r][i] - cnt[l-1][i]);
    }
    cout << (r - l + 1 - mx) << "\n";
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
    for(int i=1;i<=2e5;++i) {
        for(int j=0;j<20;++j) {
            cnt[i][j] = cnt[i-1][j];
            if(i & (1 << j)) {
                ++cnt[i][j];
            }
        }
    }
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}