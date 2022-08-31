#include <bits/stdc++.h>
 
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
 
using namespace std;
 
typedef long double ld;
typedef long long ll;
typedef long long LL;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};
 
struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
 
  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0));
      g[v].emplace_back(E.size() - 1);
    }
  }
 
  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }
 
  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }
 
  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};
 
struct ship_t {
	ll x, a, f, p;
};
 
struct base_t {
	ll x, d, g;
	bool operator<(const base_t &o) const {
		return d < o.d;
	}
};
 
const int N = 1e2 + 10, S = 1e5 + 10;
const ll inf = 1e12 + 42;
 
ship_t ship[S];
base_t base[S];
ll g[N][N];
vector<int> dep[S];
vector<pll> bases_at[N];
bool seen[S];
ll val[S];
 
int main()
{
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			g[i][j] = g[j][i] = inf;
		}
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = min(g[u][v], 1ll);
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int s, b, k;
	cin >> s >> b >> k;
	for (int i = 1; i <= s; ++i) {
		cin >> ship[i].x >> ship[i].a >> ship[i].f >> ship[i].p;
	}
	for (int i = 1; i <= b; ++i) {
		cin >> base[i].x >> base[i].d >> base[i].g;
	}
	sort(base + 1, base + 1 + b);
	for (int i = 1; i <= b; ++i) {
		int p = base[i].x;
		if (bases_at[p].empty() or bases_at[p].back().second < base[i].g) {
			bases_at[p].pb({base[i].d, base[i].g});
		}
	}
	Dinic dinic(s + 2);
	int source = 0, sink = s + 1;
	ll ans = 0;
	for (int i = 1; i <= s; ++i) {
		bool found = false;
		for (int p = 1; p <= n; ++p) {
			if (g[ship[i].x][p] > ship[i].f) {
				continue;
			}
			auto it = upper_bound(bases_at[p].begin(), bases_at[p].end(), make_pair(ship[i].a, inf));
			if (it != bases_at[p].begin()) {
				--it;
				val[i] = max(val[i], it->second);
				found = true;
			}
		}
		val[i] -= ship[i].p;
		if (!found) {
			val[i] = -inf;
		}
		if (val[i] >= 0) {
			ans += val[i];
			dinic.AddEdge(source, i, val[i]);
		} else {
			dinic.AddEdge(i, sink, -val[i]);
		}
	}
	for (int i = 1; i <= k; ++i) {
		int u, v;
		cin >> u >> v;
		dep[u].pb(v);
		dinic.AddEdge(u, v, inf);
	}
	// for (int i = 1; i <= s; ++i) {
	// 	if (val[i] < 0) {
	// 		continue;
	// 	}
	// 	vector<int> vis = {i};
	// 	queue<int> q;
	// 	q.push(i);
	// 	seen[i] = true;
	// 	while (!q.empty()) {
	// 		int u = q.front();
	// 		q.pop();
	// 		if (val[u] < 0) {
	// 			dinic.AddEdge(i, u, inf);
	// 		}
	// 		for (auto &v : dep[u]) {
	// 			if (!seen[v]) {
	// 				seen[v] = true;
	// 				vis.pb(v);
	// 				q.push(v);
	// 			}
	// 		}
	// 	}
	// 	for (auto &u : vis) {
	// 		seen[u] = false;
	// 	}
	// }
	cout << ans - dinic.MaxFlow(source, sink);
}