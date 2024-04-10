#include <bits/stdc++.h>

using namespace std;



signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
      cin >> x[i] >> y[i];
    }
    bool ok = 0;
    for (int i = 0; i < n; i++) {
      bool all = 1;
      for (int j = 0; j < n; j++) {
        all &= ((abs(x[i] - x[j]) + abs(y[i] - y[j])) <= k);
      }
      ok |= all;
    }
    if (!ok) {
      cout << "-1\n";
    } else {
      cout << "1\n";
    }
  }
}