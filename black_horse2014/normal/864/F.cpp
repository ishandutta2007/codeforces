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

const int MAXN = 3005;

#define next asdf

int chk[MAXN], q[MAXN];
short next[13][MAXN][MAXN];
vector<int> adj[MAXN], radj[MAXN];

int go(int s, int t, int k) {
	if (k < 0) return 0;
	for (int i = 0; i <= 11; i++) if (k >> i & 1) s = next[i][t][s];
	return s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, Q; scanf("%d%d%d", &n, &m, &Q);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		radj[v].pb(u), adj[u].pb(v);
	}
	for (int i = 1; i <= n; i++) sort(all(adj[i]));
	for (int t = 1; t <= n; t++) {
		for (int s = 1; s <= n; s++) chk[s] = 0;
		int qn = 0; q[qn++] = t; chk[t] = 1;
		for (int j = 0; j < qn; j++) {
			int s = q[j];
			for (int l = 0; l < sz(radj[s]); l++) {
				int ns = radj[s][l];
				if (chk[ns]) continue;
				q[qn++] = ns, chk[ns] = 1;
			}
		}
		for (int s = 1; s <= n; s++) {
			if (chk[s]) {
				if (s == t) {
					next[0][t][s] = t;
					continue;
				}
				for (int j = 0; j < sz(adj[s]); j++) {
					int ns = adj[s][j];
					if (chk[ns]) {
						next[0][t][s] = ns;
						break;
					}
				}
			}
		}
		for (int j = 1; j <= 12; j++) {
			for (int s = 1; s <= n; s++) next[j][t][s] = next[j-1][t][next[j-1][t][s]];
		}
	}
	while (Q--) {
		int s, t, k; scanf("%d%d%d", &s, &t, &k);
		if (next[12][t][s] != t) {
			puts("-1");
			continue;
		}
		k--;
		if (go(s, t, k) == t && go(s, t, k-1) == t) {
			puts("-1");
			continue;
		}
		printf("%d\n", go(s, t, k));
	}
	return 0;
}