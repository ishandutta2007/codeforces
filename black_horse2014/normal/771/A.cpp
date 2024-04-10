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

int chk[151111];
VI adj[151111];
VI V;
void dfs(int u) {
	chk[u] = 1; V.pb(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (chk[v]) continue;
		dfs(v);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	bool flg = 1;
	for (int i = 1; flg && i <= n; i++) {
		if (!chk[i]) {
			V.clear();
			dfs(i);
			for (int j = 0; flg && j < sz(V); j++) {
				if (sz(adj[V[j]]) != sz(V)-1) flg = 0;
			}
		}
	}
	puts(flg ? "YES" : "NO");
	return 0;
}