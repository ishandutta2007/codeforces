#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

const int maxn = 2000010;
const int maxc = 100;
int n, k;
char s[maxn];
char t[maxn];
int cnt[maxc][maxc];
int ans[maxc];

#define linf (long long) (1e18 + 5)
#define maxv 10005
#define maxe 100005
int dr[4] = {-1, +1, 0, 0};
int dc[4] = {0, 0, +1, -1};
struct MincostFlow {
	int n, s, t, E, adj[maxe], next[maxe], last[maxv], which[maxv];
	long long totalCost, totalFlow, cap[maxe], flow[maxe], cost[maxe], pot[maxe], dist[maxv];
	void init(int _n, int _s, int _t) {
		n = _n; s = _s; t = _t;
		ms(cap, 0); ms(pot, 0); ms(dist, 0); ms(which, 0);
		ms(last, -1); E = 0;
	}
	void add(int u, int v, long long ca, long long co) {
		adj[E] = v; cap[E] = ca; flow[E] = 0; cost[E] = +co; next[E] = last[u]; last[u] = E++;
		adj[E] = u; cap[E] =  0; flow[E] = 0; cost[E] = -co; next[E] = last[v]; last[v] = E++;
	}
	void bellman() {
		bool stop = false;
		ms(pot, 0);
		while (!stop) {
			stop = true;
			for(int u = 0; u < n; u++) for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				if (pot[v] > pot[u] + cost[e]) {
					pot[v] = pot[u] + cost[e];
					stop = false;
				}
			}
		}
	}
	bool dijkstra() {
		typedef pair<long long, int> node;
		priority_queue<node, vector<node>, greater<node> > que;
		for(int u = 0; u < n; u++) dist[u] = linf;
		dist[s] = 0;
		que.push(make_pair(0, s));
		while (!que.empty()) {
			long long dnow = que.top().first;
			int u = que.top().second;
			que.pop();
			if (dnow > dist[u]) continue;
			for (int e = last[u]; e != -1; e = next[e]) if (flow[e] < cap[e]) {
				int v = adj[e];
				long long dnext = dnow + cost[e] + pot[u] - pot[v];
				if (dist[v] > dnext) {
					dist[v] = dnext;
					which[v] = e;
					que.push(make_pair(dnext, v));
				}
			}
		}
		return dist[t] < linf;
	}
	bool maxflow(long long desireFlow = linf) {
		totalCost = totalFlow = 0;
		bellman();
		while (totalFlow < desireFlow) {
			if (!dijkstra()) return false;
			long long delta = desireFlow - totalFlow;
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v])
				delta = min(delta, cap[e] - flow[e]);
			for (int v = t, e = which[v]; v != s; v = adj[e ^ 1], e = which[v]) {
				flow[e] += delta;
				flow[e ^ 1] -= delta;
			}
			totalFlow += delta;
			totalCost += delta * (dist[t] - pot[s] + pot[t]);
			for (int u = 0; u < n; u++) pot[u] += dist[u];
		}
		return true;
	}
} mcf;

void solve() {
	ms(cnt, 0);
	scanf("%d%d%s%s", &n, &k, s, t);
	FOR(i, 0, n) {
		int u, v;
		if (s[i] < 'a') u = s[i] - 'A' + 26; else u = s[i] - 'a';
		if (t[i] < 'a') v = t[i] - 'A' + 26; else v = t[i] - 'a';
		cnt[u][v]++;
	}
	mcf.init(2 * k + 2, 2 * k, 2 * k + 1);
	FOR(i, 0, k) {
		mcf.add(2 * k, i, 1, 0);
		mcf.add(i + k, 2 * k + 1, 1, 0);
		FOR(j, 0, k) mcf.add(i, j + k, 1, -cnt[i][j]);
	}
	mcf.maxflow();
	printf("%I64d\n", -mcf.totalCost);
	FOR(i, 0, k) {
		for (int e = mcf.last[i]; e != -1; e = mcf.next[e]) if (mcf.flow[e]) {ans[i] = mcf.adj[e] - k; break;}
	}
	FOR(i, 0, k) if (ans[i] < 26) printf("%c", 'a' + ans[i]); else printf("%c", 'A' + ans[i] - 26);
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