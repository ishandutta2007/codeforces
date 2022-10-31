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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

int _b[111][111], M;
void matbox(int a[111][111], int b[111][111]) {
	
	int c[111][111] = {0};
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) 
			for (int k = 0; k < M; k++) c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) a[i][j] = c[i][j];
}

void matpow(int n, int a[111][111]) {
	if (!n) {
		
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++) a[i][j] = int(i == j);
		return;
	}
	
	matpow(n / 2, a);
	matbox(a, a);
	if (n & 1) matbox(a, _b);
}

int a[MAXN], f[MAXN], s[MAXN], c[MAXN], d[MAXN], cnt[MAXN];
int N, L, dp[111][111];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d%d", &N, &L, &M);
	for (int i = 0; i < N; i++) scanf("%d", f + i);
	for (int i = 0; i < N; i++) scanf("%d", a + i);
	for (int i = 0; i < N; i++) scanf("%d", s + i);
	for (int i = 0; i < N; i++) cnt[a[i] % M]++;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++) _b[i][j] = cnt[(i - j + M) % M];
	int A[111][111];	
	matpow(L - 2, A);
	
	for (int i = 0; i < N; i++) c[f[i] % M]++;
	for (int i = 0; i < M; i++) 
		for (int j = 0; j < M; j++) {
			d[i] = (d[i] + 1LL * c[j] * A[i][j]) % MOD;
		}
	int ans = 0;
	for (int i = 0; i < N; i++) ans = (ans + d[(M + M - s[i] - a[i]) % M]) % MOD;
	printf("%d\n", ans);		
	return 0;
}