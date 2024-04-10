#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> l, r;

pair<long long, long long> DFS(int node, int par) {
  long long lc = 0, rc = 0;
  for (auto vec : graph[node]) {
    if (vec == par) continue;
    auto [lp, rp] = DFS(vec, node);
    lc += max(abs(l[node] - l[vec]) + lp,
        abs(l[node] - r[vec]) + rp);
    rc += max(abs(r[node] - l[vec]) + lp,
        abs(r[node] - r[vec]) + rp);
  }
  return {lc, rc};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph.assign(n, {});
    l.assign(n, -1);
    r.assign(n, -1);
    for (int i = 0; i < n; ++i)
      cin >> l[i] >> r[i];
    for (int i = 1; i < n; ++i) {
      int a, b; cin >> a >> b; --a; --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    auto [a, b] = DFS(0, -1);
    cout << max(a, b) << '\n';
  }

  return 0;
}