#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int tt;
  cin >> tt;
  while (tt--) {
    string s, w;
    int x, n = (int) s.size();
    cin >> s >> x;
    n = (int) s.size();
    w = s;
    for (auto &ch : w) {
      ch = '1';
    }
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (i - x >= 0) w[i - x] = '0';
        if (i + x < n) w[i + x] = '0';
      }
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        bool has = 0;
        if (i - x >= 0 && w[i - x] == '1') has = 1;
        if (i + x < n && w[i + x] == '1') has = 1;
        if (has == 0) {
          ok = 0;
          break;
        }
      }
    }
    if (ok) {
      cout << w << "\n";
    } else {
      cout << "-1\n";
    }
  }
  return 0;
}