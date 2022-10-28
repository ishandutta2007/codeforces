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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> a(n);
    for(int i=0;i<n;++i) {
    	cin >> a[i];
    	--a[i];
    }	
    auto f = [&](int id) {
    	vector<int> blocked(n,0);
    	for(int i=0;i<id;++i) {
    		blocked[a[i]] = 1;
    	}
    	int cur = 0;
    	for(char c:t) {
    		while(cur < n && (s[cur] != c || blocked[cur])) {
    			++cur;
    		}
    		if(cur == n) {
    			return false;
    		}
    		++cur;
    	}
    	return true;
    };

    int lo = 0, hi = n, ans = -1;
    while(lo <= hi) {
    	int mid = (lo + hi)/2;
    	if(f(mid)) {
    		ans = mid;
    		lo = mid + 1;
    	}
    	else {
    		hi = mid - 1;
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