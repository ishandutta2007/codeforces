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
    vector<string> s(n);
    for (int i = 0; i < n; ++i)
      cin >> s[i];

    vector<pair<int, int>> ans;
    if (s[0][1] == s[1][0]) {
      if (s[n - 1][n - 2] == s[0][1])
        ans.emplace_back(n - 1, n - 2);
      if (s[n - 2][n - 1] == s[0][1])
        ans.emplace_back(n - 2, n - 1);
    } else if (s[n - 1][n - 2] == s[n - 2][n - 1]) {
      if (s[0][1] == s[n - 1][n - 2])
        ans.emplace_back(0, 1);
      if (s[1][0] == s[n - 1][n - 2])
        ans.emplace_back(1, 0);
    } else {
      if (s[0][1] != '1') ans.emplace_back(0, 1);
      if (s[1][0] != '1') ans.emplace_back(1, 0);
      if (s[n - 1][n - 2] != '0') ans.emplace_back(n - 1, n - 2);
      if (s[n - 2][n - 1] != '0') ans.emplace_back(n - 2, n - 1);
    }
    
    assert(ans.size() <= 2);
    cout << ans.size() << '\n';
    for (auto [a, b] : ans)
      cout << a + 1 << " " << b + 1 << '\n';
  }

  return 0;
}