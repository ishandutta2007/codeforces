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

const int N = 200005;

vector<int> g[N];
int dep[N];
ll dp[N], sub[N];
ll cnt[2];
int n;

void dfs(int s,int p) {
	++cnt[dep[s] & 1];
	sub[s] = 1;
	for(auto &j:g[s]) {
		if(j == p) {
			continue;
		}
		dep[j] = dep[s] + 1;
		dfs(j, s);
		dp[s] += dp[j] + sub[j];
		sub[s] += sub[j];
	}
}

ll ans = 0;

void dfs2(int s,int p) {
	ans += (dp[s] + cnt[1 - (dep[s] & 1)])/2;
	for(auto &j:g[s]) {
		if(j != p) {
			dp[j] += (dp[s] - sub[j] - dp[j]) + n - sub[j];
			dfs2(j, s);
		}
	}
}

int _runtimeTerror_()
{
    cin >> n;
    for(int i=1;i<=n-1;++i) {
    	int x, y;
    	cin >> x >> y;
    	g[x].push_back(y), g[y].push_back(x);
    }
    dfs(1, 0);
    dfs2(1, 0);
    cout << ans / 2 << "\n";
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