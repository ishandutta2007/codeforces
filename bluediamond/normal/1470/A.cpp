#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> k(n), c(m);
    for (auto &x : k) {
      cin >> x;
      x--;
    }
    for (auto &x : c) {
      cin >> x;
    }
    sort(k.rbegin(), k.rend());
    ll ret = 0;
    int p = 0;
    for (auto &x : k) {
      if (p < x) {
        ret += c[p++];
      } else {
        ret += c[x];
      }
    }
    cout << ret << "\n";
  }
}