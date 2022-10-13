#include <bits/stdc++.h>

using namespace std;

int main() {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string need(s.size(), '.');
    for (int i = 0; i < k - 1; i += 1) {
      need[2 * i] = '(';
      need[2 * i + 1] = ')';
    }
    for (int i = 2 * k - 2, j = n - 1; i < j; ++i, --j) {
      need[i] = '(';
      need[j] = ')';
    }

    // cerr << "NEED: " << need << endl;

    vector<pair<int, int>> ops;
    for (int i = 0; i < n; ++i) {
      if (s[i] == need[i]) continue;
      for (int j = i + 1; j < n; ++j) {
        if (s[j] == need[i]) {
          ops.emplace_back(i, j);
          reverse(s.begin() + i, s.begin() + j + 1);
          break;
        }
      }
      assert(s[i] == need[i]);
    }

    cout << ops.size() << '\n';
    for (auto p : ops) {
      cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
  }
  return 0;
}