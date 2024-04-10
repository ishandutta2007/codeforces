
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
    vector<vector<int>> a(2, vector<int> (2, 0));
    int sum = 0;
    for (auto &v : a) {
      for (auto &x : v) {
        cin >> x;
        sum += x;
      }
    }
    if (sum == 0 || sum == 4) {
      cout << sum / 2 << "\n";
    } else {
      cout << "1\n";
    }

  }
}