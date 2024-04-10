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
    int n, d;
    cin >> n >> d;
    vector<int> a(n + 1, 0);
    int mn = d + 1;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        amin(mn, a[i] - a[i-1] - 1);
    }
    int ans = mn;
    for(int i=1;i<=n;++i) {
        if(a[i] - a[i - 1] - 1 == mn) {
            // move i - 1
            if(i > 1) {
                int val = 1e9, mx = -1;
                for(int j=i+1;j<=n;++j) {
                    amin(val, a[j] - a[j - 1] - 1);
                    amax(mx, a[j] - a[j - 1] - 1);
                }
                for(int j=1;j<=i-2;++j) {
                    amin(val, a[j] - a[j - 1] - 1);
                    amax(mx, a[j] - a[j - 1] - 1);
                }
                amin(val, a[i] - a[i - 2] - 1);
                amax(mx, a[i] - a[i - 2] - 1);
                amax(ans, min(val, (mx - 1)/2));
                amax(ans, min(val, d - a.back() - 1));
            }
            // move i
            int val = 1e9, mx = -1;
            for(int j=i+2;j<=n;++j) {
                amin(val, a[j] - a[j - 1] - 1);
                amax(mx, a[j] - a[j - 1] - 1);
            }
            for(int j=1;j<=i-1;++j) {
                amin(val, a[j] - a[j - 1] - 1);
                amax(mx, a[j] - a[j - 1] - 1);
            }
            if(i != n) {
                amin(val, a[i + 1] - a[i - 1] - 1);
                amax(mx, a[i + 1] - a[i - 1] - 1);
                amax(ans, min(val, d - a.back() - 1));
            }
            else {
                // amax(ans, min(val, d - a.back() - 1));
                
                amax(ans, min(val, d - a[n-1] - 1));
            }
            amax(ans, min(val, (mx - 1)/2));
            
            break;
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