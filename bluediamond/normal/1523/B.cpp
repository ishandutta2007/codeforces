#include <bits/stdc++.h>; iron man

using namespace std;

#define int ll
typedef long long ll;
typedef long double ld;

vector<int> steps = {0, 0, 1, 0, 0, 1};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /// freopen ("input", "r", stdin);

  for (auto &it : steps) it++;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
    }
    cout << 6 * (n / 2) << "\n";
    for (int j = 1; j <= n; j += 2) {
      for (auto &it : steps) {
        cout << it << " " << j << " " << j + 1 << "\n";
      }
    }
  }

  return 0;
}