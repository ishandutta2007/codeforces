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

const int MAXN = 333333;
const int MAXM = 1<<20;

int n;
int a[MAXN], b[MAXN];

int dp[2][MAXM], val[MAXM], d[MAXM];

void build(int u, int l, int r) {
	dp[0][u] = r - l + 1;
	if (l == r) return;
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
}

void renew(int u, int x) {
	val[u] += x, d[u] += x;
}

void down(int u) {
	if (!d[u]) return;
	renew(u + u, d[u]), renew(u + u + 1, d[u]);
	d[u] = 0;
}

void up(int u) {
	val[u] = min(val[u + u], val[u + u + 1]);
	dp[0][u] = (val[u + u] == val[u] ? dp[0][u + u] : 0) + (val[u + u + 1] == val[u] ? dp[0][u + u + 1] : 0);
	dp[1][u] = (val[u + u] == val[u] ? dp[1][u + u] : (val[u + u] == val[u] + 1 ? dp[0][u + u] : 0)) + 
	(val[1 + u + u] == val[u] ? dp[1][1 + u + u] : (val[1 + u + u] == val[u] + 1 ? dp[0][1 + u + u] : 0));
}

void add(int u, int l, int r, int ll, int rr, int x) {
	if (ll <= l && r <= rr) {
		renew(u, x);
		return;
	}
	int mid = l + r >> 1;
	down(u);
	if (ll <= mid) add(u + u, l, mid, ll, rr, x);
	if (mid < rr) add(u + u + 1, mid + 1, r, ll, rr, x);
	up(u);
}

int v, d1, d2;

void merge(int vv, int dd1, int dd2) {
	int tv = min(v, vv);
	int td1 = (v == tv ? d1 : 0) + (vv == tv ? dd1 : 0);
	int td2 = (v == tv ? d2 : (v == tv + 1 ? d1 : 0)) + (vv == tv ? dd2 : (vv == tv + 1 ? dd1 : 0));
	v = tv, d1 = td1, d2 = td2;
}

void get(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) {
		merge(val[u], dp[0][u], dp[1][u]);
		return;
	}
	int mid = l + r >> 1;
	down(u);
	if (ll <= mid) get(u + u, l, mid, ll, rr);
	if (mid < rr) get(u + u + 1, mid + 1, r, ll, rr);
}

int query(int r) {
	if (r <= 0) return 0;
	v = n+2, d1 = 0, d2 = 0;
	get(1, 1, n, 1, r);
	if (v == 1) return d1 + d2;
	if (v == 2) return d1;
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), b[a[i]] = i;
	build(1, 1, n);
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = b[i];
		add(1, 1, n, 1, i, 1);
		if (x > 1 && a[x-1] < i) add(1, 1, n, 1, a[x-1], -1);
		if (x < n && a[x+1] < i) add(1, 1, n, 1, a[x+1], -1);
		ans += query(i-1);
	}
	cout << ans << endl;
	return 0;
}