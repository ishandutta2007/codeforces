#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> graph;
int n;

struct DFSRet { 
  int sz, min, max; 
  long long amin, amax; 
};

DFSRet DFS(int node, int par, int cost) {
  DFSRet ret{1, 1, 1, 0, 0}; 
  for (auto e : graph[node]) {
    int vec, cost; tie(vec, cost) = e;
    if (vec == par) continue;

    auto now = DFS(vec, node, cost);
    ret.sz += now.sz;
    ret.amin += now.amin;
    ret.amax += now.amax;
    
    ret.min = max(ret.min, now.min) - min(ret.min, now.min);
    ret.max += now.max;
    while (ret.max > n - ret.sz)
      ret.max -= 2;
  }
  ret.amin += 1LL * ret.min * cost;
  ret.amax += 1LL * ret.max * cost;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n; n *= 2;
    graph.assign(n, {});
    for (int i = 1; i < n; ++i) {
      int a, b, c; cin >> a >> b >> c;
      --a; --b;
      graph[a].emplace_back(b, c);
      graph[b].emplace_back(a, c);
    }
    auto ans = DFS(0, -1, 0);
    cout << ans.amin << " " << ans.amax << '\n';
  }
  return 0;
}