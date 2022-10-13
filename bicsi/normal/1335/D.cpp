#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    vector<string> v(9);
    for (int i = 0; i < 9; ++i)
      cin >> v[i];
    
    auto good = [&](int i, int j) {
      bool flag;

      flag = false;
      for (int ip = 0; ip < 9; ++ip) {
        if (ip == i) continue;
        if (v[ip][j] == v[i][j])
          flag = true; 
      }
      if (!flag) return true;
      
      flag = false;
      for (int jp = 0; jp < 9; ++jp) {
        if (jp == j) continue;
        if (v[i][jp] == v[i][j])
          flag = true; 
      }
      if (!flag) return true;

      flag = false;
      for (int ip = i / 3; ip < i / 3 + 3; ++ip) {
        for (int jp = j / 3; jp < j / 3 + 3; ++jp) {
          if (ip == i && jp == j) continue;
          if (v[ip][jp] == v[i][j])
            flag = true;
        }
      }
      if (!flag) return true;

      return false;
    };

    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        int r = i * 3 + j;
        int c = j * 3 + i;
        while (good(r, c)) {
          v[r][c] = (v[r][c] - '0' + 1) % 10 + '0'; 
        }
        // v[r][c] = 'X';
      } 
    }
 
    for (int i = 0; i < 9; ++i)
      cout << v[i] << '\n';
  }
  return 0;
}