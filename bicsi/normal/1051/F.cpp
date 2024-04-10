#include <bits/stdc++.h>

using namespace std;

template <class T>
struct RMQ {
  vector<vector<T>> rmq;
  
  void Build(const vector<T>& V) {
    int n = V.size(), on = 1, depth = 1;
    while (on < n) on *= 2, ++depth;
    rmq.assign(depth, V);
    for (int i = 0; i < depth - 1; ++i)
      for (int j = 0; j < n; ++j)
        rmq[i + 1][j] = min(rmq[i][j],
          rmq[i][min(n - 1, j + (1 << i))]);
  }
  

  T Query(int a, int b) {
    if (b <= a) return numeric_limits<T>::max();
      int dep = 31 - __builtin_clz(b - a); // log(b - a)
        return min(rmq[dep][a], rmq[dep][b - (1 << dep)]);
  }
};

struct LCA {
  int n;
  vector<int> enter, depth, imp;
  vector<long long> pref;
  vector<vector<pair<int, int>>> graph;
  vector<pair<int, int>> linear;
  vector<vector<long long>> dists;
  RMQ<pair<int, int>> rmq;
  int timer = 0;
  
  LCA(int n) : n(n), enter(n, -1), depth(n), pref(n, 0), 
    graph(n), linear(2 * n) {}
  
  void dfs(int node, int par, int dep, long long dist) {
    linear[timer] = {dep, node};
    enter[node] = timer++;
    depth[node] = dep;
    pref[node] = dist;
    
    for (auto itr : graph[node]) {
      int vec, cost; tie(vec, cost) = itr;
      if (vec == par) continue;
      if (enter[vec] == -1) {
        dfs(vec, node, dep + 1, dist + cost);
        linear[timer++] = {dep, node};
        continue;
      }
      imp.push_back(node);
      imp.push_back(vec);
    }
  }
  
  void AddEdge(int a, int b, int c) {
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }
  
  vector<long long> Dijkstra(int node) {
    priority_queue<pair<long long, int>> q;
    vector<long long> dist(n, (long long)1e18);
    auto push = [&](int node, long long d) {
      if (d >= dist[node]) return;
      dist[node] = d;
      q.emplace(-d, node);
    };
  
    push(node, 0);
    while (!q.empty()) {
      long long d;
      tie(d, node) = q.top(); d = -d;
      q.pop();
  		
      if (d != dist[node]) continue;
      for (auto itr : graph[node]) {
        int vec, cost; tie(vec, cost) = itr;
        push(vec, d + cost);
      }
    }
    return dist;
  }
  
  void Build(int root) {
    dfs(root, -1, 0, 0);
    rmq.Build(linear);
    sort(imp.begin(), imp.end());
    imp.erase(unique(imp.begin(), imp.end()), imp.end());
    
    for (auto x : imp)
      dists.emplace_back(Dijkstra(x));
  }
  
  int GetLCA(int a, int b) {
    a = enter[a], b = enter[b];
    return rmq.Query(min(a, b), max(a, b) + 1).second;
  }
  
  long long Query(int a, int b) {
    int lca = GetLCA(a, b);
    long long ans = pref[a] + pref[b] - 2 * pref[lca];
    for (int i = 0; i < (int)dists.size(); ++i)
      ans = min(ans, dists[i][a] + dists[i][b]);
    return ans;
  }
};

int main() {
  int n, m; cin >> n >> m;
  LCA lca(n);

  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    lca.AddEdge(a - 1, b - 1, c);
  }

  lca.Build(0);
  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;
    cout << lca.Query(a - 1, b - 1) << '\n';
  }

  return 0;
}