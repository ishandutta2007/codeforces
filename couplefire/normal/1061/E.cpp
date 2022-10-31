#include <bits/stdc++.h>

using namespace std;

namespace mcmf {
	using ll = long long;
	const ll oo = 1e18;
	const int N = 1015, E = N * N * 2;
	vector<int> g[N];
	int ne;
	struct Edge {
		int from, to; ll cap, cost;
	} edge[E];
	int start = N - 1, target = N - 2, p[N];  int inqueue[N];
	ll d[N];
	ll pot[N];
	bool dijkstra(int source, int sink) {
		for(int i = 0; i < N; i++) d[i] = oo;
		d[source] = 0;
		priority_queue<pair<ll, int>> q;
		q.emplace(0, source);
		ll dt; int u;
		while(!q.empty()) {
			tie(dt, u) = q.top(); q.pop(); dt = -dt;
			if(dt > d[u]) continue;
			for(int e : g[u]) {
				auto v = edge[e];
				const ll cand = d[u] + v.cost + pot[u] - pot[v.to];
				if(v.cap > 0 and cand < d[v.to]) {
					p[v.to] = e;
					d[v.to] = cand;
					q.emplace(-d[v.to], v.to);
				}
			}
		}
		return d[sink] < oo;
	}
	pair<ll, ll> mincost(int source = start, int sink = target) {
		ll ans = 0, mf = 0;
		while(dijkstra(source, sink)) {
			ll f = oo;
			for(int u = sink; u != source; u = edge[ p[u] ].from) {
				f = min(f, edge[ p[u] ].cap);
			}
			mf += f;
			ans += f * (d[sink] - pot[source] + pot[sink]);
			for(int u = sink; u != source; u = edge[ p[u] ].from) {
				edge[ p[u] ].cap -= f;
				edge[ p[u]^1 ].cap += f;
			}
			for(int i = 0; i < N; i++) pot[i] = min(oo, pot[i] + d[i]);
		}
		return {mf, ans};
	}
	void addEdge(int u, int v, ll c, ll cost) {
		edge[ne] = {u, v, c, cost};
		g[u].push_back(ne++);
		edge[ne] = {v, u, 0, -cost};
		g[v].push_back(ne++);
	}
};

const int N = 505, M = 200000;

int n, x, y;
int a[N];

vector<int> g[N], t[N];
int x1[N], x2[N];

int dfs1(int u, int p) {
	int sum = 0;
	for(int v : g[u]) if(v != p) {
		sum += dfs1(v, u);
	}
	if(x1[u] == -1) {
		mcmf::addEdge(p, u, n, 0);
		return sum;
	} 
	int tmp = x1[u];
	x1[u] -= sum;
	if(x1[u] < 0) {
		printf("-1\n");
		exit(0);
	}
	mcmf::addEdge(mcmf::start, u, x1[u], 0);
	return tmp;
}
int dfs2(int u, int p) {
	int sum = 0;
	for(int v : t[u]) if(v != p) {
		sum += dfs2(v, u);
	}
	if(x2[u] == -1) {
		mcmf::addEdge(u + n, p + n, n, 0);
		return sum;
	} 
	int tmp = x2[u];
	x2[u] -= sum;
	if(x2[u] < 0) {
		printf("-1\n");
		exit(0);
	}
	mcmf::addEdge(u + n, mcmf::target, x2[u], 0);
	return tmp;
}

int main() {

	scanf("%d %d %d", &n, &x, &y);

	for(int i = 1; i <= n; i++) scanf("%d", a + i);

	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		t[u].push_back(v);
		t[v].push_back(u);
	}

	memset(x1, -1, sizeof x1);
	memset(x2, -1, sizeof x2);

	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int k, tmp;
		scanf("%d %d", &k, &tmp);
		x1[k] = tmp;
	}
	
	scanf("%d", &q);
	for(int i = 0; i < q; i++) {
		int k, tmp;
		scanf("%d %d", &k, &tmp);
		x2[k] = tmp;
	}

	int va = dfs1(x, x);
	int vb = dfs2(y, y);

	if(va != vb) return printf("-1\n"), 0;

	for(int i = 1; i <= n; i++) {
		mcmf::addEdge(i, n + i, 1, M - a[i]);
	}

	auto ans = mcmf::mincost();
	if(ans.first != va) return printf("-1\n"), 0;

	printf("%lld\n", -(ans.second - 1LL * M * va));

}