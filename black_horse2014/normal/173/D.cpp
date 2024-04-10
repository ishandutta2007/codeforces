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

int n, m;

VI adj[MAXN], V[2];
int deg[MAXN], ans[MAXN], A[100], B[100];
int c[MAXN];

void dfs(int u, int flg) {
	c[u] = flg;
	V[c[u]].push_back(u);
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (!~c[v]) dfs(v, flg ^ 1);
	}
}

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++, deg[v]++;
	}
	for (int i = 1; i <= n; i++) sort(all(adj[i]));
	memset(c, -1, sizeof c);
	for (int i = 1; i <= n; i++) if (!~c[i]) dfs(i, 0);
	sort(all(V[0]));
	sort(all(V[1]));
	int cur = 0;
	if (V[0].size() % 3 != 0) {
		int id = (V[0].size() % 3 != 1);
		int u = 0;
		for (int i = 0; i < V[id].size(); i++) {
			if (deg[V[id][i]] + 2 <= V[id^1].size()) {
				u = V[id][i];
				break;
			}
		}
		if (u) {
			A[0] = u;
			for (int i = 0, cnt = 1; cnt < 3 && i < V[id^1].size(); i++) {
				if (!binary_search(all(adj[u]), V[id^1][i])) A[cnt++] = V[id^1][i];
			}
			for (int i = 0; i < 3; i++) {
				ans[A[i]] = 1;
				V[c[A[i]]].erase(lower_bound(all(V[c[A[i]]]), A[i]));
			}
			cur = 1;
		} else {
			id ^= 1;
			int cnt = 0;
			for (int i = 0; cnt < 2 && i < V[id].size(); i++) {
				if (deg[V[id][i]] + 2 <= V[id^1].size()) {
					B[cnt++] = V[id][i];
				}
			}
			if (cnt < 2) {
				puts("NO");
				return 0;
			}
			for (int j = 0; j < 2; j++) {
				int u = B[j];
				A[0] = u;
				for (int i = 0, tot = 1; tot < 3 && i < V[id^1].size(); i++) {
					if (!binary_search(all(adj[u]), V[id^1][i])) A[tot++] = V[id^1][i];
				}
				for (int i = 0; i < 3; i++) {
					ans[A[i]] = j + 1;
					V[c[A[i]]].erase(lower_bound(all(V[c[A[i]]]), A[i]));
				}
			}
			cur = 2;
		}
	}
	if (V[0].size() % 3 == 0) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < V[i].size(); j += 3) {
				cur++, ans[V[i][j]] = ans[V[i][j+1]] = ans[V[i][j+2]] = cur;
			}
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i < n ? ' ' : '\n');
	}
	return 0;
}