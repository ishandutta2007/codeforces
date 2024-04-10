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
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    set<int> s(v.begin(), v.end());
    if (s.size() == 1) {
      cout << "NO\n";
      continue;
    }

    int a = *(s.begin());
    int posa = -1, posb = -1;
    for (int i = 0; i < n; ++i) {
      if (v[i] == a) {
        posa = i;
      } else {
        posb = i;
      }
    }
    assert(posa != -1);
    assert(posb != -1);

    vector<pair<int, int>> ans;
    // link all to posa
    for (int i = 0; i < n; ++i) {
      if (v[i] != a) {
        ans.emplace_back(posa + 1, i + 1);
      }
    }
    // link rem to posb
    for (int i = 0; i < n; ++i) {
      if (v[i] == a && i != posa) {
        ans.emplace_back(posb + 1, i + 1);
      }
    }
    assert(ans.size() == n - 1);

    cout << "YES\n";
    for (auto [a, b] : ans) {
      cout << a << " " << b << '\n';
    }
  }

  return 0;
}