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

const int MAXN = 222222;
const int MOD = 1e9 + 7;

int f[MAXN], g[MAXN], r[MAXN];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % p) if (n & 1) ret = (LL)ret * a % p;
	return ret;
}

int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1LL * f[n] * g[m] % MOD * g[n - m] % MOD;
}

long long solve(int N, int M, int H) {
	long long ret = 0;
	for (int i = 1; i <= M && (H+1) * i <= M; i++) {
		ret = (ret + (LL)C(M - H * i - 1, i - 1) * C(N, i)) % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	f[0] = f[1] = g[0] = g[1] = r[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		r[i] = (LL)(MOD - r[MOD % i]) * (MOD / i) % MOD;
		f[i] = (LL)f[i-1] * i % MOD;
		g[i] = (LL)g[i-1] * r[i] % MOD;
	}
	int F, W, H; scanf("%d%d%d", &F, &W, &H);
	if (H == 0 || W == 0) {
		puts("1");
		return 0;
	}
	if (F == 0) {
		if (W > H) puts("1");
		else puts("0");
		return 0;
	}
	long long p = solve(F+1, W, H);
	long long q = modExp(C(W+F, W), MOD-2, MOD);
	cout << p * q % MOD << endl;
	return 0;
}