#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, a, b, da, db; cin >> n >> a >> b >> da >> db;
    --a; --b;

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
      int a, b; cin >> a >> b; --a; --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    if (2 * da + 1 > db) {
      cout << "Alice\n";
      continue;
    }
  
    vector<int> depth(n, 0), parent(n, -1), height(n, 0);
    function<void(int, int)> dfs = [&](int node, int par) {
      for (auto vec : graph[node]) {
        if (vec == par) continue;
        depth[vec] = 1 + depth[node];
        parent[vec] = node;
        dfs(vec, node);
        height[node] = max(height[node], 1 + height[vec]);
      }
    };
    dfs(a, -1);

    if (depth[b] <= da) {
      cout << "Alice\n";
      continue;
    }

    int cnt = 0;
    for (auto vec : graph[a]) {
      if (height[vec] >= da) 
        cnt += 1;
    }

    if (cnt >= 2) {
      cout << "Bob\n";
      continue;
    }

    int far = 0;
    for (int i = 0; i < n; ++i)
      if (depth[i] > depth[far])
        far = i;

    depth[far] = 0; parent[far] = -1; height[far] = 0;
    dfs(far, -1);

    int diam = 0;
    for (int i = 0; i < n; ++i)
      diam = max(diam, depth[i]);
    diam = (diam + 1) / 2;
    if (diam <= da) {
      cout << "Alice\n";
      continue;
    }
    
    cout << "Bob\n";
  }

  return 0;
}