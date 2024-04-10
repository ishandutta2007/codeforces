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
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;++i) {
    	cin >> a[i];
    }
    if(n == 1) {
    	cout << abs(a[0]) << "\n";
    	return 0;
    }
    auto check = [&](ll x) {
    	auto b = a;
    	for(auto &i:b) {
    		i += x;
    	}
    	if(b[0] < 0) {
    		return false;
    	}
    	ll mn = b[0], prev = 0;
    	for(int i=1;i<n-1;++i) {
    		if(b[i] - mn >= prev) {
    			prev = b[i] - mn;
    		}
    		else {
    			mn = b[i] - prev;
    		}
    		if(mn < 0) {
    			return false;
    		}
    	}
    	if(b.back() < prev) {
    		return false;
    	}
    	return true;
    };
    ll lo = -1e15, hi = 1e15, ans = INF;
    while(lo <= hi) {
    	ll mid = (lo + hi) / 2;
    	if(check(mid)) {
    		hi = mid - 1;
    		amin(ans, abs(mid) + a[0] + a.back() + 2 * mid);
    	}
    	else {
    		lo = mid + 1;
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