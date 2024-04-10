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

int a[111][111];
PII val[111][111];

int main() {

	int n, m, q;
	int t, r, c, v;
	PII p;
	
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) val[i][j] = PII(i, j);
	}
	for (int i = 0; i < q; i++) {
		scanf("%d", &t);
		if (t == 1) {
			scanf("%d", &r);
			r--;
			p = val[r][0];
			for (int j = 1; j < m; j++) {
				val[r][j - 1] = val[r][j];
			}
			val[r][m - 1] = p;
		}
		else if (t == 2) {
			scanf("%d", &c);
			c--;
			p = val[0][c];
			for (int j = 1; j < n; j++) {
				val[j - 1][c] = val[j][c];
			}
			val[n - 1][c] = p;
		}
		else {
			scanf("%d%d%d", &r, &c, &v);
			r--, c--;
			int x = val[r][c].first, y = val[r][c].second;
			a[x][y] = v;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j != m - 1) printf("%d ", a[i][j]);
			else printf("%d\n", a[i][j]);
		}
	}
	return 0;
}