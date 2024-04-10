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

const int MAXN = 220000;

VI adj[MAXN];
//VI radj[MAXN];

int deg[MAXN], a[MAXN], b[MAXN];
int id[MAXN], ans[MAXN];

void add_edge(int u, int v) {
	adj[u].push_back(v);
//	radj[v].push_back(u);
	deg[v]++;
}

int q[MAXN];

bool cmp(int u, int v) {
	if (a[u] != a[v]) return a[u] < a[v];
	return b[u] < b[v];
}

set<PII> S;

int main() {
	int n, m, K; scanf("%d%d%d", &n, &m, &K);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		if (a[i]) b[i] = a[i];
		else b[i] = K;
	}
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		add_edge(u, v);
		if (a[u] && a[v] && a[u] <= a[v]) return puts("-1"), 0;
	}
	for (int i = 1; i <= n; i++) if (!a[i]) a[i] = 1, b[i] = K;
	int qn = 0;
	for (int i = 1; i <= n; i++) if (!deg[i]) q[qn++] = i;
	for (int it = 0; it < qn; it++) {
		int u = q[it];
		for (int j = 0; j < sz(adj[u]); j++) {
			int v = adj[u][j];
			if (--deg[v] == 0) q[qn++] = v;
		}
	}
	if (qn != n) {
		return puts("-1"), 0;
	}
	for (int i = 0; i < n; i++) {
		int u = q[i];
		for (int j = 0; j < sz(adj[u]); j++) {
			int v = adj[u][j];
			chkmin(b[v], b[u] - 1);
		}
	}
	for (int i = n-1; i >= 0; i--) {
		int u = q[i];
		for (int j = 0; j < sz(adj[u]); j++) {
			int v = adj[u][j];
			chkmax(a[u], a[v] + 1);
		}
	}
	for (int i = 1; i <= n; i++) if (a[i] > b[i]) return puts("-1"), 0;
	for (int i = 1; i <= n; i++) id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1, j = 1; i <= K; i++) {
		while (j <= n && a[id[j]] <= i) S.insert(PII(b[id[j]], id[j])), j++;
		int flg = 0;
		while (!S.empty()) {
			set<PII> :: iterator it = S.begin();
			if (it->first > i) break;
			flg = 1;
			int u = it->second;
			ans[u] = i;
			S.erase(it);
		}
		if (!flg && S.empty()) return puts("-1"), 0;
		if (flg) continue;
		set<PII> :: iterator it = S.begin();
		int u = it->second;
		ans[u] = i;
		S.erase(it);
	}
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return 0;
}