#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
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

const int maxn = 110;
int n, m;
int a[maxn];
bool adj[maxn][maxn];
vi v[maxn];
map<pair<int, int>, int> mp;

void run(int k) {
	int m = a[k];
	for (ll i = 2; i * i <= m; i++) {
		if (m % i == 0) v[k].push_back(i);
		while (m % i == 0) {
			mp[make_pair(k, i)]++; m /= i;
		}
	}
	if (m > 1) {
		v[k].push_back(m);
		mp[make_pair(k, m)]++;
	}
}

void solve() {
	ms(adj, 0);
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {scanf("%d", a + i); run(i);}
	FOR(i, 0, m) {int x, y; scanf("%d%d", &x, &y); x--; y--; adj[x][y] = adj[y][x] = 1;}
	dinic.init(20 * n + 2, 20 * n, 20 * n + 1);
	FOR(i, 0, n) {
		FOR(j, 0, sz(v[i])) {
			int k = v[i][j];
			if (i % 2 == 0) dinic.add(20 * n, 20 * i + j, mp[make_pair(i, k)], 0);
			else dinic.add(20 * i + j, 20 * n + 1, mp[make_pair(i, k)], 0);
		}
	}
	for (int i = 0; i < n; i += 2) for (int j = 1; j < n; j += 2) if (adj[i][j]) {
		FOR(p, 0, sz(v[i])) FOR(q, 0, sz(v[j])) {
			int x = v[i][p], y = v[j][q];
			if (x == y) dinic.add(i * 20 + p, j * 20 + q, INT_MAX, 0);
		}
	}
	printf("%d", dinic.maxflow());
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}