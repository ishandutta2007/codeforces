#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> graph;
vector<vector<int>> sz, ccs;

void DFS(int gi, int node, int cc) {
  ccs[gi][node] = cc;
  sz[gi][cc] += 1;

  for (auto vec : graph[gi][node]) {
    if (ccs[gi][vec] == -1)
      DFS(gi, vec, cc);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  graph.assign(2, vector<vector<int>>(n));
  sz.assign(2, vector<int>(n, 0));
  ccs.assign(2, vector<int>(n, -1));

  for (int i = 1; i < n; ++i) {
    int a, b, c; 
    cin >> a >> b >> c;
    --a; --b; 
    graph[c][a].emplace_back(b);
    graph[c][b].emplace_back(a);
  }

  long long ans = 0;
  int cc1 = 0, cc2 = 0;
  
  for (int i = 0; i < n; ++i) {
    if (ccs[0][i] == -1) {
      DFS(0, i, cc1++);
    }
    if (ccs[1][i] == -1) {
      DFS(1, i, cc2++);
    }
    int cc1 = ccs[0][i];
    int cc2 = ccs[1][i];
    ans += 1LL * sz[0][cc1] * sz[1][cc2];
  }

  cout << ans - n  << endl;

  return 0;
}