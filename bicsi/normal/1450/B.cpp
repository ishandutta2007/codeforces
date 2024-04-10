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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
      cin >> x[i] >> y[i];

    bool sol = false;
    for (int i = 0; i < n; ++i) {
      bool ok = true;
      for (int j = 0; j < n; ++j) {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        if (abs(dx) + abs(dy) > k) {
          ok = false;
          break;
        }
      }
      if (ok) {
        sol = true;
        cout << 1 << '\n';
        break;
      }
    }
    if (!sol) cout << -1 << '\n';
  }
  return 0;
}