#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ///freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    string s, t;
    cin >> s;
    for (auto &c : s) {
      t += c;
      while ((int) t.size() >= 2 && t[(int) t.size() - 2] == 'A' && t[(int) t.size() - 1] == 'B') {
        t.pop_back();
        t.pop_back();
      }
    }
    s.clear();
    for (auto &c : t) {
      s += c;
      while ((int) s.size() >= 2 && s[(int) s.size() - 2] == 'B' && s[(int) s.size() - 1] == 'B') {
        s.pop_back();
        s.pop_back();
      }
    }
    cout << (int) s.size() << "\n";
  }
}