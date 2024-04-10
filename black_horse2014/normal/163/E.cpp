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

const int MAXN = 1111111;

int wa[MAXN], wb[MAXN], wc[MAXN], wd[MAXN];
int sa[MAXN], rnk[MAXN], lcp[MAXN];
int m;
int cnt[MAXN];

char s[MAXN], t[MAXN], str[MAXN];
int L[MAXN], R[MAXN], st[MAXN], en[MAXN], lo[MAXN], hi[MAXN];
int tp[MAXN], id[MAXN];

namespace SA {
	const int MAXN = 555555;
	bool is_equal(int *r, int a, int b, int l, int n) {
		int la = r[a], lb = r[b], ra, rb;
		ra = a + l < n ? r[a+l] : -1;
		rb = b + l < n ? r[b+l] : -1;
		return (la == lb) && (ra == rb);
	}
	void buildSA(char *r, int *sa, int n, int m) {
		int *x = wa, *y = wb;
		memset(wc, 0, sizeof(int) * m);
		for (int i = 0; i < n; i++) wc[x[i] = r[i]]++;
		for (int i = 1; i < m; i++) wc[i] += wc[i-1];
		for (int i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
		for (int tot = 0, p = 1; tot + 1 < n; p <<= 1, m = tot + 1) {
			tot = 0;
			for (int i = n - p; i < n; i++) y[tot++] = i;
			for (int i = 0; i < n; i++) if (sa[i] >= p) y[tot++] = sa[i] - p;
			for (int i = 0; i < n; i++) wd[i] = x[y[i]];
			memset(wc, 0, sizeof(int) * m);
			for (int i = 0; i < n; i++) wc[wd[i]]++;
			for (int i = 1; i < m; i++) wc[i] += wc[i-1];
			for (int i = n - 1; i >= 0; i--) sa[--wc[wd[i]]] = y[i];
			swap(x, y);
			x[sa[0]] = tot = 0;
			for (int i = 1; i < n; i++) x[sa[i]] = is_equal(y, sa[i-1], sa[i], p, n) ? tot : ++tot;
		}
	}
	void buildLCP(char *r, int *sa, int *lcp, int n) {
		for (int i = 0; i < n; i++) rnk[sa[i]] = i;
		lcp[0] = 0;
		for (int i = 0; i < n; i++) if (rnk[i]) {
			lcp[rnk[i]] = ((i == 0) ? 0 : max(0, lcp[rnk[i-1]] - 1));
			for ( ; r[i+lcp[rnk[i]]] == r[sa[rnk[i]-1] + lcp[rnk[i]]]; lcp[rnk[i]]++);
		}
	}
};

void add(int u, int x) {
	for (u++; u <= m; u += u & -u) cnt[u] += x;
}

bool comp(int l1, int r1, int l2, int r2) {
	int L = min(r1-l1, r2-l2);
	for (int i = 0; i < L; i++) {
		if (str[i+l1] != s[l2+i]) return str[i+l1] < s[l2+i];
	}
	return r1-l1 <= r2-l2;
}

int get_lower_bound(int st, int en) {
	int lo = -1, hi = m;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (comp(st, en, sa[mid], m)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	return hi;
}

int chk[MAXN];

int get(int u) {
	int ret = 0;
	for (u++; u; u -= u & -u) ret += cnt[u];
	return ret;
}

int main() {
	int q, n; cin >> q >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", t);
		st[i] = m;
		for (int j = 0; t[j]; j++) str[m++] = t[j];
		str[m++] = 'z' + 2;
		en[i] = m;
	}
	m = 0;
	for (int i = 1; i <= q; i++) {
		scanf("%s", t);
		if (t[0] == '?') {
			tp[i] = 2;
			lo[i] = m;
			for (int j = 1; t[j]; j++) s[m++] = t[j];
			hi[i] = m;
			s[m++] = 'z' + 1;
		} else {
			id[i] = atoi(t+1);
			if (t[0] == '+') tp[i] = 0;
			else tp[i] = 1;
		}
	}
	s[m] = 0;
	SA::buildSA(s, sa, m, 256);
	for (int i = 1; i <= n; i++) {
		L[i] = get_lower_bound(st[i], en[i]-1);
		R[i] = get_lower_bound(st[i], en[i]);
		add(L[i], 1), add(R[i], -1), chk[i] = 1;
	}
	for (int i = 0; i < m; i++) rnk[sa[i]] = i;
	for (int i = 1; i <= q; i++) {
		int u = id[i];
		if (tp[i] == 0) {
			if (!chk[u]) {
				add(L[u], 1);
				add(R[u], -1);
				chk[u] = 1;
			}
		} else if (tp[i] == 1) {
			if (chk[u]) {
				chk[u] = 0;
				add(L[u], -1);
				add(R[u], 1);
			} 
		} else {
			long long ans = 0;
			for (int j = lo[i]; j < hi[i]; j++) ans += get(rnk[j]);
			printf("%lld\n", ans);
		}
	}
	return 0;
}