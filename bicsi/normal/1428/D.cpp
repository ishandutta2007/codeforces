#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<pair<int, int>> ans;
  map<int, int> for2, for3;
  for (int i = n - 1, nowh = 1; i >= 0; --i, ++nowh) {
    if (a[i] == 0) continue;
    if (a[i] == 1) {
      ans.emplace_back(i + 1, nowh);
      for2[nowh] = i + 1;
      for3[nowh] = i + 1;
    }
    if (a[i] == 2) {
      if (for2.empty()) {
        cout << -1 << '\n';
        return 0;
      }
      auto it = for2.begin();
      ans.emplace_back(i + 1, it->first);
      for2.erase(it);
      for3[it->first] = i + 1;
      // it->second = i + 1;
    }
    if (a[i] == 3) {
      if (for3.empty()) {
        cout << -1 << '\n';
        return 0;
      }
      auto it = prev(for3.end());
      ans.emplace_back(i + 1, nowh);
      ans.emplace_back(it->second, nowh);
      for2.erase(it->first);
      for3.erase(it);
      // for2[nowh] = i + 1;
      for3[nowh] = i + 1;
      // avail[nowh] = i + 1;
    }
  }

  cout << ans.size() << '\n';
  for (auto [a, b] : ans)
    cout << n - b + 1 << " " << a << '\n';

  return 0;
}