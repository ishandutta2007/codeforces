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
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef long long LL;

// Attribution - t3nsor codebook
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

const int N = 1e9 + 10, M = 120;

map<int, int> mx, my;
int rx[M], ry[M];
int x1[M], x2[M], y1[M], y2[M];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		mx[x1[i]];
		mx[x2[i] + 1];
		my[y1[i]];
		my[y2[i] + 1];
	}
	int idx = 0;
	for (auto &p : mx) {
		p.second = ++idx;
		rx[idx] = p.first;
	}
	rx[idx + 1] = n + 1;
	int idy = 1;
	for (auto &p : my) {
		p.second = ++idy;
		ry[idy] = p.first;
	}
	ry[idy + 1] = n + 1;
	Dinic dinic(2 + idx + idy);
	int source = 0, sink = 1 + idx + idy;
	for (int i = 1; i <= idx; ++i) {
		dinic.AddEdge(source, i, rx[i + 1] - rx[i]);
	}
	for (int j = 1; j <= idy; ++j) {
		dinic.AddEdge(idx + j, sink, ry[j + 1] - ry[j]);
	}
	for (int i = 1; i <= m; ++i) {
		x1[i] = mx[x1[i]];
		x2[i] = mx[x2[i] + 1];
		y1[i] = my[y1[i]];
		y2[i] = my[y2[i] + 1];
		for (int x = x1[i]; x < x2[i]; ++x) {
			for (int y = y1[i]; y < y2[i]; ++y) {
				dinic.AddEdge(x, idx + y, n + 1);
			}
		}
	}
	ll ans = dinic.MaxFlow(source, sink);
	assert(ans <= n);
	cout << ans << endl;
}