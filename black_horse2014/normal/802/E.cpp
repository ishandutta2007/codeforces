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

int a[255];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		double s2 = 0, s1 = 0;
		for (int i = 0, x; i < 250; i++) {
			scanf("%d", &a[i]);
			x = a[i];
			s1 += x, s2 += 1.0 * x * x;
		}
		s1 /= 250, s2 /= 250;
		s2 -= s1 * s1;
		int ans = 10;
		sort(a, a + 250);
		if (s2 > 2 * s1) {
			ans = (a[0] + a[249]) / 2;
		} else {
			double mind = 1e100;
			for (int pro = 10; pro <= 1000; pro++) {
				double dis = 0;
				for (int i = 0; i < 250; i++) dis += 1.0 * (a[i] - pro) * (a[i] - pro);
				dis /= 250;
				if (fabs(dis - pro) < mind) {
					mind = fabs(dis - pro);
					ans = pro;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}