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

const int MAXN = 1<<19;
int d[MAXN], f[18][MAXN], g[18][MAXN], a[MAXN], b[MAXN];

int get(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return d[u];
	int mid = l + r >> 1, ret = 0;
	if (ll <= mid) chkmax(ret, get(u + u, l, mid, ll, rr));
	if (mid < rr) chkmax(ret, get(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

void update(int u, int l, int r, int p, int x) {
	if (l == r) {
		d[u] = x; return;
	}
	int mid = l + r >> 1;
	if (p <= mid) update(u + u, l, mid, p, x);
	else update(u + u + 1, mid + 1, r, p, x);
	d[u] = max(d[u + u], d[u + u + 1]);
}

void build(int u, int l, int r) {
	if (l == r) {
		d[u] = a[l] + b[l];
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid); 
	build(u + u + 1, mid + 1, r);
	d[u] = max(d[u + u], d[u + u + 1]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	for (int i = n; i > 0; i--) {
		int lo = i, hi = n+1;
		while (hi - lo > 1) {
			int mid = lo + hi >> 1;
			if (a[mid] <= a[i] + b[i]) lo = mid;
			else hi = mid;
		}
		f[0][i] = max(i, get(1, 1, n, i, lo));
		update(1, 1, n, i, f[0][i]);
	}
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		f[0][i]++;
		if (f[0][i] == n+1) g[0][i] = 0;
		else g[0][i] = a[f[0][i]] - get(1, 1, n, i, f[0][i]-1);
	}
	for (int j = 0; j <= 17; j++) f[j][n+1] = n+1, g[j][n+1] = 0;
	for (int i = n; i > 0; i--) {
		for (int j = 1; j <= 17; j++) f[j][i] = f[j-1][f[j-1][i]], g[j][i] = g[j-1][i] + g[j-1][f[j-1][i]];
	}
	int q; scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		if (f[0][l] > r) {
			puts("0");
			continue;
		}
		int ans = 0;
		for (int j = 17; j >= 0; j--) {
			if (f[j][l] > r) continue;
			ans += g[j][l], l = f[j][l];
		}
		assert(f[0][l] > r);
		printf("%d\n", ans);
	}
	return 0;
}