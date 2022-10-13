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
    int n, m; cin >> n >> m;
    string s; cin >> s;
    for (int i = 0; i < m; ++i) {
      string ns = s;
      for (int j = 0; j < n; ++j) {
        int vec = 0 + (j != 0 && s[j - 1] == '1') + (j + 1 != n && s[j + 1] == '1');
        if (vec == 1)
          ns[j] = '1';
      }
      if (s == ns) break;
      s = ns;
    }
    cout << s << '\n';
  }
  return 0;
}