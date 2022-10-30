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

const int MAXN = 111111;

int N, M, MOD;
int f[MAXN], sz[MAXN];

int get(int x) {
	return f[x] == 0 ? x : f[x] = get(f[x]);
}

int main() {
	
	cin >> N >> M >> MOD;
	for (int i = 1; i <= N; i++) f[i] = 0, sz[i] = 1;
	int cnt = N;
	for (int i = 0; i < M; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u = get(u), v = get(v);
		if (u != v) f[u] = v, cnt--, sz[v] += sz[u], sz[u] = 0;
	}
	if (cnt == 1) {
		if (MOD > 1) puts("1");
		else puts("0");
		return 0;
	}
	int ans = 1;
	for (int i = 1; i <= cnt-2; i++) ans = 1LL*ans*N % MOD;
	for (int i = 1; i <= N; i++) if (sz[i]) ans = 1LL*ans*sz[i] % MOD;
	cout << ans%MOD << endl;
	return 0;
}