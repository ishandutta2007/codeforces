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

const int MAXN = 2e5 + 5;

vector<int> V[MAXN];
int vis[MAXN], q[MAXN], qn, a[MAXN];
int _n, cn;

#define NOT(x) (((x)+_n))
vector<int> adj[MAXN], radj[MAXN];
inline void add(int u, int v) {
	adj[u].pb(v);
	radj[v].pb(u);
}

inline void add_true(int u) {
	add(NOT(u), (u));
}

inline void add_false(int u) {
	add((u), NOT(u));
}

void DFS(int u) {
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (vis[v]) continue;
		DFS(v);
	}
	q[qn++] = u;
}

void _DFS(int u) {
	vis[u] = cn;
	for (int i = 0; i < radj[u].size(); i++) {
		int v = radj[u][i];
		if (vis[v]) continue;
		_DFS(v);
	}
}

bool can() {
	memset(vis, 0, sizeof vis);
	qn = 0;
	for (int i = 1; i <= 2 * _n; i++) {
		if (vis[i]) continue;
		DFS(i);
	}
	memset(vis, 0, sizeof vis);
	cn = 0;
	for (int i = qn - 1; ~i; i--) {
		int now = q[i];
		if (vis[now]) continue;
		cn++;
		_DFS(now);
	}
	for (int i = 1; i <= _n; i++) {
		if (vis[i] == vis[NOT(i)]) return false;
		a[i] = (vis[i] > vis[NOT(i)]);
		a[NOT(i)] = a[i] ^ 1;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l; scanf("%d", &l);
		for (int j = 0; j < l; j++) {
			int t; scanf("%d", &t);
			V[i].pb(t);
		}
	}
	int flg = 0;
	_n = m;
	for (int i = n - 1; i > 0; i--) {
		int len = min(V[i].size(), V[i+1].size());
		int j;
		for (j = 0; j < len; j++) {
			if (V[i][j] != V[i+1][j]) break;
		}
		if (j == V[i+1].size()) {
			if (j == V[i].size()) continue;
			flg = 1;
			break;
		}
		if (j == V[i].size()) continue;
		if (V[i][j] < V[i+1][j]) {
			add(V[i+1][j], (V[i][j]));
			add(NOT(V[i][j]), NOT(V[i+1][j]));
		} else {
			add_true(V[i][j]);
			add_false(V[i+1][j]);
		}
	}
	if (flg) return puts("No"), 0;
	if (!can()) return puts("No"), 0;
	puts("Yes");
	int cnt = 0;
	for (int i = 1; i <= m; i++) cnt += a[i];
	printf("%d\n", cnt);
	flg = 0;
	for (int i = 1; i <= m; i++) if (a[i]) {
		if (flg) printf(" ");
		printf("%d", i);
		flg = 1;
	}
	return 0;
}