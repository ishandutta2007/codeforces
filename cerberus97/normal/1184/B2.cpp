#include <bits/stdc++.h>

#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0);
 
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
	int x, a, f;
};

struct base_t {
	int x, d;
};

const int N = 1e2 + 10, S = 1e3 + 10, inf = 1e9 + 42;

ship_t ship[S];
base_t base[S];
int g[N][N];

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
		g[u][v] = g[v][u] = min(g[u][v], 1);
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	int s, b, k, h;
	cin >> s >> b >> k >> h;
	Dinic dinic(s + b + 2);
	int source = 0, sink = s + b + 1;
	for (int i = 1; i <= s; ++i) {
		cin >> ship[i].x >> ship[i].a >> ship[i].f;
		dinic.AddEdge(source, i, 1);
	}
	for (int i = 1; i <= b; ++i) {
		cin >> base[i].x >> base[i].d;
		dinic.AddEdge(s + i, sink, 1);
	}
	for (int i = 1; i <= s; ++i) {
		for (int j = 1; j <= b; ++j) {
			if (g[ship[i].x][base[j].x] <= ship[i].f and ship[i].a >= base[j].d) {
				dinic.AddEdge(i, s + j, 1);
			}
		}
	}
	ll t = dinic.MaxFlow(source, sink);
	ll ans = t * k;
	for (ll d = 1; d <= s; ++d) {
		ans = min(ans, d * h + min(t, s - d) * k);
	}
	cout << ans << endl;
}