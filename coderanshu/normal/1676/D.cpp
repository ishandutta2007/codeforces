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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0;i<n;++i) {
    	for(int j=0;j<m;++j) {
    		cin >> a[i][j];
    	}
    }
    ll ans = 0;
    for(int i=0;i<n;++i) {
    	for(int j=0;j<m;++j) {
    		ll val = 0;
    		for(int k=-max(n, m);k<=max(n, m);++k) {
    			int x = i + k;
    			if(x >= 0 and x < n and j + k >= 0 and j + k < m) {
    				val += a[i + k][j + k];
    			}
    			if(k == 0) {
    				continue;
    			}
    			if(x >= 0 and x < n and j - k >= 0 and j - k < m) {
    				val += a[i + k][j - k];
    			}
    		}
    		amax(ans, val);
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