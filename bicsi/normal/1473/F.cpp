#include <bits/stdc++.h>

using namespace std;

using T = int;

struct Dinic {
  struct Edge { int from, to, nxt; T cap, flow; };
   
  vector<Edge> es;
  vector<int> graph, at, dist, q;
  
  Dinic(int n) : graph(n, -1) {}
  
  int AddEdge(int a, int b, T c, bool dir = true) {
    auto add = [&](int a, int b, T c) {
      es.push_back({a, b, graph[a], c, 0});
      graph[a] = es.size() - 1;
    };
    add(a, b, c); add(b, a, dir ? 0 : c);
    return es.size() - 2;
  } 
  bool bfs(int src, int dest) {
    dist.assign(graph.size(), -1); q.clear();
    dist[src] = 0; q.push_back(src);
    for (int i = 0; i < (int)q.size(); ++i) {
      int node = q[i];
      for (int ei = graph[node]; ei >= 0; ei = es[ei].nxt) {
        const auto &e = es[ei];
        if (dist[e.to] == -1 && e.cap > e.flow) {
          dist[e.to] = dist[node] + 1;
          q.push_back(e.to);
        }
      }
    }
    return dist[dest] != -1;
  }
  T dfs(int node, int dest, T need) {
    if (!need || node == dest) return need;
    T ret = 0;
    for (int& ei = at[node]; ei != -1; ei = es[ei].nxt) {
      const auto &e = es[ei];
      if (dist[e.to] != dist[node] + 1) continue;
      if (T now = dfs(e.to, dest, min(need, e.cap - e.flow))) {
        es[ ei ].flow += now;
        es[ei^1].flow -= now;
        ret += now; need -= now;
      }
      if (!need) break;
    }
    return ret;
  }
  T Compute(int src, int dest) {
    T ret = 0;
    while (bfs(src, dest)) {
      at = graph;
      ret += dfs(src, dest, numeric_limits<T>::max());
    }
    return ret;
  }
  bool SideOfCut(int x) { return dist[x] == -1; } 
};

int main() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  vector<int> last(101, -1);
  Dinic F(n + 2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    for (int j = 1; j <= 100; ++j) 
      if (last[j] != -1 && a[i] % j == 0) 
        F.AddEdge(i, last[j], 1e9);
    last[a[i]] = i;
  }
  int total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    if (b[i] > 0) {
      F.AddEdge(n, i, b[i]);
      total += b[i];
    } else {
      F.AddEdge(i, n + 1, -b[i]);
    }
  }
  cout << total - F.Compute(n, n + 1) << endl;
  
  return 0;
}