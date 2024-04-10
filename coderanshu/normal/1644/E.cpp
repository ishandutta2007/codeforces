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


int _runtimeTerror_()
{
    int n;
    cin >> n;
    ll ans = 0;
    string s;
    cin >> s;
    int x = 1, y = 1;
    for(auto j:s) {
    	x += j == 'D';
    	y += j == 'R';
    }
    x = n - x + 1, y = n - y + 1;
    int xx = 1, yy = 1;
    bool fx = 0, fy = 0;
    ++ans;
    for(int i=0;i<sz(s);++i) {
		if(s[i] == 'D') {
			if(fx == 0) {
				xx = x;
				ans += xx * 1ll * yy;
				fx = 1;
			}
			else {
				ans += yy;
			}
		}
		else {
			if(fy == 0) {
				yy = y;
				ans += xx * 1ll * yy;
				fy = 1;
			}
			else {
				ans += xx;
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}