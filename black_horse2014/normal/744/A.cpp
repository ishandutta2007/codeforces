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

int sz[MAXN], a[MAXN], f[MAXN];
int chk[MAXN];

int get(int u) {
	return f[u] == 0 ? u : f[u] = get(f[u]);
}

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) sz[i] = 1;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		u = get(u), v = get(v);
		if (u != v) f[u] = v, sz[v] += sz[u], sz[u] = 0;
	}
	int ans = 0;
	int tot = 0, msz = 0;
	for (int i = 1; i <= p; i++) chk[get(a[i])] = 1;
	for (int i = 1; i <= n; i++) {
		if (sz[i] && !chk[i]) {
			ans += sz[i];
		} else if (sz[i]) {
			tot += sz[i] * (sz[i] - 1) / 2;
			chkmax(msz, sz[i]);
		}
	}
	ans = ans * msz + ans * (ans - 1) / 2 - m + tot;
	cout << ans << endl;
	return 0;
}