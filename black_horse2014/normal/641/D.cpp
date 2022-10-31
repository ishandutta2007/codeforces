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

long double a[111111], b[111111], x[111111], y[111111];
const long double eps = 1e-13;

long double fab(long double a) {
	if (a < 0) return -a;
	return a;	
}

int main() {
	
	int n;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double xx;
		scanf("%lf", &xx);
		x[i] = (long double)xx;
	}
	for (int i = 0; i < n; i++) {
		double yy;
		scanf("%lf", &yy);
		y[i] = (long double)yy;
	}
	long double sa = 0, sb = 0, s, t, p, q;
	for (int i = 0; i < n; i++) {
		s = x[i] + sa * sb;
		t = sa + sb + x[i] + y[i];
		long double ss = 0;
		if (fab(sqr(t) - s * 4) < eps) ss = 0;
		else ss = sqrt(fab(sqr(t) - s * 4));
		p = fab(t + ss) / 2;
		q = fab(t - ss) / 2;
		if (sa < sb) swap(p, q);
		a[i] = fab(p - sa), b[i] = fab(q - sb);
		sa = p, sb = q;
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 1) printf("%.15lf ", (double)a[i]);
		else printf("%.15lf\n", (double)a[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 1) printf("%.15lf ", (double)b[i]);
		else printf("%.15lf\n", (double)b[i]);
	}
	return 0;
}