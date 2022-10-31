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

const int MAXN = 222222;

#define yn __adfs

set<int> S;
vector<int> V[MAXN];

int xn, yn, first;
int x[MAXN], y[MAXN], yy[MAXN], xx[MAXN], prev[MAXN], next[MAXN], cnt[MAXN];
long long ans[MAXN];

void add(int y, int t) {
	int p = lower_bound(yy, yy+yn, y) - yy;
	if (!cnt[p]) {
		set<int> :: iterator it = S.upper_bound(p);
		if (it != S.end()) {
			next[p] = *it;
			prev[*it] = p;
		} else {
			next[p] = -1;
		}
		if (it != S.begin()) {
			--it; prev[p] = *it;
			next[*it] = p;
		} else {
			first = p;
			prev[p] = -1;
		}
		S.insert(p);
	}
	cnt[p] += t;
	if (!cnt[p]) {
		int x = prev[p], y = next[p];
		S.erase(p);
		if (x != -1) {
			next[x] = y;
		} else {
			first = y;
		}
		if (y != -1) {
			prev[y] = x;
		}
	}
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		xx[xn++] = x[i], xx[xn++] = x[i]+m, yy[yn++] = y[i], yy[yn++] = y[i]+m;
	}
	sort(xx, xx + xn);
	sort(yy, yy + yn);
	xn = unique(xx, xx + xn) - xx;
	yn = unique(yy, yy + yn) - yy;
	for (int i = 0; i < n; i++) {
		V[lower_bound(xx, xx+xn, x[i]) - xx].push_back(i);
		V[lower_bound(xx, xx+xn, x[i]+m) - xx].push_back(~i);
	}
	memset(prev, -1, sizeof prev);
	memset(next, -1, sizeof next);
	for (int i = 0; i < xn-1; i++) {
		for (int k = 0; k < sz(V[i]); k++) {
			int l = V[i][k];
			if (l >= 0) {
				add(y[l], 1), add(y[l]+m, -1);
			} else {
				add(y[~l], -1), add(y[~l]+m, 1);
			}
		}
		if (S.empty()) {
			continue;
		}
		int dx = xx[i+1] - xx[i];
		for (int u = next[first], w = 0; ~u; u = next[u]) {
			int v = prev[u]; w += cnt[v];
			ans[w] += (LL)(yy[u]-yy[v])*dx;
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%lld%c", ans[i], i<n ? ' ' : '\n');
	}
	return 0;
}