#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] = (1 << 30) - 1 - a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    int mask = 0;
    for (int bit = 29; bit >= 0; bit--) {
      mask += (1 << bit);
      map<int, int> f;
      for (auto &x : a) {
        f[x & mask]++;
      }
      for (auto &x : b) {
        f[x & mask]--;
      }
      bool ok = 1;
      for (auto &it : f) {
        ok &= (it.second == 0);
      }
      if (!ok) {
        mask -= (1 << bit);
      }
    }
    cout << mask << "\n";
  }
  return 0;
}