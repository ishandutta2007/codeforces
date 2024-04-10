#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> ls;
  vector<vector<int>> g(2 * n);
  for (int i = 0; i < 2 * n; i += 2) {
    g[i].push_back(i + 1);
    g[i + 1].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    ls.push_back({ a, b });
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> sol(2 * n, -1);
  function<void(int, int)>dfs = [&](int a, int type) {
    sol[a] = type;
    for (auto& b : g[a]) {
      if (sol[b] == -1) {
        dfs(b, 1 ^ type);
      }
    }
  };
  for (int i = 0; i < 2 * n; i++) {
    if (sol[i] == -1) {
      dfs(i, 0);
    }
  }
  for (auto& it : ls) {
    cout << sol[it.first] + 1 << " " << sol[it.second] + 1 << "\n";
  }
  return 0;
}