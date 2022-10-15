/// 507 -> 508
#include <bits/stdc++.h>

using namespace std;




int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input.txt", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      a[i % 2][x] = max(a[i % 2][x], a[1 - (i % 2)][x] + 1);
    }
    for (int i = 0; i < n; i++) {
      cout << max(a[0][i], a[1][i]) << " ";
    }
    cout << "\n";
  }

}