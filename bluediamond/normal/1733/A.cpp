#include <bits/stdc++.h>

using namespace std;


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, k;
    cin >> n >> k;
    vector<int> biggest(k, 0);
    for (int i = 0; i < n; i++) {
      int foo;
      cin >> foo;
      biggest[i % k] = max(biggest[i % k], foo);
    }
    cout << accumulate(biggest.begin(), biggest.end(), 0LL) << "\n";
  }
}