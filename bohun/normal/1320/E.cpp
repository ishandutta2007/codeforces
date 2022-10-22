#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ss(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, l, r) for (int i = r; l <= i; --i)

using ll = long long;
using namespace std;

//
const int N = 4e5 + 100;
const int LOG = 18;

int n, in[N], out[N], siz[N], dep[N], jj[N][LOG];
vector <int> G[N];

int dfs(int v, int p) {
	jj[v][0] = p;
	rep(i, 1, LOG - 1) jj[v][i] = jj[jj[v][i - 1]][i - 1];
	in[v] = ++*in;
	dep[v] = dep[p] + 1;
	siz[v] = 1;
	for (auto u : G[v])
		if (u != p)
			siz[v] += dfs(u, v);
	out[v] = *in;
	return siz[v];
}

int ispar(int a, int b) {
	return in[a] <= in[b] && in[b] <= out[a];
}

int lca(int a, int b) {
	per(i, 0, LOG - 1)
		if (!ispar(jj[a][i], b))
			a = jj[a][i];
	return jj[a][0];
}
//

int spe[N], sta[N], qw[N], nodes[N], vis[N];
vector <int> graf[N];

struct gao {
	int v, id, czas;
	bool operator < (gao p) const {
		auto sufit = [](int a, int b) {
			return (a + b - 1) / b;
		};
		int a = sufit(czas, spe[id]), b = sufit(p.czas, spe[p.id]);
		if (a != b) return a > b;
		return id > p.id;
	}
};
gao dd[N];

void sortuj(int *a, int &sz) {
	sort(a + 1, a + sz + 1, [&](int a, int b) {
		return in[a] < in[b];
	});
	sz = unique(a + 1, a + sz + 1) - a - 1;
}	

void solve() {
	*nodes = 0;
	int k, m;
	scanf ("%d%d", &k, &m);
	rep(i, 1, k) {
		scanf ("%d%d", sta + i, spe + i);
		nodes[++*nodes] = sta[i];
	}
	rep(i, 1, m) {
		scanf ("%d", qw + i);
		nodes[++*nodes] = qw[i];
	}
	sortuj(nodes, *nodes);
	int sz = *nodes;
	rep(i, 1, sz - 1)
		nodes[++*nodes] = lca(nodes[i], nodes[i + 1]);
	sortuj(nodes, *nodes);
	
	vector <int> s = {nodes[1]};
	rep(i, 2, *nodes) {
		while (!ispar(s.back(), nodes[i])) s.pop_back();
		graf[s.back()].pb(nodes[i]);
		graf[nodes[i]].pb(s.back());
		s.pb(nodes[i]);
	}
	
	priority_queue <gao> qq;
	rep(i, 1, *nodes)
		dd[nodes[i]] = {0, 0, (int)1e9};
	rep(i, 1, k) {
		dd[sta[i]] = {sta[i], i, 0};
		qq.push(dd[sta[i]]);
	}
		
	while (!qq.empty()) {
		int v = qq.top().v;
		qq.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (auto u : graf[v]) {
			int dis = abs(dep[v] - dep[u]) + dd[v].czas;
			gao nw = {u, dd[v].id, dis};
			if (dd[u] < nw) {
				dd[u] = nw;
				qq.push(nw);
			}
		}	
	}
	
	rep(i, 1, m) printf ("%d ", dd[qw[i]].id);
	printf ("\n");
	
	rep(i, 1, *nodes) {
		vis[nodes[i]] = 0;
		graf[nodes[i]].clear();
	}
}

int main() {
	spe[0] = 1;
	scanf ("%d", &n);
	rep(i, 2, n) {
		int u, v;
		scanf ("%d%d", &u, &v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 1);
	
	int q;
	scanf ("%d", &q);
	while (q--) solve();
	return 0;
}