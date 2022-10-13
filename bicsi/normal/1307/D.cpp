#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;

vector<long long> Dijkstra(int src) {
  int n = graph.size();
  vector<long long> ret(n, 2e18);

  priority_queue<pair<long long, int>> pq;
  auto push = [&](int node, long long d) {
    if (ret[node] <= d) return;
    ret[node] = d;
    pq.emplace(-d, node);
  };

  push(src, 0);
  while (!pq.empty()) {
    long long d; int node; tie(d, node) = pq.top(); pq.pop();
    if (ret[node] != -d) continue;
    for (auto e : graph[node]) {
      int vec, cost; tie(vec, cost) = e;
      push(vec, cost - d);
    }
  }

  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  
  int n, m, k; cin >> n >> m >> k;
  graph.resize(n);

  vector<int> spec;
  for (int i = 0; i < k; ++i) {
    int x; cin >> x; spec.push_back(x - 1);
  }

  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b, 1);
    graph[b].emplace_back(a, 1);
  }

  auto d1 = Dijkstra(0);
  auto dn = Dijkstra(n - 1);
  
  sort(spec.begin(), spec.end(), [&](int a, int b) {
    return d1[a] < d1[b];   
  });

  long long best = 0;
  long long max_b = dn[spec[k - 1]];
  for (int i = k - 2; i >= 0; --i) {
    long long now = d1[spec[i]] + 1 + max_b;
    best = max(best, now);
    max_b = max(max_b, dn[spec[i]]);
  }
  best = min(best, d1[n - 1]);
  cout << best << endl;

  return 0;
}