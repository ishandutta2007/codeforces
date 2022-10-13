#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    bool ok = false;
    for (int i = 1; i < n; ++i) {
      if (abs(v[i] - v[i - 1]) >= 2) {
        cout << "YES\n" << i << " " << i + 1 << '\n';
        ok = true;
        break;
      }
    }
    if (!ok) {
      cout << "NO\n";
    }
  }

  return 0;
}