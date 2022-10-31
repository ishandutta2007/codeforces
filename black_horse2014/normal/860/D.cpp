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

const int MAXN = 200000 + 10;

VI adj[MAXN], ans[MAXN];
int T, chk[MAXN], vis[MAXN];

void dfs(int u, int p) {
	vis[u] = ++T;
	for (auto v : adj[u]) {
		if (v == p) continue;
		if (!vis[v]) {
			dfs(v, u);
			if (chk[v]) chk[v] ^= 1, ans[v].push_back(u);
			else chk[u] ^= 1, ans[u].push_back(v);
		} else if (vis[v] < vis[u]) {
			chk[u] ^= 1, ans[u].push_back(v);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, 0);
	int ret = 0;
	for (int i = 1; i <= n; i++) ret += ans[i].size() / 2;
	cout << ret << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < ans[i].size()/2; j++) printf("%d %d %d\n", ans[i][2*j], i, ans[i][2*j+1]);
	}
	return 0;
}