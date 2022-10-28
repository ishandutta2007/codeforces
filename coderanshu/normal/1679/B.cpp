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
    vector<ll> a(n + 1);
    ll ans = 0;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        ans += a[i];
    }
    int sq = -1, last = -1;
    vector<int> b(n + 1, 0);
    for(int i=1;i<=Q;++i) {
        int tt, id, x;
        cin >> tt;
        if(tt == 1) {
            cin >> id >> x;
            if(b[id] < sq) {
                ans += x - last;
            }
            else {
                ans += x - a[id];
            }
            a[id] = x;
            b[id] = i;
        }
        else {
            cin >> x;
            sq = i;
            ans = n * 1ll * x;
            last = x;
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}