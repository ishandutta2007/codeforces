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

VI adj[MAXN], con[MAXN];
int x[MAXN], col[MAXN], f[MAXN];

int get(int u) {
	return f[u] == 0 ? u : f[u] = get(f[u]);
}

int dfs(int u, int c) {
	col[u] = c;
	for (int i = 0; i < sz(con[u]); i++) {
		int v = con[u][i];
		if (~col[v]) {
			if (col[u] == col[v]) return 0;
		} else {
			if (!dfs(v, c ^ 1)) return 0;
		}
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]), x[i] ^= 1;
	for (int i = 1; i <= m; i++) {
		int c; scanf("%d", &c);
		while (c--) {
			int u; scanf("%d", &u);
			adj[u].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!x[i]) {
			int u = get(adj[i][0]), v = get(adj[i][1]);
			if (u != v) f[u] = v;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (x[i]) {
			int u = get(adj[i][0]), v = get(adj[i][1]);
			if (u == v) return puts("NO"), 0;
			con[u].push_back(v);
			con[v].push_back(u);
		}
	}
	memset(col, -1, sizeof col);
	for (int i = 1; i <= m; i++) {
		if (!~col[i]) {
			if (!dfs(i, 0)) return puts("NO"), 0;
		}
	}
	puts("YES");
	return 0;
}