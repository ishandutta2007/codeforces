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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int _runtimeTerror_()
{
	int n;
	cin >> n;
    vector<string> p(n);
    for(int i=0;i<n;++i) {
    	cin >> p[i];
    }
    int m = p[0].size();
    int ans = 0;
    string a;
    for(int j=0;j<m;++j) {
    	vector<int> cnt(26,0);
    	for(int i=0;i<n;++i) {
    		if(p[i][j] != '?') {
    			++cnt[p[i][j]-'a'];	
    		}
    	}
    	char c = rng() % 26 + 'a';
    	int distinct = 0;
    	for(int i=0;i<26;++i) {
    		distinct += cnt[i] > 0;
    		if(cnt[i] > 0) {
    			c = i + 'a';
    		}
    	}
    	if(distinct >= 2) {
    		c = '?';
    	}
    	a += c;
    	ans += distinct >= 2;
    }
    cout << a << "\n";
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