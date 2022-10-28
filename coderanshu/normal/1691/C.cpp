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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = count(all(s), '1');
    if(cnt == 0 or cnt == n) {
    	k = 0;
    }
    auto get = [&](string s) {
    	int ans = (s[0] - '0') * 10 + (s.back() - '0');
    	for(int i=1;i<n-1;++i) {
    		ans += 11 * (s[i] - '0');
    	}
    	return ans;
    };
    if(k == 0) {
    	cout << get(s) << "\n";
    	return 0;
    }
    if(sz(s) == 2) {
		sort(all(s));
		cout << get(s) << "\n";
		return 0;
	}
    int r = -1, l = -1;
    for(int i=0;i<n;++i) {
    	if(s[i] == '1') {
    		r = i;
    	}
    }
    for(int i=n-1;i>=0;--i) {
    	if(s[i] == '1') {
    		l = i;
    	}
    }
    r = n - 1 - r;
    int ans = cnt * 11;
    if(cnt == 1) {
    	if(r <= k) {
    		cout << ans - 10 << "\n";
    	}
    	else if(l <= k) {
    		cout << ans - 1 << "\n";
    	}
    	else {
    		cout << ans << "\n";
    	}
    }
    else {
    	if(l + r <= k) {
    		cout << ans - 11 << "\n";
    	}
    	else if(r <= k) {
    		cout << ans - 10 << "\n";
    	}
    	else if(l <= k) {
    		cout << ans - 1 << "\n";
    	}
    	else {
    		cout << ans << "\n";
    	}
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
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}