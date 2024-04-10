#include <bits/stdc++.h>
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

int m;

const int MAXN = 65536;
const int MOD = 998244353;

int a[3][MAXN], b[3][MAXN];

VI V;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % p) if (n & 1) ret = (LL)ret * a % p;
	return ret;
}

void NTT(int *A, int r) {
	for (int m = MAXN >> 1, n = MAXN; n > 1; n >>= 1, m >>= 1, r = (LL)r * r % MOD) {
		for (int i = 0, q = 1; i < m; q = (LL)q * r % MOD, i++) {
			for (int j = i, k = j + m; j < MAXN; j += n, k += n) {
				int x = A[j] - A[k] + MOD;
				A[j] += A[k]; if (A[j] >= MOD) A[j] -= MOD; 
				A[k] = (LL)x * q % MOD;
			}
		}
	}
	for (int j = 1, i = 0; j < MAXN; j++) {
		for (int k = MAXN >> 1; (i ^= k) < k; k >>= 1);
		if (j < i) swap(A[i], A[j]);
	}
}

int main() {
	int n; cin >> n >> m;
	for (int j = 0; j < 2; j++) for (int i = 0; i < MAXN; i++) a[j][i] = (i <= j);
	if (n == 1) {
		for (int j = 1; j <= m; j++) printf("%d%c", a[1][j], j < m ? ' ' : '\n');
		return 0;
	}
	while (n > 1) V.push_back(n), n = n / 2 - 1;
	int R = modExp(MAXN, MOD-2, MOD);
	n = 0;
	reverse(all(V));
	for (int i = 0; i < V.size(); i++) {
		for (int j = 0; j < MAXN; j++) a[2][j] = (j < MAXN/2 ? (a[1][j] + (j ? (a[1][j-1] + a[0][j-1]) % MOD : 0)) % MOD : 0);
		for (int k = 0; k <= 2; k++) NTT(a[k], modExp(3, MOD/MAXN, MOD));
		for (int k = 0; k < 2; k++) {
			for (int j = 0; j < MAXN; j++) b[k][j] = (LL)a[k][j] * a[k][j] % MOD * R % MOD;
		}
		NTT(b[0], modExp(3, MOD-1-MOD/MAXN, MOD));
		NTT(b[1], modExp(3, MOD-1-MOD/MAXN, MOD));
		for (int j = MAXN-1; j >= 0; j--) b[0][j] = (j < MAXN/2 ? (b[1][j] + (j ? b[0][j-1] : 0)) % MOD : 0);
		for (int k = 1; k <= 2; k++) for (int j = 0; j < MAXN; j++) b[k][j] = (LL)a[k-1][j] * a[k][j] % MOD * R % MOD;
		NTT(b[1], modExp(3, MOD-1-MOD/MAXN, MOD));
		NTT(b[2], modExp(3, MOD-1-MOD/MAXN, MOD));
		for (int j = MAXN-1; j >= 0; j--) b[1][j] = (j < MAXN/2 ? (b[2][j] + (j ? b[1][j-1] : 0)) % MOD : 0);
		memcpy(a[0], b[0], sizeof a[0]);
		memcpy(a[1], b[1], sizeof a[1]);
		n = 2 * n + 2;
		while (n < V[i]) {
			for (int j = 0; j < MAXN; j++) a[2][j] = (j < MAXN/2 ? (a[1][j] + (j ? (a[1][j-1] + a[0][j-1]) % MOD : 0)) % MOD : 0);
			memcpy(a[0], a[1], sizeof a[0]);
			memcpy(a[1], a[2], sizeof a[1]);
			n++;
		}
	}
	for (int j = 1; j <= m; j++) printf("%d%c", a[0][j], j < m ? ' ' : '\n');
	return 0;
}