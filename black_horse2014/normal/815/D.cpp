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

int a[MAXN], b[MAXN], add[MAXN], c[MAXN], x[MAXN], d[MAXN];
long long s[MAXN];
int mb[MAXN], mc[MAXN];

VI V[MAXN/2];

int p, q, r;

void renew(int u, int l, int r, int x) {
	d[u] = add[u] = x;
	s[u] = 1LL * (r - l + 1) * x;
}

void down(int u, int l, int r) {
	if (!add[u]) return;
	int mid = l + r >> 1;
	renew(u + u, l, mid, add[u]);
	renew(u + u + 1, mid + 1, r, add[u]);
	add[u] = 0;
}

void up(int u) {
	d[u] = max(d[u + u], d[u + u + 1]);
	s[u] = s[u + u] + s[u + u + 1];
}

int query(int u, int l, int r, int x) {
	if (d[u] <= x) return 0;
	if (l == r) return l;
	down(u, l, r);
	int mid = l + r >> 1, ret = query(u + u + 1, mid + 1, r, x);
	if (ret) return ret;
	return query(u + u, l, mid, x);
}

void update(int u, int l, int r, int ll, int rr, int x) {
	if (ll <= l && r <= rr) {
		renew(u, l, r, x);
		return;
	}
	down(u, l, r);
	int mid = l + r >> 1;
	if (ll <= mid) update(u + u, l, mid, ll, rr, x);
	if (mid < rr) update(u + u + 1, mid + 1, r, ll, rr, x);
	up(u);
}

long long get_sum(int u, int l, int r, int ll, int rr) {
	if (ll <= l && r <= rr) return s[u];
	int mid = l + r >> 1;
	down(u, l, r);
	long long ret = 0;
	if (ll <= mid) ret += get_sum(u + u, l, mid, ll, rr);
	if (mid < rr) ret += get_sum(u + u + 1, mid + 1, r, ll, rr);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d%d%d%d", &n, &p, &q, &r);
	for (int i = 1; i <= n; i++) scanf("%d%d%d", &a[i], &b[i], &c[i]), x[i-1] = a[i];
	x[n] = 0, x[n+1] = p;
	sort(x, x + n + 2);
	int xn = unique(x, x + n + 2) - x;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(x, x + xn, a[i]) - x, V[a[i]].push_back(i);
	for (int i = 1; i <= n; i++) chkmax(mb[a[i]], b[i]), chkmax(mc[a[i]], c[i]);
	for (int i = xn-1; i >= 0; i--) chkmax(mb[i], mb[i+1]), chkmax(mc[i], mc[i+1]);
	long long ans = 0;
	for (int i = 0; i < xn-1; i++) {
		for (int j = 0; j < V[i].size(); j++) {
			int u = V[i][j];
			int ret = query(1, 1, q, c[u]);
			if (ret < b[u]) update(1, 1, q, ret+1, b[u], c[u]);
		}
		int ret = query(1, 1, q, mc[i+1]);
		ans += 1LL * (x[i+1] - x[i]) * (q - mb[i+1]) * (r - mc[i+1]);
		if (ret > mb[i+1]) {
			ans -= 1LL * (x[i+1] - x[i]) * (get_sum(1, 1, q, mb[i+1]+1, ret) - 1LL * mc[i+1] * (ret - mb[i+1]));
		}
	}
	cout << ans << endl;
	return 0;
}