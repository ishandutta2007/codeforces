/// 486 -> 487
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    int n, s = -1;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    for (int i = 0; i < n; i++) {
      int nd = 0;
      for (int j = 0; j < n; j++) {
        if (i != j) {
          nd ^= (a[j]);
        }
      }
      if (nd == a[i]) {
        s = a[i];
        break;
      }
    }
    assert(s != -1);
    cout << s << "\n";
  }
}