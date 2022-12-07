#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; ++qq) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(0));
    for (int i = 0; i < n - 1; ++i) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    int diam = -1;
    int z = 0;
    function<void(int, int, int)> dfs = [&](int x, int p, int dep) {
      if (dep > diam) {
        diam = dep;
        z = x;
      }
      for (auto y : adj[x]) {
        if (y != p) {
          dfs(y, x, dep + adj[y].size() - 1);
        }
      }
    };
    dfs(0, -1, adj[0].size() - 1);
    dfs(z, -1, adj[z].size() - 1);
    cout << diam + 2 << endl;
  }

  return 0;
}