#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
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

const int MAXN = 111111;
int cnt[2];
int a[MAXN], sz[MAXN], b[MAXN], c[MAXN], f[MAXN], vis[MAXN], ret[MAXN], chk[MAXN];
VI V;
VI adj[MAXN];

bool dfs(int u, int cc) {
	chk[u] = 1, vis[u] = cc, cnt[cc] += sz[u];
	V.push_back(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (chk[v]) {
			if (vis[v] == cc) {
				return 0;
			}
		} else {
			if (!dfs(v, cc ^ 1)) return 0;
		}
	}
	return 1;
}

int get(int u) {
	return f[u] == 0 ? u : f[u] = get(f[u]);
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		char s[5]; int u, v;
		scanf("%d%d%s", &u, &v, s);
		a[i] = u, b[i] = v, c[i] = (s[0] == 'R');
	}
	int ans = n+1;
	for (int i = 0; i < 2; i++) {
		memset(f, 0, sizeof f);
		for (int j = 1; j <= n; j++) sz[j] = 1;
		for (int j = 0; j < m; j++) {
			int u = a[j], v = b[j];
			if (c[j] == i) {
				u = get(u), v = get(v);
				if (u != v) {
					f[u] = v;
					sz[v] += sz[u];
					sz[u] = 0;
				}
			}
		}
		for (int j = 1; j <= n; j++) adj[j].clear();
		int flg = 1;
		for (int j = 0; j < m && flg; j++) {
			int u = get(a[j]), v = get(b[j]);
			if (c[j] != i) {
				if (u == v) {
					flg = 0;
					break;
				}
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		memset(chk, 0, sizeof chk);
		memset(vis, 0, sizeof vis);
		int sum = 0;
		for (int j = 1; j <= n && flg; j++) {
			if (get(j) == j && !chk[j]) {
				cnt[0] = cnt[1] = 0;
				V.clear();
				if (!dfs(j, 0)) {
					flg = 0;
					break;
				}
				if (cnt[0] < cnt[1]) {
					for (int j = 0; j < sz(V); j++) {
						vis[V[j]] ^= 1;
					}
				}
				sum += min(cnt[0], cnt[1]);
			}
		}
		if (!flg) {
			continue;
		}
		if (sum < ans) {
			for (int i = 1; i <= n; i++) {
				ret[i] = vis[get(i)];
			}
			ans = sum;
		}
	}
	if (ans > n) {
		puts("-1");
		return 0;
	}
	printf("%d\n", ans);
	int flg = 0;
	for (int i = 1; i <= n; i++) {
		if (ret[i]) {
			if (flg++) putchar(' ');
			printf("%d", i);
		}
	}
	puts("");
	return 0;
}