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
    vector<int> v(n);
    map<int, int> last_pos, from;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      if (!last_pos.count(v[i])) {
        from[v[i]] = i + 1;
      } else {
        from[v[i]] = max(from[v[i]], i - last_pos[v[i]]);
      }
      last_pos[v[i]] = i;
    }


    for (auto p : last_pos) {
      from[p.first] = max(from[p.first], n - p.second);
    }


    vector<int> ans(n + 1, 1e9);
    for (auto p : from) {
      ans[p.second] = min(ans[p.second], p.first);
    }
    for (int i = 1; i <= n; ++i) {
      ans[i] = min(ans[i], ans[i - 1]);
    }

    for (int i = 1; i <= n; ++i) {
      cout << (ans[i] == 1e9 ? -1 : ans[i]) << " ";
    }
    cout << '\n';
  }

  return 0;
}