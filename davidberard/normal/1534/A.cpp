#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    bool has_w = false, has_r = false;
    for (int i=0; i<n; ++i) {
      cin >> grid[i];
      for (int j=0; j<m; ++j) {
        if (grid[i][j] == 'R') {
          ((i+j)%2 == 1 ? has_w : has_r) = true;
        }
        if (grid[i][j] == 'W') {
          ((i+j)%2 == 1 ? has_r : has_w) = true;
        }
      }
    }
    if (has_w && has_r) {
      cout << "NO\n";
      continue;
    }
    if (!has_w && !has_r) {
      has_w = 1;
    }
    cout << "YES\n";
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) {
        if (grid[i][j] == '.') {
          if (has_w) {
            grid[i][j] = ((i+j)%2 == 1 ? 'R' : 'W');
          }
          if (has_r) {
            grid[i][j] = ((i+j)%2 == 0 ? 'R' : 'W');
          }
        }
      }
      cout << grid[i] << "\n";
    }
  }
  return 0;
}