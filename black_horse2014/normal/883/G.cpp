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

int T;

const int MAXN = 330000;

int vis[MAXN];
int a[MAXN], b[MAXN], c[MAXN];
VPII con[MAXN];

int dfs_max(int u) {
	vis[u] = ++T;
	int ret = 1;
	for (int i = 0; i < sz(con[u]); i++) {
		int j = con[u][i].first;
		int v = a[j] ^ b[j] ^ u;
//		cerr << u << ' ' << v << endl;
		if (!vis[v]) ret += dfs_max(v);
	}
	return ret;
}

int dfs_min(int u) {
	vis[u] = ++T;
	int ret = 1;
	for (int i = 0; i < sz(con[u]); i++) {
		int j = con[u][i].first, w = con[u][i].second;
		int v = a[j] ^ b[j] ^ u;
		if (w == 0) {
			if (!vis[v]) ret += dfs_min(v);
		}
	}
	return ret;
}

int main() {
	int n, m, s; scanf("%d%d%d", &n, &m, &s);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &c[i], &a[i], &b[i]);
		if (c[i] == 1) {
			con[a[i]].push_back(PII(i, 0));
		} else {
			con[a[i]].push_back(PII(i, 1));
			con[b[i]].push_back(PII(i, -1));
		}
	}
	int cnt = 0;
	memset(vis, 0, sizeof vis);
	cnt = dfs_max(s);
	cout << cnt << endl;
	for (int i = 1; i <= m; i++) {
		if (c[i] == 2) {
			if (vis[a[i]] > vis[b[i]]) putchar('-');
			else putchar('+');
		}
	}
	puts("");
	memset(vis, 0, sizeof vis);
	T = 0;
	cnt = dfs_min(s);
	cout << cnt << endl;
	for (int i = 1; i <= m; i++) {
		if (c[i] == 2) {
			if (vis[a[i]] && !vis[b[i]]) putchar('-');
			else putchar('+');
		}
	}
	return 0;
}