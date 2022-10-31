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

int vis[222222], h[222222], deg[222222];
VI adj[222222];
int r;

int dfs(int u, int p) {
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		if (dfs(v, u)) return 1;
		chkmax(h[u], h[v] + 1);
	}
	if (u == r) return 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		if (h[u] > h[v] + 1) {
			r = u;
			return 1;
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v), deg[u]++;
		adj[v].push_back(u), deg[v]++;
	}
	for (int i = 1; i <= n; i++) if (deg[i] > 2) r = i;
	if (r == 0) {
		int ans = n-1;
		cout << ans / (ans & -ans) << endl;
		return 0;
	}
	dfs(r, 0);
	memset(h, 0, sizeof h);
	if (dfs(r, 0)) return puts("-1"), 0;
	vector<int> V;
	for (int i = 0; i < sz(adj[r]); i++) {
		int v = adj[r][i]; V.pb(h[v] + 1);
	}
	sort(all(V));
	int cnt = 0, ans = 0;
	for (int i = 0, j; i < sz(V); i = j) {
		for (j = i; j < sz(V) && V[i] == V[j]; j++);
		cnt++;
		if (cnt > 2) {
			puts("-1");
			return 0;
		}
		ans += V[i];
	}
	cout << ans / (ans & -ans) << endl;
	return 0;
}