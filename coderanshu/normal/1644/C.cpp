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
    int n, x;
    cin >> n >> x;
    vector<ll> a(n+1);
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    }
    vector<ll> b(n + 1, -INF), c(n + 2, -INF);
    for(int i=1;i<=n;++i) {
    	ll sum = 0;
    	for(int j=i;j<=n;++j) {
    		sum += a[j];
    		amax(b[j - i + 1], sum + x * 1ll * (j - i + 1));
    		amax(c[j - i + 1], sum);
    	}
    }
    // debug(b);
    vector<ll> ans(n + 1, 0);
    for(int i=1;i<=n;++i) {
    	amax(b[i], b[i - 1]);
    	amax(ans[i], b[i]);
    }
    for(int i=n;i>=0;--i) {
    	amax(c[i], c[i + 1]);
    	amax(ans[i], c[i] + i * 1ll * x);
    }
    for(auto i:ans) {
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