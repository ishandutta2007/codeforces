#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 /// freopen("iron_man.txt", "r", stdin);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> parrent(n);
  vector<int> dist(n);

  function<int(int)> find_far_vertex = [&](int a) {
    for (int i = 0; i < n; i++) {
      parrent[i] = -1;
      dist[i] = -1;
    }
    queue<int> q;
    q.push(a);
    dist[a] = 0;
    int mxDist = 0;
    while (!q.empty()) {
      a = q.front();
      q.pop();
      for (auto& b : g[a]) {
        if (dist[b] == -1) {
          dist[b] = 1 + dist[a];
          parrent[b] = a;
          q.push(b);
        }
      }
    }

    return max_element(dist.begin(), dist.end()) - dist.begin();
  };
  int a = find_far_vertex(0);
  int b = find_far_vertex(a);
  vector<int> path;
  {
    int vertex = b;
    path.push_back(vertex);
    while (vertex != a) {
      vertex = parrent[vertex];
      path.push_back(vertex);
    }
  }
  find_far_vertex(a);
  vector<int> dist_a = dist;
  find_far_vertex(b);
  vector<int> dist_b = dist;

  vector<bool> onpath(n, 0);
  for (auto& x : path) {
    onpath[x] = 1;
  }
  vector<int> deg(n);
  queue<int> leafs;
  for (int i = 0; i < n; i++) {
    deg[i] = (int)g[i].size();
    if (!onpath[i] && deg[i] == 1) {
      leafs.push(i);
    }
  }
  ll sol = 0;
  vector<vector<int>> print;
  while (!leafs.empty()) {
    int v = leafs.front();
    leafs.pop();
    if (dist_a[v] > dist_b[v]) {
      sol += dist_a[v];
      print.push_back({ a, v, v });
    }
    else {
      sol += dist_b[v];
      print.push_back({ b, v, v });
    }
    for (auto& v2 : g[v]) {
      deg[v2]--;
      if (!onpath[v2] && deg[v2] == 1) {
        leafs.push(v2);
      }
    }
  }
  for (int i = (int)path.size() - 1; i; i--) {
    sol += i;
    print.push_back({ path[0], path[i], path[i] });
  }
  cout << sol << "\n";
  for (auto& v : print) {
    for (auto& x : v) {
      cout << x + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}