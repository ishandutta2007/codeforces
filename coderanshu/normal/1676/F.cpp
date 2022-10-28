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

    int len = -1, l = -1;
    map<int, int> mp;
    for(int i=1;i<=n;++i) {
    	int x;
    	cin >> x;
    	++mp[x];
    }
    vector<int> a;
    for(auto &[i, j]:mp) {
    	if(j >= k) {
    		a.push_back(i);
    	}
    }
    debug(a);
    if(sz(a)) {
    	int last = a.back();
    	len = 1, l = a.back();
    	for(int i=sz(a)-2;i>=0;--i) {
    		if(a[i] + 1 == a[i + 1]) {
    			if(last - a[i] + 1 > len) {
    				len = last - a[i] + 1;
    				l = a[i];
    			}
    		}
    		else {
    			last = a[i];
    		}
    		debug(len, last);
    	}
    }
    if(l == -1) {
    	cout << l << "\n";
    }
    else {
    	cout << l << " " << l + len - 1 << "\n";
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