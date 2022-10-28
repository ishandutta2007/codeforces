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
    string s;
    cin >> s;
    int ans = true;
    for(int i=0;i<6;++i) {
    	if(s[i] == 'r') {
    		int x = false;
    		for(int j=i+1;j<6;++j) {
    			x |= s[j] == 'R';
    		}
    		ans &= x;
    	}
    	if(s[i] == 'g') {
    		int x = false;
    		for(int j=i+1;j<6;++j) {
    			x |= s[j] == 'G';
    		}
    		ans &= x;
    	}
    	if(s[i] == 'b') {
    		int x = false;
    		for(int j=i+1;j<6;++j) {
    			x |= s[j] == 'B';
    		}
    		ans &= x;
    	}
    }
    cout << (ans ? "YES": "NO") << "\n";
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