#include <bits/stdc++.h>

using namespace std;




signed main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    string s, a = "", b = "", c = "";
    int cost = 1;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
      char ch = s[i];
      if (a.size() == 1 && a[0] == ch) continue;
      if (b.size() == 1 && b[0] == ch) continue;
      if (c.size() == 1 && c[0] == ch) continue;
      if (a.size() == 0) {a += ch; continue;}
      if (b.size() == 0) {b += ch; continue;}
      if (c.size() == 0) {c += ch; continue;}
      a = "";
      b = "";
      c = "";
      cost++;
      i--;
    }
    cout << cost << "\n";
  }
  return 0;
}