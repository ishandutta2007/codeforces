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
#define mp make_pair

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


const int MAXN = 1e5+5;

vector<PII> adj[MAXN];

vector<LL> Vo[MAXN], V[MAXN], V1[MAXN];
int K, k, n;
LL dpo[MAXN], dp1[MAXN];
void dfs(int u, int p) {
	
	for(int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].X;
		if(v == p) continue;
		dfs(v, u);
		Vo[u].push_back(dpo[v] + adj[u][i].Y);
		V[u].push_back(dpo[v] + adj[u][i].Y);
		V1[u].push_back(dp1[v] + adj[u][i].Y);
	}
	if(adj[u].size() == 1 && u) return;
	sort(all(V[u]));
	int U = min(int(Vo[u].size()), K - 1);
	int vv = min(int(Vo[u].size()), K - 1);
	LL tmp = 0;
	for(int i = 0; i < U; i++) tmp += V[u][V[u].size() - 1 - i];
	for(int i = 0; i < vv; i++) dpo[u] += V[u][V[u].size() - 1 - i];
	for(int i = 0; i < V[u].size(); i++) {
		int id = lower_bound(all(V[u]), Vo[u][i]) - V[u].begin();
		int pid = V[u].size() - 1 - id;
		if(pid < U) {
			chkmax(dp1[u], tmp - V[u][id] + (U == V[u].size() ? 0 : V[u][V[u].size() - U - 1]) + V1[u][i]);
		}
		else chkmax(dp1[u], tmp + V1[u][i]);
	}
	chkmax(dp1[u], dpo[u]);
}
int main() {
	scanf("%d%d", &n, &K);
	for(int i = 1; i < n; i++) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		adj[u].push_back(PII(v, k));
		adj[v].push_back(PII(u, k));
	}
	dfs(0, -1);
	printf("%lld\n", max(dp1[0], dpo[0]));
	return 0;
}