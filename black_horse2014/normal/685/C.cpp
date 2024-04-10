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

const int MAXN = 111111;
const long long INF = 3000000000000000001LL;

long long a[4], b[4], c[4], s[4], e[4];

bool check(long long d) {
	for (int i = 0; i < 4; i++) {
		if (a[i]-d > b[i]+d) return 0;
	}
	for (int j = 0; j < 2; j++) {
		bool flg = 1;
		long long _s = 0, _e = 0;
		for (int i = 0; i < 4; i++) {
			s[i] = a[i]-d;
			if ((s[i] + j) % 2 != 0) {
				s[i]++;
			}
			e[i] = b[i]+d;
			if ((e[i] + j) % 2 != 0) {
				e[i]--;
			}
			if (s[i] > e[i]) {
				flg = 0;
				break;
			}
			if (i > 0) {
				_s += s[i];
				_e += e[i];
			}
		}
		if (_s > e[0] || _e < s[0]) {
			flg = 0;
		}
		if (flg) {
			return 1;
		}
	}
	return 0;
}

void solve(long long d) {
	for (int j = 0; j < 2; j++) {
		bool flg = 1;
		long long _s = 0, _e = 0;
		for (int i = 0; i < 4; i++) {
			s[i] = a[i]-d;
			if ((s[i] + j) % 2 != 0) {
				s[i]++;
			}
			e[i] = b[i]+d;
			if ((e[i] + j) % 2 != 0) {
				e[i]--;
			}
			if (s[i] > e[i]) {
				flg = 0;
				break;
			}
			if (i > 0) {
				_s += s[i];
				_e += e[i];
			}
		}
		if (_s > e[0] || _e < s[0]) {
			flg = 0;
		}
		if (!flg) {
			continue;
		}
		c[0] = max(_s, s[0]);
		long long t = c[0] - _s;
		for (int i = 1; i < 4; i++) {
			if (e[i] - s[i] > t) {
				c[i] = s[i] + t;
				t = 0;
			} else {
				c[i] = e[i];
				t -= e[i] - s[i];
			}
		}
		long long x = (c[0]-c[1])/2, y = (c[0]-c[2])/2, z = (c[0]-c[3])/2;
//		long long dd[4];
//		dd[0] = x+y+z, dd[1] = -x+y+z, dd[2] = x-y+z, dd[3] = x+y-z;
//		for (int i = 0; i < 4; i++) {
//			assert(a[i]-d <= dd[i] && dd[i] <= b[i]+d);
//		}
		printf("%lld %lld %lld\n", x, y, z);
		return;
	}
}
int n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		scanf("%d", &n);
		for (int i = 0; i < 4; i++) {
			a[i] = -INF;
			b[i] = INF;
		}
		for (int i = 1; i <= n; i++) {
			long long x, y, z;
			scanf("%lld%lld%lld", &x, &y, &z);
			chkmax(a[0], x+y+z), chkmin(b[0], x+y+z);
			chkmax(a[1], -x+y+z), chkmin(b[1], -x+y+z);
			chkmax(a[2], x-y+z), chkmin(b[2], x-y+z);
			chkmax(a[3], x+y-z), chkmin(b[3], x+y-z);
		}
		long long lo = -1, hi = INF;
		while (hi - lo > 1) {
			long long mid = lo + hi >> 1;
			if (check(mid)) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		solve(hi);
	}
	return 0;
}