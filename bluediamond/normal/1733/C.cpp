#include <bits/stdc++.h>

using namespace std;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    cout << n - 1 << "\n";
    cout << 1 << " " << n << "\n";
    for (int i = 1; i < n - 1; i++) {
      if ((a[0] + a[i]) % 2 == 1) {
        cout << 1 << " " << i + 1 << "\n";
      } else {
        cout << i + 1 << " " << n << "\n";
      }
    }

  }
}