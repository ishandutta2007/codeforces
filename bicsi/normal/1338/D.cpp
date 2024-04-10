#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> take, skip;

struct PQ {
  priority_queue<int> pq, qp;
  void Add(int x) { pq.push(x); }
  void Rem(int x) { qp.push(x); }
  int Max() {
    while (qp.size() && pq.top() == qp.top()) {
      pq.pop(); qp.pop();
    }
    return pq.top();
  }
  int Size() { return pq.size() - qp.size(); }
};

void DFSDown(int node, int par) {
  int best_skip = 0;
  int best_take = 0;
  int sons = 0;

  for (auto vec : graph[node]) {
    if (vec == par) continue;
    DFSDown(vec, node);
    sons += 1;
    best_skip = max(best_skip, skip[vec]);
    best_take = max(best_take, take[vec]);
  }

  take[node] = 1 + best_skip;
  if (sons >= 1) {
    skip[node] = sons - 1 + max(best_skip, best_take);
  }
}

int ans = 0;

void DFSUp(int node, int par, int up_skip, int up_take) {
  ans = max(ans, take[node] + up_skip);
  ans = max(ans, skip[node] + max(up_skip, up_take));
  
  PQ skip_pq, take_pq;
  if (par != -1) {
    skip_pq.Add(up_skip);
    take_pq.Add(up_take);
  }
  
  for (auto vec : graph[node]) {
    if (vec == par) continue;
    skip_pq.Add(skip[vec]);
    take_pq.Add(take[vec]);
  }

  for (auto vec : graph[node]) {
    if (vec == par) continue;
    
    skip_pq.Rem(skip[vec]);
    take_pq.Rem(take[vec]);
  
    int n_up_take = 1 + skip_pq.Max();
    int n_up_skip = max(take_pq.Max(), skip_pq.Max())
      + take_pq.Size() - 1;

    DFSUp(vec, node, n_up_skip, n_up_take);

    skip_pq.Add(skip[vec]);
    take_pq.Add(take[vec]);
  }
}

int main() {
  int n; cin >> n;
  take.assign(n, 0); skip.assign(n, 0); graph.assign(n, {});
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int root = 0;
  while (graph[root].size() == 1) 
    ++root;

  DFSDown(root, -1);
  DFSUp(root, -1, 0, 0);
  cout << ans << endl;

  return 0;
}