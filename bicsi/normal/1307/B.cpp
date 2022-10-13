#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, x; cin >> n >> x;

    bool is_one = false;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (a[i] == x) {
        is_one = true;
      }
    }

    if (is_one) {
      cout << 1 << '\n';
    } else {
      sort(a.begin(), a.end());
      cout << max(2, (x + a[n - 1] - 1) / a[n - 1]) << '\n';
    }
  }

  return 0;
}