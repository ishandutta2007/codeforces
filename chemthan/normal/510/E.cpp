#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

#define inf 1000000005
#define maxe 150005
#define maxv 50005
struct Dinic {
	int n, s, t, E, adj[maxe], flow[maxe], cap[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv];

	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t; E = 0;
		for (int i = 0; i <= n; ++i) last[i] = -1;
	}

	void add(int u, int v, int c1, int c2) {
		adj[E] = v; flow[E] = 0; cap[E] = c1; next[E] = last[u]; last[u] = E++;
		adj[E] = u; flow[E] = 0; cap[E] = c2; next[E] = last[v]; last[v] = E++;
	}

	bool bfs() {
		for (int i = 0; i <= n; ++i) level[i] = -1;
		level[s] = 0;

		int qsize = 0;
		que[qsize++] = s;

		for (int i = 0; i < qsize; i++) {
			for (int u = que[i], e = last[u]; e != -1; e = next[e]) {
				int v = adj[e];
				if (flow[e] < cap[e] && level[v] == -1) {
					level[v] = level[u] + 1;
					que[qsize++] = v;
				}
			}
		}

		return level[t] != -1;
	}

	int dfs(int u, int bot) {
		if (u == t) return bot;
		for (int &e = run[u]; e != -1; e = next[e]) {
			int v = adj[e], delta = 0;
			if (level[v] == level[u] + 1 && flow[e] < cap[e] && (delta = dfs(v, min(bot, cap[e] - flow[e]))) > 0) {
				flow[e] += delta; flow[e ^ 1] -= delta;
				return delta;
			}
		}
		return 0;
	}

	int maxflow() {
		int total = 0;
		while (bfs()) {
			for (int i = 0; i <= n; ++i) run[i] = last[i];
			for (int delta = dfs(s, inf); delta > 0; delta = dfs(s, inf)) total += delta;
		}
		return total;
	}
} dinic;

const int maxn = 210;
int n;
int a[maxn];
bool vis[maxn];
vi ans[maxn];

bool isprime(int n) {
	for (int i = 2; i * i <= n; i++) if (n % i == 0) return 0;
	return 1;
}

void dfs(int u, int cnt) {
	vis[u] = 1;
	ans[cnt].push_back(u);
	for (int e = dinic.last[u]; e != -1; e = dinic.next[e]) {
		int v = dinic.adj[e];
		if (!vis[v] && (dinic.flow[e] + dinic.cap[e]) % 2 != a[u] % 2 && v < n) dfs(v, cnt);
	}
}

void solve() {
	ms(vis, 0);
	scanf("%d", &n);
	FOR(i, 0, n) scanf("%d", a + i);
	dinic.init(n + 2, n, n + 1);
	FOR(i, 0, n) if (a[i] & 1) dinic.add(n, i, 2, 2); else dinic.add(i, n + 1, 2, 2);
	FOR(i, 0, n) FOR(j, i + 1, n) if (isprime(a[i] + a[j])) {if (a[i] & 1) dinic.add(i, j, 1, 0); else dinic.add(j, i, 1, 0);}
	if (dinic.maxflow() != n) {printf("Impossible"); return;}
	int cnt = 0; FOR(i, 0, n) if (!vis[i]) dfs(i, cnt++);
	printf("%d\n", cnt);
	FOR(i, 0, cnt) {
		printf("%d ", sz(ans[i]));
		FOR(j, 0, sz(ans[i])) printf("%d ", ans[i][j] + 1);
		printf("\n");
	}
}

int main() {
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}