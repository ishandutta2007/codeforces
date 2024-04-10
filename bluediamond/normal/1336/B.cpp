#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll sol = (ll) 5e18;
    vector<vector<int>> v(3);
    vector<int> l(3);
    cin >> l[0] >> l[1] >> l[2];
    for (int i = 0; i < 3; i++) {
      v[i].resize(l[i]);
      for (auto &x : v[i]) {
        cin >> x;
      }
      sort(v[i].begin(), v[i].end());
    }
    function<vector<int>(int, int)> f = [&] (int id, int val) {
      if (v[id].back() < val) {
        vector<int> sol;
        sol.push_back(v[id].back());
        return sol;
      }
      vector<int> sol;
      int l = 0, r = (int) v[id].size() - 1, pos = -1;  /// minimul >= val
      while (l <= r) {
        int m = (l + r) / 2;
        if (v[id][m] >= val) {
          pos = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      assert(pos != -1);
      sol.push_back(v[id][pos]);
      if (pos >= 1) {
        sol.push_back(v[id][pos - 1]);
      }
      return sol;
    };
    function<ll(ll, ll, ll)> get = [&] (ll x, ll y, ll z) {
      return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
    };
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i != j) {
          int k = 3 - i - j;
          for (auto &x : v[i]) {
            vector<int> vals = f(j, x);
            for (auto &y : vals) {
              vector<int> vals2 = f(k, y);
              for (auto &z : vals2) {
                sol = min(sol, get(x, y, z));
              }
            }
          }
        }
      }
    }
    cout << sol << "\n";
  }

}