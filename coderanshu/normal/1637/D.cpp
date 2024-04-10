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

const int N = 105;

ll dp[N][N * N];

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
    }
    for(int i=1;i<=n;++i) {
        cin >> b[i];
    }
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=n*100;++j) {
            dp[i][j] = INF;
        }
    }
    ll sum = a[1] + b[1];
    dp[1][a[1]] = dp[1][b[1]] = 0;
    for(int i=2;i<=n;++i) {
        for(int j=1;j<=n*100;++j) {
            if(j + a[i] <= n * 100) {
                amin(dp[i][j+a[i]], dp[i-1][j] + a[i] * j + b[i] * (sum - j));
            }
            if(j + b[i] <= n * 100) {
                amin(dp[i][j+b[i]], dp[i-1][j] + a[i] * (sum - j) + b[i] * j);
            }
        }
        sum += a[i] + b[i];
    }
    ll ans = INF;
    for(int i=1;i<=n*100;++i) {
        amin(ans, dp[n][i]);
    }
    ans *= 2;
    debug(ans);
    for(int i=1;i<=n;++i) {
        for(int j=i+1;j<=n;++j) {
            ans += a[i] * a[i] + a[j] * a[j] + b[i] * b[i] + b[j] * b[j];
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
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}