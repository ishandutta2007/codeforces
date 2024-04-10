#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, id = 0;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    vector<int> pos(n * m + 1);
    for (auto &v : a) {
      for (auto &x : v) {
        cin >> x;
        pos[x] = id;
      }
      id++;
    }
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < m; j++) {
        cout << a[pos[x]][j] << " ";
      }
      cout << "\n";
    }
    for (int i = 0; i < m - 1; i++) {
      for (int j = 0; j < n; j++) {
        int u;
        cin >> u;
      }
    }
  }
}