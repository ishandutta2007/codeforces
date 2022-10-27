#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      if (abs(v[i]) == 1) {
        pos.push_back(i);
      }
    }
    if (pos.size() % 2) {
      cout << -1 << '\n';
    } else {
      pos.push_back(n);
      vector<pair<int, int>> ans;
      for (int i = 0; i + 1 < (int)pos.size(); i += 2) {
        int a = pos[i], b = pos[i + 1], c = pos[i + 2];
        if (ans.empty() && a > 0) {
          ans.emplace_back(0, a);
        }
        if (b - a > 1) {
          assert(false);
        } else if (v[a] == v[b]) {
          ans.emplace_back(a, c);
        } else {
          ans.emplace_back(a, b);
          ans.emplace_back(b, c);
        }
      }
      cout << ans.size() << '\n';
      for (auto [a, b] : ans) {
        cout << a + 1 << " " << b << '\n';
      }
    }
  }

  return 0;
}