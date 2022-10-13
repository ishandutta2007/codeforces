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
    int n, k; cin >> n >> k;
    set<int> all;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      all.insert(v[i]);
    }
    if (all.size() > k) {
      cout << -1 << '\n';
    } else {
      cout << k * n << '\n';
      for (int i = 0; i < n; ++i) {
        for (auto x : all)
          cout << x << " ";
        for (int j = all.size(); j < k; ++j)
          cout << *all.begin() << " ";
      }
      cout << '\n';
    }
  }


  return 0;
}