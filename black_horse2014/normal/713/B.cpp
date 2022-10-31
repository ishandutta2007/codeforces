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

struct Data {
	int x1, y1, x2, y2;
	Data(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1), y1(y1), x2(x2), y2(y2) {}
} ans[2];

int query(int x1, int x2, int y1, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

Data find(int sx, int ex, int sy, int ey) {
	int lo, hi;
	lo = sx-1, hi = ex;
	Data ret;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (query(sx, mid, sy, ey) > 0) hi = mid;
		else lo = mid;
	}
	ret.x2 = hi;
	hi++, lo = sx;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (query(mid, ret.x2, sy, ey) > 0) lo = mid;
		else hi = mid;
	}
	ret.x1 = lo;
	lo = sy-1, hi = ey;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (query(ret.x1, ret.x2, sy, mid) > 0) hi = mid;
		else lo = mid;
	}
	ret.y2 = hi;
	hi++, lo = sy;
	while (hi - lo > 1) {
		int mid = lo + hi >> 1;
		if (query(ret.x1, ret.x2, mid, ret.y2) > 0) lo = mid;
		else hi = mid;
	}
	ret.y1 = lo;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	ans[0] = find(1, n, 1, n);
	int x1 = ans[0].x1, x2 = ans[0].x2, y1 = ans[0].y1, y2 = ans[0].y2;
	if (x1 > 1 && query(1, x1-1, 1, n)) {
		ans[1] = find(1, x1-1, 1, n);
	} else if (x2 < n && query(x2+1, n, 1, n)) {
		ans[1] = find(x2+1, n, 1, n);
	} else if (y1 > 1 && query(1, n, 1, y1-1)) {
		ans[1] = find(1, n, 1, y1-1);
	} else {
		ans[1] = find(1, n, y2+1, n);
	}
	putchar('!');
	for (int i = 0; i < 2; i++) printf(" %d %d %d %d", ans[i].x1, ans[i].y1, ans[i].x2, ans[i].y2);
	puts("");
	return 0;
}