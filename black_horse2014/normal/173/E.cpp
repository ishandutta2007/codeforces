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

const int MAXN = 111111;

int n, m, N;
int xn;

int ans[MAXN], c[MAXN], a[MAXN], b[MAXN], id[MAXN], x[MAXN];
int qid[MAXN], L[MAXN], R[MAXN], B[MAXN], ret[MAXN];
int dp[1<<18];

void add(int u) {
	for (; u <= xn; u += u & -u) c[u]++;
}

int get(int u) {
	int ret = 0;
	for (; u; u -= u & -u) ret += c[u];
	return ret;
}

bool cmp(int u, int v) {
	return b[u] > b[v];
}

bool cmp1(int u, int v) {
	return B[u] > B[v];
}

void update(int u, int v) {
	u += N;
	if (dp[u] >= v) return;
	for (dp[u] = v, u >>= 1; u; u >>= 1) chkmax(dp[u], v);
}

int query(int st, int en) {
	st += N, en += N;
	int ret = 0;
	while (st < en) {
		if (st & 1) chkmax(ret, dp[st]);
		if (en & 1) chkmax(ret, dp[en-1]);
		st = st + 1 >> 1, en >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) id[i] = i;
	for (int i = 1; i <= n; i++) x[xn++] = a[i];
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (int i = 1; i <= n; i++) a[i] = lower_bound(x, x + xn, a[i]) - x;
	sort(id + 1, id + n + 1, cmp);
	for (int i = n, j; i > 0; i = j) {
		for (j = i; j > 0 && b[id[i]] == b[id[j]]; j--) add(a[id[j]] + 1);
		for (int k = i; k > j; k--) {
			int u = id[k];
			int r = upper_bound(x, x + xn, x[a[u]] + m) - x;
			int l = lower_bound(x, x + xn, x[a[u]] - m) - x;
			ans[u] = get(r) - get(l);
		}
	}
	int q; scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int u, v; scanf("%d%d", &u, &v);
		L[i] = lower_bound(x, x + xn, max(x[a[u]], x[a[v]]) - m) - x + 1;
		R[i] = upper_bound(x, x + xn, min(x[a[u]], x[a[v]]) + m) - x + 1;
		B[i] = max(b[u], b[v]);
		qid[i] = i;
	}
	sort(qid + 1, qid + q + 1, cmp1);
	N = bit(32 - clzi(xn));
	for (int i = 1, j = 1; i <= q; i++) {
		int u = qid[i];
		for (; j <= n && b[id[j]] >= B[u]; j++) update(a[id[j]] + 1, ans[id[j]]);
		ret[u] = query(L[u], R[u]);
	}
	for (int i = 1; i <= q; i++) {
		if (!ret[i]) ret[i]--;
		printf("%d\n", ret[i]);
	}
	return 0;
}