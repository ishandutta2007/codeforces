/// 483 -> 484
#include <bits/stdc++.h>

using namespace std;


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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int l = 0, sol = 0;
    while (l < n) {
      if (a[l] == 0) {
        l++;
        continue;
      }
      int r = l;
      while (r + 1 < n && a[r + 1] != 0) {
        r++;
      }
      sol++;
      l = r + 1;
    }
    cout << min(2, sol) << "\n";
  }
}