#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N = (int) 1e5 + 7;
int n, k, m, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  ld best = -(ld) 1e18, sm = 0;
  for (int i = 1; i <= n; i++) {
    sm += a[i];
    int grow = m - (n - i);
    if (grow >= 0) {
      best = max(best, (sm + min((long long) grow, (long long) k * i)) / i);
    }
  }
  cout << fixed << setprecision(6) << best << "\n";
  return 0;
}