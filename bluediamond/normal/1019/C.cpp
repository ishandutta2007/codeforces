#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1), ig(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    ig[y].push_back(x);
    g[x].push_back(y);
  }
  vector<bool> marked(n + 1, 0), insol(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    if (marked[i] == 0) {
      marked[i] = 1;
      insol[i] = 1;
      for (auto &j : g[i]) {
        marked[j] = 1;
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    if (insol[i]) {
      for (auto &j : ig[i]) {
        if (insol[j]) {
          insol[i] = 0;
          break;
        }
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (insol[i]) {
      ans.push_back(i);
    }
  }
  cout << (int) ans.size() << "\n";
  for (auto &i : ans) {
    cout << i << " ";
  }
  cout << "\n";
  return 0;
}