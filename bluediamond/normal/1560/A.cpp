#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  vector<int> r;

  for (int x = 1; x < 30; x++) {
    if (x % 3 != 0 && x % 10 != 3) {
      r.push_back(x);
    }
  }

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << ((n - 1) / 18) * 30 + r[(n - 1) % 18] << "\n";
  }

  return 0;
}