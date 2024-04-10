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
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    y = min(y, 2 * x);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (v[i][j] == '*') continue;
        if (j + 1 < m && v[i][j + 1] == '.') {
          ans += y;
          j += 1;
        } else ans += x;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}