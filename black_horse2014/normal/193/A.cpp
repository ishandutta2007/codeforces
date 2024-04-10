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

const int MAXN = 2555;
const int MAXM = 22222;

int T, n, m, tot, cn, bn;
int low[MAXN], chk[MAXN], vis[MAXN], num[MAXN];
int sz[MAXN*2], pr[MAXN*2];
int x[MAXM], c[MAXM], b[MAXM];
vector<int> adj[MAXN];

int ans;

void dfs(int u, int p) {
	low[u] = chk[u] = ++T;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (v == p) continue;
		if (!chk[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= chk[u]) {
				cn++;
			}
		} else {
			low[u] = min(low[u], chk[v]);
		}
	}
	if (!p) cn--;
	if (cn >= 1) {
		ans++;
	}
}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

bool out(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}

char s[55][55];
int id[55][55];

int main() {
	
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", s[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				id[i][j] = ++tot;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '#') {
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (out(nx, ny) || s[nx][ny] == '.') continue;
					adj[id[i][j]].push_back(id[nx][ny]);
				}
			}
		}
	}
	dfs(1, 0);
	if (ans >= 1) {
		puts("1");
	} else {
		if (tot <= 2) {
			puts("-1");
		} else {
			puts("2");
		}
	}
	return 0;
}