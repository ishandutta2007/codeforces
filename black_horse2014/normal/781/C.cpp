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

const int MAXN = 222222;

VI adj[MAXN], ans[MAXN];

int chk[MAXN], q[2*MAXN];
int qn;

void dfs(int u) {
	chk[u] = 1;
	q[qn++] = u;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (chk[v]) continue;
		dfs(v);
		q[qn++] = u;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, p; cin >> n >> m >> p;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	dfs(1);
	assert(qn == 2*n-1);
	int c = (2*n+p-1)/p;
	for (int i = 0; i < p; i++) {
		for (int j = i*c; j < qn && j < (i+1)*c; j++) {
			ans[i].push_back(q[j]);
		}
		if (ans[i].empty()) ans[i].push_back(1);
	}
	for (int i = 0; i < p; i++) {
		printf("%d", sz(ans[i]));
		for (int j = 0; j < sz(ans[i]); j++) printf(" %d", ans[i][j]);
		puts("");
	}
	return 0;
}