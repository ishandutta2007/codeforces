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

const int MAXN = 1<<20;

double x[MAXN], y[MAXN];
int a[MAXN];

double c[360], s[360];

void build(int u, int l, int r) {
	x[u] = r - l + 1, y[u] = 0, a[u] = 0;
	if (l == r) return;
	int mid = l + r >> 1;
	build(u + u, l, mid);
	build(u + u + 1, mid + 1, r);
}

void up(int u) {
	x[u] = x[u + u] + x[u + u + 1];
	y[u] = y[u + u] + y[u + u + 1];
}

void renew(int u, int p) {
	a[u] = (a[u] + p) % 360;
	double nx = x[u] * c[p] + y[u] * s[p];
	double ny = -x[u] * s[p] + y[u] * c[p];
	x[u] = nx, y[u] = ny;
}

void down(int u) {
	if (a[u]) {
		renew(u + u, a[u]);
		renew(u + u + 1, a[u]);
		a[u] = 0;
	}
}

void update(int u, int l, int r, int p, int phi) {
	if (p <= l) {
		renew(u, phi);
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (p <= mid) update(u + u, l, mid, p, phi);
	update(u + u + 1, mid + 1, r, p, phi);
	up(u);
}

void add(int u, int l, int r, int p, double z) {
	if (l == r) {
		double d = sqrt(sqr(x[u]) + sqr(y[u]));
		x[u] *= (d + z) / d, y[u] *= (d + z) / d;
		return;
	}
	down(u);
	int mid = l + r >> 1;
	if (p <= mid) add(u + u, l, mid, p, z);
	else add(u + u + 1, mid + 1, r, p, z);
	up(u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	double PI = acos(-1);
	for (int i = 0; i < 360; i++) c[i] = cos(i * PI / 180), s[i] = sin(i * PI / 180);
	build(1, 1, n);
	while (m--) {
		int t, p, z; scanf("%d%d%d", &t, &p, &z);
		if (t == 1) add(1, 1, n, p, z);
		else update(1, 1, n, p, z);
		printf("%.10lf %.10lf\n", x[1], y[1]);
	}
	return 0;
}