#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
int maxv;
vector<pair<int, int>> ans;

void DFS(int node, int par, int val) {
  assert(val <= maxv);
  int sonc = graph[node].size();
  int _val = val;
  
  //cerr << node + 1 << " " << val << endl; 
  ans.emplace_back(node, val);
  for (int i = 0; i < sonc; ++i) {
    if (graph[node][i] == par) continue;
    if (val == maxv) {
      int nval = maxv - sonc;
      //cerr << node + 1 << " " << nval << endl;
      ans.emplace_back(node, nval);
      val = nval;
    }
    DFS(graph[node][i], node, val + 1);
    //cerr << node + 1 << " " << val + 1 << endl;
    ans.emplace_back(node, val + 1);
    ++val;
  }
  if (val >= _val) {
    //cerr << node + 1 << " " << _val - 1 << endl;
    ans.emplace_back(node, _val - 1);
    val = _val - 1;
  }

  assert(val == _val - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  graph.assign(n, {});
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  for (int i = 0; i < n; ++i)
    maxv = max(maxv, (int)graph[i].size());

  DFS(0, -1, 0);
  ans.pop_back();
  cout << ans.size() << endl;
  for (auto x : ans) {
    cout << x.first + 1 << " " << x.second << '\n';
  }

  return 0;
}