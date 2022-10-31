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

const int MAXN = 1111;
const int MOD = 1e9 + 7;

char A[MAXN], B[MAXN];
int N;
vector<int> V;

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = 1LL * a * a % p) if (n & 1) ret = 1LL * ret * a % p;
	return ret;
}

int calc(int s, int N, int M) {
	if (s) return 1LL * (modExp(M-1, N, MOD) + (N % 2 == 1 ? 1 : -1)) * modExp(M, MOD-2, MOD) % MOD;
	return 1LL * (modExp(M-1, N, MOD) + (N % 2 == 1 ? MOD-M+1 : M-1)) * modExp(M, MOD-2, MOD) % MOD;
}

int main() {
	
	scanf("%s%s%d", A, B, &N);
	int M = strlen(A), ans = 0;
	for (int i = 0; i < M; i++) {
		bool flg = 1;
		for (int j = 0; flg && j < M; j++) if (B[(i + j) % M] != A[j]) flg = 0;
		if (flg) {
			ans = (ans + calc(i, N, M)) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}