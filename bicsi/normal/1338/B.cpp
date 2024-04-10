#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
int got[2];
vector<bool> is_leaf;
int ans = 0;

void DFS(int node, int par, int depth) {
  bool has_leaf_son = false;
  for (auto vec : graph[node]) {
    if (vec == par) continue;
    is_leaf[node] = false;
    DFS(vec, node, depth + 1);
    if (!has_leaf_son || is_leaf[vec] == false)
      ans += 1;
    if (is_leaf[vec]) has_leaf_son = true;
  }
  if (is_leaf[node]) 
    got[depth % 2] += 1;
}

int main() {
  int n; cin >> n;
  graph.resize(n);
  is_leaf.assign(n, true);

  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int root = 0;
  while (graph[root].size() == 1)
    ++root;
  // cerr << "root: " << root + 1 << endl;
  DFS(root, -1, 0);

  int min_ans = (got[0] && got[1] ? 3 : 1);
  int max_ans = ans;
  
  cout << min_ans << " " << max_ans << endl;
  assert(min_ans <= max_ans);

  return 0;
}