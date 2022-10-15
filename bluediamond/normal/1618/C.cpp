#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<ll>> a(2);
    vector<ll> g(2);
    for (int i = 0; i < n; i++) {
      ll x;
      cin >> x;
      a[i % 2].push_back(x);
      g[i % 2] = __gcd(g[i % 2], x);
    }
    ll sol = 0;
    for (int it = 0; it < 2; it++) {
      bool ok = true;
      for (auto &x : a[it ^ 1]) {
        ok &= (x % g[it] != 0);
      }
      if (ok) {
        sol = g[it];
      }
    }
    cout << sol << "\n";
  }

  return 0;
}