#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans = 0;
vector<vector<int>> graph;

vector<int> DFS(int node, int par) {
  vector<int> big = {1};
  for (auto vec : graph[node]) {
    if (vec == par) continue;

    auto small = DFS(vec, node);
    if (small.size() > big.size()) 
      swap(small, big);  
    for (int i = 0, j = k; i < (int)small.size(); ++i, --j) {
      int p1 = small.size() - i - 1, p2 = big.size() - j - 1;
      if (p2 >= 0 && p2 < (int)big.size())
        ans += 1LL * small[p1] * big[p2];
    }
    for (int i = 0; i < (int)small.size(); ++i) {
      int p1 = small.size() - i - 1, p2 = big.size() - i - 1;
      big[p2] += small[p1];
    }
  }
  big.push_back(0);
  return big;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  graph.resize(n);
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  DFS(0, -1);
  cout << ans << endl;


  return 0;
}