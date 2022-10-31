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

const int MAXN = 1111111;

int deg[MAXN], f[MAXN], cnt[MAXN];
int get(int u) {
	return f[u] == 0 ? u : f[u] = get(f[u]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d", &n, &m);
	int tot = n, num = 0, E = 0;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		if (u == v) {
			num++, cnt[u]++;
			continue;
		}
		int x = get(u), y = get(v);
		if (x != y) {
			f[x] = y;
			tot--;
		}
		deg[u]++, deg[v]++;
		E++;
	}
	for (int i = 1; i <= n; i++) {
		if (deg[i] + cnt[i] == 0) tot--;
	}
	if (tot != 1) {
		puts("0");
		return 0;
	}
	long long ans = 1LL * num * (num - 1) / 2;
	for (int i = 1; i <= n; i++) ans += 1LL * deg[i] * (deg[i]-1) / 2;
	ans += 1LL * num * E;
	cout << ans << endl;
	return 0;
}