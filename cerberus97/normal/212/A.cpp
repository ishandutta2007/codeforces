/* cerberus97 - Hanit Banga */
 
#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
typedef long long ll;
typedef long long LL;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
 
const int N = 410, K = 5e3 + 10;
 
struct Edge {
  int u, v;
  LL cap, flow;
  int id;
  Edge() {}
  Edge(int u, int v, LL cap, int id): u(u), v(v), cap(cap), flow(0), id(id) {}
};
 
struct Dinic {
  int n, m, N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}
 
  void AddEdge(int u, int v, LL cap, int id) {
    if (u != v) {
      E.emplace_back(Edge(u, v, cap, id));
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(Edge(v, u, 0, -1));
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
 
int deg[N], lo[N], hi[N];
int u[K], v[K], type[K];
bool used[K];
 
int main() {
	fast_cin();
	int n, m, k, t;
	cin >> n >> m >> k >> t;
	for (int i = 1; i <= k; ++i) {
		cin >> u[i] >> v[i];
		v[i] += n;
		++deg[u[i]];
		++deg[v[i]];
	}
	int ans = 0;
	for (int i = 1; i <= n + m; ++i) {
		if (deg[i] % t) {
			++ans;
		}
	}
	for (int c = 1; c <= t; ++c) {
		int source = 0, sink = n + m + 1;
		int dummy_source = n + m + 2, dummy_sink = n + m + 3;
		Dinic dinic(n + m + 4);
		memset(deg, 0, sizeof(deg));
		for (int i = 1; i <= k; ++i) {
			if (!used[i]) {
				dinic.AddEdge(u[i], v[i], 1, i);
				++deg[u[i]];
				++deg[v[i]];
			}
		}
		int cur_t = (t - c + 1);
		int sum_lhs = 0, sum_rhs = 0, inf = 0;
		for (int i = 1; i <= n; ++i) {
			lo[i] = deg[i] / cur_t;
			hi[i] = (deg[i] + cur_t - 1) / cur_t;
			dinic.AddEdge(dummy_source, i, hi[i] - lo[i], -1);
			dinic.AddEdge(source, i, lo[i], -1);
			sum_lhs += lo[i];
			inf += hi[i];
		}
		for (int i = n + 1; i <= n + m; ++i) {
			lo[i] = deg[i] / cur_t;
			hi[i] = (deg[i] + cur_t - 1) / cur_t;
			dinic.AddEdge(i, dummy_sink, hi[i] - lo[i], -1);
			dinic.AddEdge(i, sink, lo[i], -1);
			sum_rhs += lo[i];
		}
		// int inf = max(sum_lhs, sum_rhs);
		dinic.AddEdge(source, dummy_source, inf - sum_lhs, -1);
		dinic.AddEdge(dummy_source, dummy_sink, inf, -1);
		dinic.AddEdge(dummy_sink, sink, inf - sum_rhs, -1);
		assert(dinic.MaxFlow(source, sink) == inf);
		for (auto &e : dinic.E) {
			if (e.id != -1 and e.flow) {
				type[e.id] = c;
				used[e.id] = true;
			}
		}
		// cout << c << " done" << endl;
	}
	cout << ans << '\n';
	for (int i = 1; i <= k; ++i) {
		cout << type[i] << ' ';
	}
	cout << endl;
}