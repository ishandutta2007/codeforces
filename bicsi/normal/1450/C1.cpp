#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

void Solve(vector<string> v) {
  int n = v.size();
  vector<vector<int>> cnt(2, vector<int>(3, 0));
  int k = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      if (v[i][j] == '.') continue;
      ++k;
      cnt[v[i][j] == 'X'][(i + j) % 3] += 1;
    }

  for (int a = 0; a < 3; ++a) {
    for (int b = 0; b < 3; ++b) {
      if (a == b) continue;
      if (cnt[0][a] + cnt[1][b] <= k / 3) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            if (v[i][j] == '.') continue;
            int x = (v[i][j] == 'X');
            int y = (i + j) % 3;
            if ((x == 0 && y == a) || (x == 1 && y == b)) {
              v[i][j] ^= ('X' ^ 'O');
            }
          }
        }
        for (int i = 0; i < n; ++i)
          cout << v[i] << '\n';
        return;
      }
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];
    Solve(v);
  }
  return 0;
}