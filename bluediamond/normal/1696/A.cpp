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
    int n, z;
    cin >> n >> z;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    int sol = 0;
    for (auto &x : a) {
      sol = max(sol, x | z);
    }
    cout << sol << "\n";
  }
}