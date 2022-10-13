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
    int n; cin >> n;
    vector<int> x, y;
    for (int i = 0; i < 2 * n; ++i) {
      int a, b; cin >> a >> b;
      if (a == 0) y.push_back(abs(b));
      else x.push_back(abs(a));
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double best = 4e18;
    for (int it = 0; it < 2; ++it) {
      double ans = 0;
      for (int i = 0; i < n; ++i) {
        ans += sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
      }
      best = min(best, ans);
      reverse(y.begin(), y.end());
    }
    cout << fixed << setprecision(20) << best << '\n';
  }

  return 0;
}