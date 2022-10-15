/**

48 -> 8:17
43 -> 8:33
42 -> 8:42
41 -> 8:47
39 -> 8:54
37 -> 9:06
36 -> 9:13
**/

#include <bits/stdc++.h>

using namespace std;

int tt, n, m;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    vector<int> a(n * m);
    for (auto &x : a) {
      cin >> x;
    }
    int sol = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < i; j++) {
        sol += (a[j] < a[i]);
      }
    }
    cout << sol << "\n";
  }

  return 0;
}
/// 2 3 2 1 1 1