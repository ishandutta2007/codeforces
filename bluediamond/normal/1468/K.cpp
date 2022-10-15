#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll


vector<pair<int, int>> mo;

bool tri(string s, int bx, int by) {
  int x, y;
  x = 0;
  y = 0;
  mo.clear();
  int inix, iniy;
  for (auto &ch : s) {
    inix = x;
    iniy = y;
    if (ch == 'L') x--;
    if (ch == 'R') x++;
    if (ch == 'D') y--;
    if (ch == 'U') y++;
    if (x == bx && y == by) {
      x = inix;
      y = iniy;
    }
    if (x != 0 || y != 0) {
      mo.push_back({x, y});
    }
  }
  return (x == 0 && y == 0);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //freopen ("input", "r", stdin);


  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    if (tri(s, (int) 1e9, (int) 1e9)) {
      cout << (int) 1e9 << " " << (int) 1e9 << "\n";
      continue;
    }
    bool ok = 0;
    vector<pair<int, int>> kek = mo;
    for (auto &it : kek) {
      if (tri(s, it.first, it.second)) {
        cout << it.first << " " << it.second << "\n";
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << "0 0\n";
    }
  }

}