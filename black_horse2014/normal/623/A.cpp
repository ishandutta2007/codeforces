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

const int MAXN = 555;

VI adj[MAXN];
int id[MAXN], con[MAXN][MAXN], ans[MAXN];

bool cmp(int u, int v) {
	if (adj[u].size() != adj[v].size()) return adj[u].size() < adj[v].size();
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i] != adj[v][i]) return adj[u][i] < adj[v][i];
	}
	return 0;
}

bool equal(int u, int v) {
	if (adj[u].size() != adj[v].size()) return 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i] != adj[v][i]) return 0;
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v), adj[v].push_back(u);
		con[u][v] = con[v][u] = 1;
	}
	for (int i = 1; i <= n; i++) adj[i].push_back(i);
	for (int i = 1; i <= n; i++) sort(all(adj[i])), id[i] = i;
	sort(id + 1, id + n + 1, cmp);
	int cur = 0;
	for (int i = 1, j; i <= n; i = j) {
		for (j = i; j <= n && equal(id[i], id[j]); j++) {
			ans[id[j]] = cur;
		}
		cur++;
		if (cur > 3) {
			puts("No");
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == n) continue;
		for (int j = i+1; j <= n; j++) {
			if (adj[j].size() == n) continue;
			if (ans[i] != ans[j] && con[i][j]) {
				puts("No");
				return 0;
			}
		}
	}
	bool flg = 0;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == n) flg = 1;
	}
	if (!flg && cur > 2) {
		puts("No");
		return 0;
	}
	puts("Yes");
	if (!flg) {
		for (int i = 1; i <= n; i++) {
			if (ans[i] == 1) putchar('c');
			else putchar('a');
		}
	} else {
		for (int i = 1; i <= n; i++) {
			if (adj[i].size() == n) putchar('b');
			else if (ans[i] == 0) putchar('a');
			else putchar('c');
		}
	}
	return 0;
}