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
    int n; cin >> n;
    vector<array<int, 3>> v(n);
    for (int j = 0; j < 3; ++j)
      for (int i = 0; i < n; ++i)
        cin >> v[i][j];
    
    
    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      if (i == 0) ans[i] = v[i][0];
      else if (i + 1 < n) {
        if (ans[i - 1] == v[i][0])
          ans[i] = v[i][1];
        else ans[i] = v[i][0];
      } else {
        int j = 0;
        while (ans[i - 1] == v[i][j] || ans[0] == v[i][j])
          ++j;
        ans[i] = v[i][j];
      }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " "; cout << '\n';
  }

  return 0;
}