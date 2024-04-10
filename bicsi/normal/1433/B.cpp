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
    int total = 0;
    int minpos = n, maxpos = -1;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i]) {
        maxpos = max(maxpos, i);
        minpos = min(minpos, i);
      }
    }
    if (maxpos < minpos) {
      cout << 0 << '\n';
    } else {
      int ans = 0;
      for (int i = minpos; i <= maxpos; ++i)
        if (a[i] == 0)
          ans += 1;
      cout << ans << '\n';
    }
  }

  return 0;
}