#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 123;
ll cnt[N][N];

ll get(ll t, int x, int y) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cnt[i][j] = 0;
    }
  }
  /// at time <= t in cell x, y => at time <= t - x - y in cell 0, 0 and at time t2 there are t2 + 1 elements in cell 0, 0
  cnt[0][0] = max(0LL, t - x - y + 1);
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      cnt[i + 1][j] += (cnt[i][j]) / 2;
      cnt[i][j + 1] += (cnt[i][j] + 1) / 2;
    }
  }
  return cnt[x][y];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE


  int tests;
  cin >> tests;
  for (int tc = 1; tc <= tests; tc++) {

    ll t;
    int x, y;
    cin >> t >> x >> y;
    /// how many are there at moment t in the cell x, y =
    /// how many are there at moment <= t in cell x, y - how many are there at moment <= t - 1 in cell x, y

    if (get(t, x, y) - get(t - 1, x, y) > 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}