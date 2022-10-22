#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int T = 1 << 20;
const int N = 5e5 + 500;

int n, q, a, b, c;
pair<int, int> e[N];
vector <pair<int, int>> G[N];

pair<int, int> farest(int v = 1, int p = 0) {
	pair<int, int> mx = {0, v};
	for (auto [u, w] : G[v])
		if (u != p) {
			auto cur = farest(u, v);
			cur.fi++;
			mx = max(mx, cur);
		}
	return mx;
}

struct tree {
	struct node {
		int x, y, flag;
	} s[T + T];
	
	node combine(node a, node b) {
		return {max(a.x, b.x), max(a.y, b.y)};
	}

	void change(int v) {
		s[v].flag ^= 1;
		swap(s[v].x, s[v].y);
	}

	void push(int v) {
		if (!s[v].flag) return;
		for (auto u : {2 * v, 2 * v + 1}) 
			change(u);
		s[v].flag = 0;
	}

	void modify(int x, int y, int v = 1, int l = 1, int r = n) {
		if (y < l || r < x) return;
		if (x <= l && r <= y) {
			change(v);
			return;
		}
		push(v);
		int m = l + r >> 1;
		modify(x, y, 2 * v, l, m);
		modify(x, y, 2 * v + 1, m + 1, r);
		s[v] = combine(s[2 * v], s[2 * v + 1]);
	}
	
	int par[N], dis[N], time, in[N], out[N], ord[N];
	
	void dfs(int v, int p = -1) {
		in[v] = ++time;
		ord[time] = v;
		for (auto [u, w] : G[v]) {
			if (u != p) {
				dis[u] = dis[v] + 1;
				par[u] = par[v] ^ w;
				dfs(u, v);
			}
		}
		out[v] = time;
	}
	
	void build(int v = 1, int l = 1, int r = n) {
		if (l == r) {
			int u = ord[l];
			if (par[u] % 2 == 0)
				s[v].x = dis[u];
			else
				s[v].y = dis[u];
			return;
		}
		int m = l + r >> 1;
		build(2 * v, l, m);
		build(2 * v + 1, m + 1, r);
		s[v] = combine(s[2 * v], s[2 * v + 1]);
	}
	
	void flip(int u, int v) {
		if (dis[u] > dis[v])
			swap(u, v);
		modify(in[v], out[v]);
	}
} D[2];

int main() {
	scanf ("%d", &n);
	rep(i, 1, n - 1) {
		scanf ("%d%d%d", &a, &b, &c);
		e[i] = {a, b};
		G[a].pb({b, c});
		G[b].pb({a, c});
	}
	
	int x = farest().se;
	int y = farest(x).se;

	D[0].dfs(x);
	D[1].dfs(y);
	D[0].build();
	D[1].build();
	
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &a);
		rep(i, 0, 1)
			D[i].flip(e[a].fi, e[a].se);
		printf ("%d\n", max(D[0].s[1].x, D[1].s[1].x));
	} 
	
	return 0;
}