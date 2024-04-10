#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<pair<int, int>> ans = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
  int at = 1;
  for (int i = 1; i <= n; ++i) {
    ans.emplace_back(i + 1, i);
    ans.emplace_back(i, i + 1);
    ans.emplace_back(i + 1, i + 1);
  }
  cout << ans.size() << endl;
  for (auto p : ans) cout << p.first << " " << p.second << '\n';

  return 0;
}