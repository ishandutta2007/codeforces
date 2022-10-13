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
    vector<int> v(n + 1);
    long long total = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> v[i];
      total += v[i];
    }

    if (total % n) {
      cout << -1 << '\n';
      continue;
    }

    int req = total / n;

    vector<tuple<int, int, int>> ans;
    auto pour = [&](int i, int j, int x) {
      ans.emplace_back(i, j, x);
      v[i] -= x * i;
      v[j] += x * i;
      assert(v[i] >= 0);
    };

    for (int i = 2; i <= n; ++i) {
      int rem = v[i] % i;
      if (rem) {
        assert(v[1] >= i - rem);
        pour(1, i, i - rem);
      }
      assert(v[i] % i == 0);
      pour(i, 1, v[i] / i);
    }

    for (int i = 2; i <= n; ++i)
      pour(1, i, req);
    
    cout << ans.size() << '\n';
    for (auto [i, j, x] : ans) {
      cout << i << " " << j << " " << x << '\n';
    }

    // for (int i = 1; i <= n; ++i) cerr << v[i] << " "; cerr << endl;
  }

  return 0;
}