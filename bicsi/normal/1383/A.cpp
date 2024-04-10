#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    set<pair<char, char>> all;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (a[i] > b[i]) bad = true;
      if (a[i] != b[i]) {
        all.insert({a[i], b[i]});
      }
    }
    if (bad) {
      cout << -1 << '\n';
    } else {
      int ans = 0;
      while (all.size()) {
        auto p = *all.begin();
        set<pair<char, char>> new_all;
        for (auto pp : all) {
          if (pp == p) continue;
          if (pp.first == p.first) {
            pp.first = p.second;
          }
          new_all.insert(pp);
        }
        all = new_all;
        ans += 1;
      }

      cout << ans << '\n';
    }
  }
  

  return 0;
}