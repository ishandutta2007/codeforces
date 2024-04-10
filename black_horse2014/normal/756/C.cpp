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

const int MAXM = 333333;

int dp[MAXM], t[MAXM], p[MAXM], x[MAXM], d[MAXM];
int n, m;

void build(int u, int l, int r) {
	dp[u] = d[u] = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
}

void renew(int u, int x) {
	d[u] += x, dp[u] += x;
}

void down(int u) {
	if (!d[u]) return;
	renew(u + u, d[u]);
	renew(1 + u + u, d[u]);
	d[u] = 0;
}

void up(int u) {
	dp[u] = max(dp[u + u], dp[u + u + 1]);
}

void update(int u, int l, int r, int ll, int rr, int x) {
	if (ll <= l && r <= rr) {
		renew(u, x);
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (ll <= mid) update(u + u, l, mid, ll, rr, x);
	if (mid < rr) update(u + u + 1, mid + 1, r, ll, rr, x);
	up(u);
}

int sum, ans;

void query(int u, int l, int r) {
	if (ans) return;
	if (dp[u] <= 0) return;
	if (l == r) {
		ans = r;
		return;
	}
	down(u);
	int mid = l + r >> 1;
	query(u + u + 1, mid + 1, r);
	if (ans > mid) return;
	query(u + u, l, mid);
}

int main() {

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i], &t[i]);
		if (t[i]) scanf("%d", &x[p[i]]);
	}
	build(1, 1, n);
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (t[i]) update(1, 1, n, 1, p[i], 1);
		else update(1, 1, n, 1, p[i], -1);
		chkmax(mx, p[i]);
		sum = 0, ans = 0;
		query(1, 1, n);
		if (ans == 0) {
			puts("-1");
		} else {
			printf("%d\n", x[ans]);
		}
	}
	return 0;
}