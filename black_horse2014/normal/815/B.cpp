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

const int MOD = 1e9 + 7;

int a[222222], b[222222], r[222222];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	if (n == 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	if (n & 1) {
		for (int i = 1; i < n; i++) b[i] = ((i & 1) ? a[i] + a[i+1] : a[i] - a[i+1]);
		n--;
		for (int i = 1; i <= n; i++) a[i] = (b[i] % MOD + MOD) % MOD;
	}
	int cur = 1;
	for (int i = 1; i <= n; i++) r[i] = modExp(i, MOD-2, MOD);
	int x = 0, y = 0;
	for (int i = 1; i <= n/2; i++) {
		x = (x + 1LL * a[2*i-1] * cur) % MOD;
		y = (y + 1LL * a[2*i] * cur) % MOD;
		cur = 1LL * cur * (n / 2 - i) % MOD * r[i] % MOD;
	}
	if (n % 4 == 0) {
		printf("%d\n", (x - y + MOD) % MOD);
	} else {
		printf("%d\n", (x + y) % MOD);
	}
	return 0;
}