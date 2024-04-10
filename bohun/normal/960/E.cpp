#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl
	
using namespace std;

const int mod = 1e9 + 7;
const int nax = 2e5 + 111;

int n;
int val[nax];
int a, b;
vector <int> v[nax];
int h[nax];
int dp[nax][2];
int ans;
int siz[nax];


void dfs1(int u, int p) {
	h[u] = h[p] + 1;
	dp[u][h[u] % 2] += 1;
	siz[u] = 1;
	
	for(auto it : v[u]) {
		if(it == p)
			continue;
		dfs1(it, u);
		dp[u][0] += dp[it][0];
		dp[u][1] += dp[it][1];
		siz[u] += siz[it];
	}
}

void dfs2(int u, int p, int dp0 = 0, int dp1 = 0) {
	
	// poczatek to u
	ans += (ll) val[u] * n % mod;
	ans %= mod;
	// poczatek na dole
	for(auto it : v[u]) {
		if(it == p)
			continue;
		ans += (ll) val[u] * dp[it][h[u] % 2] % mod * (n - siz[it]) % mod;
		ans %= mod;
		ans -= (ll) val[u] * dp[it][!(h[u] % 2)] % mod * (n - siz[it]) % mod;
		ans %= mod;
		ans += mod;
		ans %= mod;
		
		int x = dp[u][!(h[u] % 2)] - dp[it][!(h[u] % 2)];
		int y = dp[u][h[u] % 2] - dp[it][h[u] % 2];
		
		dfs2(it, u, dp1 + x, dp0 + y);
		
	}
	
	// poczatek do gorze
	ans += (ll) val[u] * dp0 % mod * siz[u] % mod;
	ans %= mod;
	
	ans -= (ll) val[u] * dp1 % mod * siz[u] % mod;
	ans %= mod;
	ans += mod;
	ans %= mod;
	
}
		
		
	

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", val + i);
	}
	for(int i = 1; i < n; ++i) {
		scanf("%d %d", &a, &b);
		v[a].pb(b);
		v[b].pb(a);
	}
	
	dfs1(1, 0);
	
	dfs2(1, 0);
	
	printf("%d", ans);
	
	
	
	return 0;
}