#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<vector<int>> M(n, vector<int>(m, 0));
    vector<vector<int>> O(n, vector<int>(m, 0));
    bool bad = false;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) {
        cin >> M[i][j];
        O[i][j] = 4;
        if (i == 0) O[i][j] -= 1;
        if (j == 0) O[i][j] -= 1;
        if (i == n - 1) O[i][j] -= 1;
        if (j == m - 1) O[i][j] -= 1;
        if (M[i][j] > O[i][j]) {
          bad = true;
        }
      }
    if (bad) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
          cout << O[i][j] << " ";
        cout << '\n';
      }
    }
  }


  return 0;
}