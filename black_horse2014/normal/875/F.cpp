#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
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

const int MAXN = 2e5 + 10;

int id[MAXN], a[MAXN], b[MAXN], c[MAXN], f[MAXN], chk[MAXN];

int find_set(int u) {
	return f[u] == u ? u : f[u] = find_set(f[u]);
}

bool cmp(int i, int j) {
	return c[i] > c[j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a[i], &b[i], &c[i]);
		id[i] = i;
	}
	sort(id + 1, id + m + 1, cmp);
	for (int i = 1; i <= n; i++) f[i] = i;
	int ans = 0;
	for (int j = 1; j <= m; j++) {
		int i = id[j], u = a[i], v = b[i], w = c[i];
		u = find_set(u), v = find_set(v);
		if (chk[u] && chk[v]) continue;
		if (u == v) {
			chk[u] = 1;
			ans += w;
		} else {
			ans += w;
			chk[v] |= chk[u];
			f[u] = v;
		}
	}
	cout << ans << endl;
	return 0;
}