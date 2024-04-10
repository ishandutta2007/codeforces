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

int a[MAXN], b[MAXN], dp[MAXN], add[MAXN], ans[MAXN];

bool cmp(int u, int v) {
	if (a[u] - u != a[v] - v) return a[u] - u < a[v] - v;
	return u < v;
}

int n, T;

void build(int u, int l, int r) {
	dp[u] = max(r-1, 0);
	if (l == r) return;
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
}

void down(int u) {
	for (int i = 0; i < 2; i++) dp[u + u + i] += add[u], add[u + u + i] += add[u];
	add[u] = 0;
}

void modify(int u, int l, int r, int ll, int rr, int x) {
	if (ll > rr) return;
	if (ll <= l && r <= rr) {
		dp[u] += x, add[u] += x;
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (ll <= mid) modify(u + u, l, mid, ll, rr, x);
	if (mid < rr) modify(u + u + 1, mid + 1, r, ll, rr, x);
	dp[u] = max(dp[u + u], dp[u + u + 1]);
}

int query(int u, int l, int r, int ll, int rr) {
	if (ll > rr) return 0;
	int ret = 0;
	if (ll <= l && r <= rr) return dp[u];
	down(u);
	int mid = l + r >> 1;
	if (ll <= mid) ret = max(ret, query(u + u, l, mid, ll, rr));
	if (mid < rr) ret = max(ret, query(u + u + 1, mid + 1, r, ll, rr));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &T);
	n = min(n, T-1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]), a[i] = max(i, min(a[i], T)), b[i] = i;
	}
	if (n == 0) return puts("0"), 0;
	sort(b, b+n+1, cmp);
	build(1, 0, n+1);
	for (int i = n; i >= 0; i--) {
		int st = b[i];
		int en = max(max(st-1, 0), min(n, T-1-(a[st]-st)));
		int x = query(1, 0, n+1, st, st);
		int y = query(1, 0, n+1, st+1, en+1);
		ans[i] = max(y - x, 0);
		if (ans[i] > 0) modify(1, 0, n+1, st, st, ans[i]);
		modify(1, 0, n+1, st+1, n+1, -1);
	}
	cout << ans[0] << endl;
	return 0;
}