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
    int n, m, x;
    cin >> n >> m;
    vector<ll> a(n+1), b(m+1);
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    }
    for(int j=1;j<=m;++j) {
    	cin >> b[j];
    }
    cin >> x;
    vector<ll> A(n+1,INF), B(m+1,INF);
    for(int i=1;i<=n;++i) {
    	ll sum = 0;
    	for(int j=i;j<=n;++j) {
    		sum += a[j];
    		amin(A[j-i+1], sum);
    	}
    }
    for(int i=1;i<=m;++i) {
    	ll sum = 0;
    	for(int j=i;j<=m;++j) {
    		sum += b[j];
    		amin(B[j-i+1], sum);
    	}
    }
    ll ans = 0;
    for(int i=1;i<=n;++i) {
    	for(int j=1;j<=m;++j) {
    		if(A[i] * B[j] <= x) {
    			amax(ans, i * j);
    		}
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
        initialize();
    #endif
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}