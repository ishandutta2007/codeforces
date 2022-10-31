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

vector<int> adj[MAXN];
vector<int> V[MAXN];
int deg[MAXN];
int chk[MAXN];
int vis[MAXN];
int T;

bool cmp(int u, int v) {
	for (int i = 0; i < sz(adj[u]); i++) {
		if (adj[u][i] != adj[v][i]) return adj[u][i] < adj[v][i];
	}
	return u < v;
}

bool equal(int u, int v) {
	for (int i = 0; i < sz(adj[u]); i++) if (adj[u][i] != adj[v][i]) return 0;
	return 1;
}

int main() {
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v), deg[u]++;
		adj[v].push_back(u), deg[v]++;
	}
	for (int i = 1; i <= n; i++) {
		V[deg[i]].push_back(i), sort(all(adj[i]));
	}
	long long ans = 0;
	for (int i = 0; i <= n; i++) {
		sort(all(V[i]), cmp);
		for (int j = 0, k; j < sz(V[i]); j = k) {
			for (k = j; k < sz(V[i]) && equal(V[i][j], V[i][k]); k++);
			ans += 1LL*(k-j)*(k-j-1)/2;
		}
		V[i].clear();
	}
	for (int i = 1; i <= n; i++) {
		adj[i].push_back(i), deg[i]++, sort(all(adj[i]));
		V[deg[i]].push_back(i);
	}
	for (int i = 0; i <= n; i++) {
		sort(all(V[i]), cmp);
		for (int j = 0, k; j < sz(V[i]); j = k) {
			for (k = j; k < sz(V[i]) && equal(V[i][j], V[i][k]); k++);
			ans += 1LL*(k-j)*(k-j-1)/2;
		}
		V[i].clear();
	}
	cout << ans << endl;
	return 0;
}