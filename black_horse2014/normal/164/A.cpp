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

VI adj[MAXN], radj[MAXN];
int c[MAXN], q[MAXN], vis[MAXN];
int qn;

int main() {
	
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		radj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 2) {
			q[qn++] = i, vis[i] = 1;
		}
	}
	for (int i = 0; i < qn; i++) {
		int u = q[i];
		for (int j = 0; j < radj[u].size(); j++) {
			int v = radj[u][j];
			if (c[v] == 1 || vis[v]) continue;
			q[qn++] = v, vis[v] = 1;
		}
	}
	qn = 0;
	for (int u = 1; u <= n; u++) {
		if (c[u] == 1) {
			for (int j = 0; j < sz(adj[u]); j++) {
				int v = adj[u][j];
				if (!vis[v]) continue;
				q[qn++] = v, vis[v] = 2;
			}
		}
	}
	for (int i = 0; i < qn; i++) {
		int u = q[i];
		for (int j = 0; j < adj[u].size(); j++) {
			int v = adj[u][j];
			if (vis[v] == 1) q[qn++] = v, vis[v] = 2;
		}
	}
	for (int u = 1; u <= n; u++) {
		if (c[u] != 1 && vis[u] == 2) {
			for (int j = 0; j < sz(radj[u]); j++) {
				int v = radj[u][j];
				if (c[v] == 1) vis[v] = 2;
			}
		}
	}
	for (int u = 1; u <= n; u++) printf("%d\n", vis[u]/2);
	return 0;
}