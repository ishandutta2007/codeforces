#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << x << endl
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
const int MAXN = 555555;
int n;
char str[MAXN];
int a[MAXN], nxt[MAXN];
VI l[2*MAXN];

int rnk[MAXN], sa[MAXN], lcp[MAXN];

namespace SA {
  int wa[MAXN], wb[MAXN], wc[MAXN], wd[MAXN];
	bool is_equal(int *r, int a, int b, int l, int n) {
		int la = r[a], lb = r[b], ra, rb;
		ra = a + l < n ? r[a + l] : -1;
		rb = b + l < n ? r[b + l] : -1;
		return (la == lb) && (ra == rb);
	}
	void SA(char *r, int *sa, int n, int m) {
		int *x = wa, *y = wb;
		int i, tot, p;
		memset(wc, 0, sizeof(int) * m);
		for (i = 0; i < n; i++) wc[x[i] = r[i]]++;
		for (i = 1; i < m; i++) wc[i] += wc[i - 1];
		for (i = n - 1; i >= 0; i--) sa[--wc[x[i]]] = i;
		for (tot = 0, p = 1; tot + 1 < n; p <<= 1, m = tot + 1) {
			for (tot = 0, i = n - p; i < n; i++) y[tot++] = i;
			for (i = 0; i < n; i++) if (sa[i] >= p) y[tot++] = sa[i] - p;
			for (i = 0; i < n; i++) wd[i] = x[y[i]];
			memset(wc, 0, sizeof(int) * m);
			for (i = 0; i < n; i++) wc[wd[i]]++;
			for (i = 1; i < m; i++) wc[i] += wc[i - 1];
			for (i = n - 1; i >= 0; i--) sa[--wc[wd[i]]] = y[i];
			swap(x, y);
			x[sa[0]] = tot = 0;
			for (i = 1; i < n; i++) x[sa[i]] = is_equal(y, sa[i - 1], sa[i], p, n) ? tot : ++tot;
		}
	}	
  void LCP(char *r, int *sa, int *lcp, int n) {
	  int i;
	  for (i = 0; i < n; i++) rnk[sa[i]] = i;
	  for (int i = 0; i < n; i++) lcp[i] = 0;
	  for (lcp[0] = i = 0; i < n; i++) if (rnk[i]) {
		  lcp[rnk[i]] = (i == 0) ? 0 : max(0, lcp[rnk[i - 1]] - 1);
		  for ( ; r[i + lcp[rnk[i]]] == r[sa[rnk[i] - 1] + lcp[rnk[i]]]; lcp[rnk[i]]++);
	  }
  }
};


int main() {
	
	scanf("%d%s", &n, str);
	LL ans = 0;
	int sum = 0;
	SA::SA(str, sa, n, 256);
	SA::LCP(str, sa, lcp, n);
	nxt[n] = n + 1;
	for (int i = 0; i < n; i++) {
		if (str[i] == '(') sum++;
		else sum--;
		a[i + 1] = sum;
	}
	for (int i = n; i >= 0; i--) {
		int lst = i + 1;
		while (lst <= n && a[lst] >= a[i]) lst = nxt[lst];
		nxt[i] = lst;
		l[a[i] + MAXN].pb(i);
	}
	for (int i = 0; i < 2 * MAXN; i++) if (l[i].size() > 0) {
		reverse(all(l[i]));
	}
	for (int i = 0; i < n; i++) {
		int v = sa[i];
		int lst = nxt[v] - 1;
		int fst = v + lcp[i] + 1;
		if (fst > lst) continue;
		ans += upper_bound(all(l[a[v] + MAXN]), lst) - 
					 lower_bound(all(l[a[v] + MAXN]), fst);
	}
	cout << ans << endl;
	return 0;
}