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
#define debug(...) 3000
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for(int i=2;i<=n;++i) {
    	int p;
    	cin >> p;
    	g[p].push_back(i);
    }
    string a;
    cin >> a;
    vector<int> sub(n + 1, 0);
    function<void(int)> dfs = [&](int s) {
    	sub[s] = a[s - 1] == 'B' ? -1 : 1;
    	for(auto &j:g[s]) {
    		dfs(j);
    		sub[s] += sub[j];
    	}
    };
    dfs(1);
    int ans = 0;
    debug(sub);
    for(int i=1;i<=n;++i) {
    	ans += sub[i] == 0;
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