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

const int MAXN = 1<<20;

int dp[MAXN], x[2][MAXN], y[2][MAXN], a[MAXN];
long long z[2][MAXN], add[MAXN];

void up(int u, int l, int r) {
	int mid = l + r >> 1;
	dp[u] = max(dp[u + u], dp[u + u + 1]);
	z[0][u] = z[0][u + u], z[1][u] = z[1][u + u + 1];
	y[1][u] = y[1][u + u + 1], x[1][u] = x[1][u + u + 1];
	y[0][u] = y[0][u + u], x[0][u] = x[0][u + u];
	if (z[1][u + u] < z[0][u + u + 1]) chkmax(dp[u], x[1][u + u] + y[0][u + u + 1]);
	if (z[1][u + u] > z[0][u + u + 1]) chkmax(dp[u], y[1][u + u] + x[0][u + u + 1]);
	if (y[0][u + u] == mid - l + 1 && z[1][u + u] > z[0][u + u + 1]) chkmax(y[0][u], y[0][u + u] + x[0][u + u + 1]);
	if (x[0][u + u] == mid - l + 1 && z[1][u + u] > z[0][u + u + 1]) chkmax(x[0][u], x[0][u + u] + x[0][u + u + 1]);
	if (x[1][u + u] == mid - l + 1 && z[1][u + u] < z[0][u + u + 1]) chkmax(y[0][u], x[1][u + u] + y[0][u + u + 1]);
	if (y[1][u + u + 1] == r - mid && z[1][u + u] < z[0][u + u + 1]) chkmax(y[1][u], y[1][u + u + 1] + x[1][u + u]);
	if (x[1][u + u + 1] == r - mid && z[1][u + u] < z[0][u + u + 1]) chkmax(x[1][u], x[1][u + u + 1] + x[1][u + u]);
	if (x[0][u + u + 1] == r - mid && z[1][u + u] > z[0][u + u + 1]) chkmax(y[1][u], x[0][u + u + 1] + y[1][u + u]);
	chkmax(y[0][u], x[0][u]), chkmax(y[1][u], x[1][u]);
	chkmax(dp[u], x[0][u]);
	chkmax(dp[u], x[1][u]);
	chkmax(dp[u], y[1][u]);
	chkmax(dp[u], y[0][u]);
}

void build(int u, int l, int r) {
	if (l == r) {
		dp[u] = x[0][u] = y[0][u] = x[1][u] = y[1][u] = 1;
		z[0][u] = z[1][u] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
	up(u, l, r);
}

void renew(int u, long long x) {
	z[0][u] += x, z[1][u] += x, add[u] += x;
}

void down(int u) {
	if (add[u]) renew(u + u, add[u]), renew(u + u + 1, add[u]), add[u] = 0;
}

void update(int u, int l, int r, int ll, int rr, int d) {
	if (ll <= l && r <= rr) {
		renew(u, d);
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (ll <= mid) update(u + u, l, mid, ll, rr, d);
	if (mid < rr) update(u + u + 1, mid + 1, r, ll, rr, d);
	up(u, l, r);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	int m; scanf("%d", &m);
	while (m--) {
		int l, r, d; scanf("%d%d%d", &l, &r, &d);
		update(1, 1, n, l, r, d);
		printf("%d\n", dp[1]);
	}
	return 0;
}