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

const int MAXN = 111111;
VI adj[MAXN];

#define y1 asdf

int x[MAXN], y[MAXN], par[MAXN], a[MAXN], x1[MAXN], y1[MAXN];

void dfs(int u, int p) {
	x[u] = y[u] = a[u], par[u] = p;
	x1[u] = 1e6, y1[u] = 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		dfs(v, u);
		x[u] = min(x[u], x[v]);
		y[u] = max(y[u], y[v]);
	}
}

void solve(int u, int p) {
	{
		int xx = min(x1[u], a[u]);
		int yy = max(y1[u], a[u]);
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (v == p) continue;
			x1[v] = min(x1[v], xx);
			y1[v] = max(y1[v], yy);
			xx = min(xx, x[v]);
			yy = max(yy, y[v]);
		}
	}
	{
		int xx = min(x1[u], a[u]);
		int yy = max(y1[u], a[u]);
		for (int i = sz(adj[u])-1; i >= 0; i--) {
			int v = adj[u][i];
			if (v == p) continue;
			x1[v] = min(x1[v], xx);
			y1[v] = max(y1[v], yy);
			xx = min(xx, x[v]);
			yy = max(yy, y[v]);
		}
	}
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		solve(v, u);
	}
}

int main() {
	int n; scanf("%d", &n);
	if (n <= 2) {
		puts("YES\n1");
		return 0;
	}
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1, 0);
	solve(1, 0);
	for (int i = 1; i <= n; i++) {
		bool flg = 1;
		for (int j = 0; flg && j < sz(adj[i]); j++) {
			int k = adj[i][j];
			if (k == par[i]) {
				if (x1[i] != y1[i]) {
					flg = 0;
				}
			} else {
				if (x[k] != y[k]) flg = 0;
			}
		}
		if (flg) {
			puts("YES");
			cout << i << endl;
			return 0;
		}
	}
	puts("NO");
	return 0;
}