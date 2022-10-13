#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      pos[v[i]].push_back(i);
    }

    string ans(n, '0');
    if (pos.size() == n) {
      ans[0] = '1';
    }
    int l = 0, r = n - 1;
    for (int i = 1; i <= n; ++i) {
      if (pos[i].empty()) break;
      ans[r - l] = '1';
      if (pos[i].size() >= 2 || (pos[i][0] != l && pos[i][0] != r)) {
        break;
      }
      if (pos[i][0] == l) ++l;
      else --r;
    }
    cout << ans << '\n';
  }
  return 0;
}