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

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		int x, y, p, q; scanf("%d%d%d%d", &x, &y, &p, &q);
		if (p == 0 && x) {
			puts("-1");
			continue;
		}
		long long lo = (y-1+q)/q-1, hi = 1<<30;
		while (hi - lo > 1) {
			long long mid = (lo + hi) / 2;
			long long L = x, R = x + mid * q - y, N = mid * q;
			if (L <= p * mid && R >= p * mid) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		if (hi == (1<<30)) {
			puts("-1");
			continue;
		}
		printf("%lld\n", hi * q - y);
	}
	return 0;
}