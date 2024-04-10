#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = b; i >= a; --i)
#define all(x) x.begin(), x.end()
 
using ll = long long;
using namespace std;

const int N = 1 << 20;

int n, dep[N];
vector<int> g[N], lvl[N];
ll a[N], dp[N];

void dfs(int v, int p = 0) {
	dep[v] = dep[p] + 1;
	lvl[dep[v]].pb(v);
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
}

void solve() {
	scanf("%d", &n);
	rep(i, 1, n) g[i].clear(), lvl[i].clear();
	rep(i, 2, n) {
		int x;
		scanf("%d", &x);
		g[i].pb(x);
		g[x].pb(i);
	}
	rep(i, 2, n) scanf("%lld", a + i);
	dfs(1);
	int mx = *max_element(dep + 1, dep + n + 1);
	for (auto x : lvl[mx]) dp[x] = 0;
	per(i, 1, mx - 1) {
		ll x = -1e18, y = -1e18;
		ll x0 = 1e18, y0 = -1e18;
		for (auto z : lvl[i + 1]) {
			x = max(x, dp[z] - a[z]);
			y = max(y, dp[z] + a[z]);
			x0 = min(x0, a[z]);
			y0 = max(y0, a[z]);
		}
		for (auto z : lvl[i]) {
			dp[z] = 0;
			for (auto u : g[z]) {
				if (dep[u] == dep[z] + 1) {
					dp[z] = max(dp[z], dp[u] + a[u] - x0);
					dp[z] = max(dp[z], dp[u] + y0 - a[u]);
					dp[z] = max(dp[z], a[u] + x);
					dp[z] = max(dp[z], y - a[u]);
				}
			}
		}
	}
	printf("%lld\n", dp[1]);
}
	

int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}