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
    vector<string> v(3);
    for (int i = 0; i < 3; ++i)
      cin >> v[i];
    for (int i = 0; i < 3; ++i) {
      string a = v[0], b = v[1];
      for (char common : {'0', '1'}) {
        int p1 = 0, p2 = 0;
        string ret;
        while (p1 < 2 * n || p2 < 2 * n) {
          if (p1 == 2 * n) ret += b[p2++];
          else if (p2 == 2 * n) ret += a[p1++];
          else if (a[p1] == b[p2]) {
            ret += a[p1++];
            p2++;
          } else if (a[p1] == common) {
            ret += a[p1++];
          } else {
            assert(b[p2] == common);
            ret += b[p2++];
          }
        }
        if (ret.size() > 3 * n) continue;
        cout << ret << '\n';
        goto done;
      }
      rotate(v.begin(), v.begin() + 1, v.end());
    }
    assert(false);
done:;
  }

  return 0;
}