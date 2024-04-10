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
const int MAXN = 111111;

VPII adj[MAXN];
int A[MAXN], B[MAXN];

int modExp(int a, int n, int p) {
	int ret = 1;
	for (; n; n >>= 1, a = (LL)a * a % p) if (n & 1) ret = (LL)ret * a % p;
	return ret; 
}

void dfs(int u, int p) {
	int chd = 0;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i].first, w = adj[u][i].second;
		B[u] = (B[u] + w) % MOD;
		if (v == p) continue;
		chd++;
		dfs(v, u);
		A[u] = (A[u] + A[v]) % MOD, B[u] = (B[u] + B[v]) % MOD;
	}
	if (chd == 0) {
		A[u] = B[u] = 0;
		return;
	}
	int cur = (sz(adj[u]) + MOD - A[u]) % MOD;
	A[u] = modExp(cur, MOD-2, MOD);
	B[u] = (LL)A[u] * B[u] % MOD;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back(PII(v, w));
		adj[v].push_back(PII(u, w));
	}
	dfs(0, -1);
	cout << B[0] << endl;
	return 0;
}