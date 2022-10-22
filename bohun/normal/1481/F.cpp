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

const int N = 1 << 17;

int n, x, y, p, mx, cnt[N], h[N], dp[N], qq[N], ans[N];
vector<int> lvl[N], who[N], g[N];

void dfs(int v, int p = 0) {
	h[v] = h[p] + 1;
	mx = max(mx, h[v]);
	lvl[h[v]].pb(v);
	for (auto u : g[v])
		if (u != p)
			dfs(u, v);
}

int main() {
	scanf("%d%d", &n, &x);
	rep(i, 2, n) {
		scanf("%d", &p);
		g[p].pb(i);
	}
	dfs(1);
	rep(i, 1, mx)
		who[sz(lvl[i])].pb(i);
	memset(dp, -1, sizeof dp);
	dp[0] = 0;
	rep(i, 1, n) {
		if (sz(who[i]) == 0) continue;
		rep(j, 0, n) {
			if (dp[j] >= 0) qq[j] = 0;
			else qq[j] = (j - i >= 0 ? qq[j - i] + 1 : 1e9);
			if (qq[j] > 0 && qq[j] <= sz(who[i]))
				dp[j] = who[i][qq[j] - 1];
		}
	}
	if (dp[x] != -1) {
		while (x > 0) {
			for (auto a : lvl[dp[x]])
				ans[a] = 1;
			x -= sz(lvl[dp[x]]);
		}
		printf("%d\n", mx);
		rep(i, 1, n) printf(ans[i] ? "a" : "b");
		return 0;
	}
	y = n - x;
	rep(i, 1, mx) {
		if (sz(lvl[i]) <= max(x, y)) {
			for (auto a : lvl[i]) 
				ans[a] = (x > y ? 1 : 0);
			if (x > y) x -= sz(lvl[i]);
			else y -= sz(lvl[i]);
			continue;
		}
		sort(all(lvl[i]), [&](int p, int q) {
			return sz(g[p]) > sz(g[q]);
		});
		int z = max(x, y);
		int w = (x > y);
		rep(j, 0, z - 1)
			ans[lvl[i][j]] = w ? 1 : 0;
		if (w) x = 0;
		else y = 0;
		rep(j, z, sz(lvl[i]) - 1)
			ans[lvl[i][j]] = w ? 0 : 1;		
	}
	printf("%d\n", mx + 1);
	rep(i, 1, n) printf(ans[i] ? "a" : "b");
	return 0;
}