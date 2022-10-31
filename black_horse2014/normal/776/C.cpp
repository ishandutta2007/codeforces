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

map<long long, int> H;
long long pw[60];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	int mxe = 0; long long cur = 1;
	while (mxe <= 50 && abs(cur) <= (LL)1e15) pw[mxe] = cur, cur *= m, mxe++;
	long long ans = 0; long long sum = 0;
	H[0] = 1;
	if (m == 1) mxe = 1;
	if (m == -1) mxe = 2;
	for (int i = 1; i <= n; i++) {
		long long x; scanf("%lld", &x);
		sum += x;
		for (int j = 0; j < mxe; j++) {
			if (H.count(sum - pw[j])) ans += H[sum - pw[j]];
		}
		H[sum]++;
	}
	cout << ans << endl;
	return 0;
}