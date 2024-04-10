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

const int MAXN = 1111;

struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
}P[MAXN];

double dist(Point p1, Point p2) {
	return sqrt(sqr(p1.x-p2.x) + sqr(p1.y-p2.y));
}

double scala(Point p, Point p1, Point p2) {
	return (p1.x-p.x)*(p2.x-p.x) + (p1.y-p.y)*(p2.y-p.y);
}

double cross(Point p, Point p1, Point p2) {
	return (p1.x-p.x)*(p2.y-p.y) - (p1.y-p.y)*(p2.x-p.x);
}

double dist_to_seg(Point A, Point B, Point C) {
	return fabs(cross(A, B, C)) / dist(B, C);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
	double hi = 1e10;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) chkmin(hi, dist(P[i], P[j]) / 2);
	}
	P[n+1] = P[1], P[0] = P[n];
	for (int i = 1; i <= n; i++) {
		chkmin(hi, dist_to_seg(P[i], P[i-1], P[i+1]) / 2);
	}
	printf("%.10lf\n", hi);
	return 0;
}