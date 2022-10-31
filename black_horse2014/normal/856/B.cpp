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

const int MAXN = 1000010;

int g[MAXN], d[MAXN], id[MAXN], f[MAXN], chd[MAXN][26];
char s[MAXN];

bool cmp(int u, int v) {
	if (d[u] != d[v]) return d[u] < d[v];
	return u < v;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (int i = 0; i < 26; i++) chd[0][i] = 1;
	for (scanf("%d", &ncase); ncase--; ) {
		int n; scanf("%d", &n);
		int m = 1;
		memset(chd[1], 0, sizeof chd[1]);
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			int u = 1;
			for (int j = 0; s[j]; j++) {
				int &v = chd[u][s[j] - 'a'];
				if (!v) {
					v = ++m;
					d[v] = j + 1;
					memset(chd[v], 0, sizeof chd[v]);
				}
				u = v;
			}
		}
		for (int i = 1; i <= m; i++) id[i] = i;
		sort(id + 1, id + m + 1, cmp);
		for (int u = 2; u <= m; u++) f[u] = u;
		for (int i = 1, u; i <= m; i++) {
			u = id[i];
			if (f[u] == u) continue;
			for (int p = f[u], q, j = 0, v; j < 26; j++) {
				v = chd[u][j];
				if (!v) continue;
				if (chd[p][j]) {
					q = chd[p][j];
					f[v] = q;
				} else {
					f[v] = v;
				}
			}
		}
		for (int u = 2; u <= m; u++) g[u] = 1;
		int ans = 0;
		for (int u, i = m; i > 1; i--) {
			u = id[i]; ans += g[u];
			if (f[u] != u) g[f[u]] &= !g[u];
		}
		printf("%d\n", ans);
	}
	return 0;
}