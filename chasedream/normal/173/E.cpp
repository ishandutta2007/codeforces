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

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 110000;

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

#define ls (u << 1)
#define rs (u << 1 | 1)
int mx[MAXN << 2];

void pushup(int u) {
  mx[u] = max(mx[ls], mx[rs]);
}

void update(int u, int l, int r, int pos, int x) {
  if (l == r) {
    mx[u] = max(mx[u], x);
    return ;
  }
  int mid = l + r >> 1;
  if (pos <= mid) update(ls, l, mid, pos, x);
  else update(rs, mid + 1, r, pos, x);
  pushup(u);
}

int query(int u, int l, int r, int ql, int qr) {
  if (ql > qr) return 0;
  if (ql <= l && r <= qr) {
    return mx[u];
  }
  int mid = l + r >> 1;
  if (qr <= mid) return query(ls, l, mid, ql, qr);
  else if (ql > mid) return query(rs, mid + 1, r, ql, qr);
  else return max(query(ls, l, mid, ql, qr), query(rs, mid + 1, r, ql, qr));
}

#define CL(s) memset(s, 0, sizeof(s))
int tag[MAXN];

void work() {
  xn = 0; N = 0; n = 0; m = 0;
  CL(ans); CL(c); CL(a); CL(b); CL(id); CL(x); CL(qid);
  CL(L); CL(R); CL(B); CL(ret); CL(dp); CL(mx);
  
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (register int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (register int i = 1; i <= n; i++) id[i] = i;
	for (register int i = 1; i <= n; i++) x[xn++] = a[i];
	sort(x, x + xn);
	xn = unique(x, x + xn) - x;
	for (register int i = 1; i <= n; i++) a[i] = lower_bound(x, x + xn, a[i]) - x;
	sort(id + 1, id + n + 1, cmp);
	for (register int i = n, j; i > 0; i = j) {
		for (j = i; j > 0 && b[id[i]] == b[id[j]]; j--) add(a[id[j]] + 1);
		for (register int k = i; k > j; k--) {
			int u = id[k];
			int r = upper_bound(x, x + xn, x[a[u]] + m) - x;
			int l = lower_bound(x, x + xn, x[a[u]] - m) - x;
			ans[u] = get(r) - get(l);
		}
	}
	int q; scanf("%d", &q);
	for (register int i = 1; i <= q; i++) {
		int u, v; scanf("%d%d", &u, &v);
		L[i] = lower_bound(x, x + xn, max(x[a[u]], x[a[v]]) - m) - x + 1;
		R[i] = upper_bound(x, x + xn, min(x[a[u]], x[a[v]]) + m) - x;
		B[i] = max(b[u], b[v]);
		qid[i] = i;
	}
	sort(qid + 1, qid + q + 1, cmp1);
	for (register int i = 1, j = 1; i <= q; i++) {
		int u = qid[i];
		for (; j <= n && b[id[j]] >= B[u]; j++) update(1, 1, xn, a[id[j]] + 1, ans[id[j]]);
		//printf("for querys %d: %d %df\n", u, L[u], R[u]);
		ret[u] = query(1, 1, xn, L[u], R[u]);
	}
	for (register int i = 1; i <= q; i++) {
		if (!ret[i]) ret[i] = -1;
		printf("%d\n", ret[i]);
	}
	return ;
}

int main() {
  int T = 1;
  while (T--) work();
	return 0;
}