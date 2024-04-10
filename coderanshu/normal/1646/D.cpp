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
    vector<vector<int>> g(n+1);
    vector<int> deg(n + 1, 0);
    for(int i=1;i<=n-1;++i) {
    	int x, y;
    	cin >> x >> y;
    	++deg[x], ++deg[y];
    	g[x].push_back(y), g[y].push_back(x);
    }
    if(n == 2) {
    	cout << "2 2\n1 1\n";
    	return 0;
    }
    vector<vector<pll>> dp(n + 1, vector<pll>(2, {0, 0}));
    vector<int> par(n + 1);
    function<void(int, int)> dfs = [&](int s, int p) {
    	ll x = 1, y = -deg[s], x2 = 0, y2 = -1;
    	for(auto &j:g[s]) {
    		if(j == p) {
    			continue;
    		}
    		dfs(j, s);
    		x += dp[j][0].F;
    		y += dp[j][0].S;
    		if(dp[j][0].F > dp[j][1].F) {
    			x2 += dp[j][0].F;
    			y2 += dp[j][0].S;
    			par[j] = 0;
    		}
    		else if(dp[j][0].F < dp[j][1].F) {
    			x2 += dp[j][1].F;
    			y2 += dp[j][1].S;
    			par[j] = 1;
    		}
    		else if(dp[j][0].S > dp[j][1].S) {
    			x2 += dp[j][0].F;
    			y2 += dp[j][0].S;
    			par[j] = 0;
    		}
    		else {
    			x2 += dp[j][1].F;
    			y2 += dp[j][1].S;
    			par[j] = 1;
    		}
    	}
    	dp[s][1] = {x, y};
    	dp[s][0] = {x2, y2};
    };
    dfs(1, 0);
    vector<ll> ans(n+1);

    function<void(int,int,int)> dfs2 = [&](int s, int p, int pt) {
    	if(pt == 1) {
    		ans[s] = deg[s];
    		for(auto &j:g[s]) {
    			if(j != p) {
    				dfs2(j, s, 0);
    			}
    		}
    	}
    	else {
    		ans[s] = 1;
    		for(auto &j:g[s]) {
    			if(j != p) {
    				dfs2(j, s, par[j]);
    			}
    		}
    	}
    };
    if(dp[1][0].F > dp[1][1].F) {
    	cout << dp[1][0].F << " " << -dp[1][0].S << "\n";
    	dfs2(1, 0, 0);
    }
    else if(dp[1][0].F < dp[1][1].F) {
    	cout << dp[1][1].F << " " << -dp[1][1].S << "\n";
    	dfs2(1, 0, 1);
    }
    else if(dp[1][0].S > dp[1][1].S) {
    	cout << dp[1][0].F << " " << -dp[1][0].S << "\n";
    	dfs2(1, 0, 0);	
    }
    else {
    	cout << dp[1][1].F << " " << -dp[1][1].S << "\n";
    	dfs2(1, 0, 1);
    }
    for(int i=1;i<=n;++i) {
    	cout << ans[i] << " ";
    }
    cout << "\n";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}