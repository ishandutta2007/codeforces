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

const double INF = 1e9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, sx, sy, ex, ey; scanf("%d", &n);
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	double L = 0, R = INF;
	for (int i = 0; i < n; i++) {
		int x, y, vx, vy; scanf("%d%d%d%d", &x, &y, &vx, &vy);
		if (vx == 0) {
			if (!(x > sx && x < ex)) chkmax(L, INF), chkmin(R, 0);
		} else {
			double t1 = 1.0 * (sx - x) / vx, t2 = 1.0 * (ex - x) / vx;
			if (t1 > t2) swap(t1, t2);
			chkmax(L, t1), chkmin(R, t2);
		}
		if (vy == 0) {
			if (!(y > sy && y < ey)) chkmax(L, INF), chkmin(R, 0);
		} else {
			double t1 = 1.0 * (sy - y) / vy, t2 = 1.0 * (ey - y) / vy;
			if (t1 > t2) swap(t1, t2);
			chkmax(L, t1), chkmin(R, t2);
		}
	}
	if (L > R - 1e-10) {
		puts("-1");
		return 0;
	}
	printf("%.10lf\n", L);
	return 0;
}