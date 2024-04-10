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

const int MAXN = 333333;

vector<int> V[MAXN], adj[MAXN];
int vis[MAXN], col[MAXN];

void dfs(int u, int p) {
	for (int i = 0; i < sz(V[u]); i++) vis[col[V[u][i]]] = 1;
	int cur = 1;
	for (int i = 0; i < sz(V[u]); i++) {
		int x = V[u][i];
		if (col[x]) continue;
		while (vis[cur]) cur++;
		col[x] = cur, vis[cur] = 1;
	}
	for (int i = 0; i < sz(V[u]); i++) vis[col[V[u][i]]] = 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int c; scanf("%d", &c); V[i].resize(c);
		for (int j = 0; j < c; j++) scanf("%d", &V[i][j]);
		ans = max(ans, sz(V[i]));
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", ans);
	for (int i = 1; i <= m; i++) printf("%d ", max(1, col[i]));
	return 0;
}