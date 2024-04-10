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
const double EPS = 1e-8;

struct PT {
	DB x, y;
	PT(DB x = 0, DB y = 0) : x(x), y(y) {}
	void input() {
		scanf("%lf%lf", &x, &y);
	}
	bool operator<(const PT &p) const {
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y < p.y;
	}
	bool operator==(const PT &p) const {
		return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
	}
} P[MAXN];

DB vect(PT p, PT p1, PT p2) {
	return (p1.x - p.x) * (p2.y - p.y) - (p1.y - p.y) * (p2.x - p.x);
}

DB scala(PT p, PT p1, PT p2) {
	return (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);
}

DB dist(PT p1, PT p2) {
	return sqrt(sqr(p2.x - p1.x) + sqr(p2.y - p1.y));
}

DB dist(PT p, PT p1, PT p2) {
	if (scala(p1, p, p2) < -EPS || scala(p2, p, p1) < -EPS) return min(dist(p, p1), dist(p, p2));
	return fabs(vect(p, p1, p2)) / dist(p1, p2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 0; i <= n; i++) scanf("%lf%lf", &P[i].x, &P[i].y);
	P[n + 1] = P[1];
	double dmax = 0, dmin = 1e7;
	for (int i = 1; i <= n; i++) {
		chkmax(dmax, dist(P[0], P[i]));
		chkmin(dmin, dist(P[0], P[i], P[i+1]));
	}
	double PI = acos(-1);
	printf("%.10lf\n", PI * (dmax * dmax - dmin * dmin));
	return 0;
}