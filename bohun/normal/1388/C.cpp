#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()

using namespace std;	

const int N = 1e5 + 10;

int n, m;
int p[N], h[N];
vector <int> G[N];
bool ok;
int dp[N];

int dfs(int v, int par) {
	int siz = p[v];
	int bil = 0;
	dp[v] = p[v];
	for (auto u : G[v]) {
		if (u == par) continue;
		siz += dfs(u, v);
		dp[v] += dp[u];
	}
	bil = -siz + 2 * (siz - dp[v]);
	int dif = h[v] - bil;
	if (!(0 <= dif && dif <= 2 * dp[v] && dif % 2 == 0)) {
		ok = false;
	}
	else {
		dp[v] -= dif / 2;
	}
	return siz;
}		
	

int main() {
	int T, n;
	scanf ("%d", &T);
	while (T--) {
		scanf ("%d%d", &n, &m);
		rep(i, 1, n) scanf ("%d", p + i);
		rep(i, 1, n) scanf ("%d", h + i);
		rep(i, 1, n) G[i].clear();
		rep(i, 1, n - 1) {
			int u, v;
			scanf ("%d%d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
		}
		ok = true;
		dfs(1, 0);
		printf (ok ? "YES\n" : "NO\n");
	}
	return 0;
}