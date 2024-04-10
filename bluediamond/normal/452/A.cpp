#include <bits/stdc++.h>

using namespace std;



signed main() {
  int n;
  string s;
  cin >> n >> s;
  set<string> p;
  p.insert("vaporeon");
  p.insert("jolteon");
  p.insert("flareon");
  p.insert("espeon");
  p.insert("umbreon");
  p.insert("leafeon");
  p.insert("glaceon");
  p.insert("sylveon");

  for (auto &t : p) {
    if ((int) s.size() != (int) t.size()) continue;
    bool ok = 1;
    for (int i = 0; i < (int) s.size(); i++) {
      if (s[i] != '.' && s[i] != t[i]) ok = 0;
    }
    if (ok) {
      cout << t << "\n";
      return 0;
    }
  }

  assert(0);
  return 0;
}
/**



**/