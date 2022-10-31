#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

int dp[2][211111];
VI adj[211111];

void dfs(int u, int p) {
	int chd = 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		chd++;
	}
	if (chd == 0) {
		dp[0][u] = 1, dp[1][u] = 0;
		return;
	}
	int sum0 = 0, d1 = 1e9, d2 = 1e9;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		sum0 += dp[0][v];
		if (dp[1][v] - dp[0][v] < d1) d2 = d1, d1 = dp[1][v] - dp[0][v];
		else if (dp[1][v] - dp[0][v] < d2) d2 = dp[1][v] - dp[0][v];
	}
	dp[1][u] = min(sum0, sum0 + d1);
	dp[0][u] = min(sum0 + d1 + d2 + 1, dp[1][u] + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n;
	long long x, y; cin >> n >> x >> y;
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	if (x >= y) {
		for (int i = 1; i <= n; i++) if (adj[i].size() == n-1) {
			cout << y * (n - 2) + x << endl;
			return 0;
		}
		cout << y * (n - 1) << endl;
		return 0;
	}
	dfs(1, 0);
	cout << x * (n - 1) + (y - x) * (dp[0][1] - 1) << endl;
	return 0;
}