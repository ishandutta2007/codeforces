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

#define tm asdf

const int MAXN = 320000;

VI adj[MAXN], vis[MAXN], gg[MAXN];

int n, m;
int cc;
PII id[MAXN];
VPII V;
map<PII, VI> M;

VI ls;
int sz[MAXN];
int was[MAXN];
int col[MAXN];

void dfs1(int v, int k) {
	if (vis[v][k])
		return;
	vis[v][k] = 1;
	gg[cc].push_back(v);
	int u = adj[v][k];
	int x = lower_bound(adj[u].begin(), adj[u].end(), v) - adj[u].begin();
	++x;
	if (x == adj[u].size())
		x = 0;
	dfs1(u, x);
}

int tm;

void dfs2(int v) {
	ls.push_back(v);
	sz[v] = 1;
	was[v] = tm;
	for (int u: adj[v]) {
		if (was[u] < tm) {
			dfs2(u);
			sz[v] += sz[u];
		}
	}
}

void solve(int v, int k) {
	++tm;
	ls.clear();
	dfs2(v);
	int bst = -1;
	for (int i: ls) {
		if (sz[i] * 2 >= sz[v] && (bst == -1 || sz[i] < sz[bst]))
			bst = i;
	}
	v = bst;
	was[v] = MAXN;
	int x = lower_bound(all(V), id[v]) - V.begin();
	col[x] = k;
	for (int u: adj[v]) {
		if (was[u] < MAXN)
			solve(u, k + 1);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		int x = (i + 1) % n;
		adj[i].push_back(x);
		adj[x].push_back(i);
	}
	for (int i = 0; i < m; ++i) { 
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		sort(all(adj[i])), vis[i].resize(adj[i].size());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < adj[i].size(); ++j)
			if (!vis[i][j]) {
				dfs1(i, j);
				++cc;
			}
	}
	for (int i = 1; i < cc; ++i) {
		int mx1 = 0, mx2 = 0;
		gg[i].push_back(gg[i][0]);
		for (int j = 0; j < gg[i].size() - 1; ++j) {
			int a = gg[i][j];
			int b = gg[i][j + 1];
			if (mx2 < a) mx2 = a;
			if (mx2 > mx1) swap(mx2, mx1);
			if (a > b) swap(a, b);
			M[PII(a, b)].push_back(i);
		}
		id[i] = PII(mx1, mx2);
		V.push_back(PII(mx1, mx2));
	}
	sort(all(V));
	for (int i = 0; i < n; ++i) adj[i].clear();
	for (map<PII, VI> :: iterator it = M.begin(); it != M.end(); it++) {
		if (it->second.size() != 2) continue;
		adj[it->second[0]].push_back(it->second[1]);
		adj[it->second[1]].push_back(it->second[0]);
	}
	solve(1, 1);
	for (int i = 0; i < V.size(); ++i)
		printf("%d ", col[i]);
	printf("\n");
	return 0;
}