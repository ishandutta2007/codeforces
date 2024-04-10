#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 1) {
      cout << 1 << " " << 1 << endl;
      continue;
    }
    int ans1 = -1;
    int ans2 = -1;
    if (x == 1) {
      if (y == n) {
        ans1 = 2;
        ans2 = n;
      } else {
        ans1 = 1;
        ans2 = y;
      }
    } else if (y == n) {
      assert(x != 1);
      ans1 = min(n, x + 1);
      ans2 = n;
    } else {
      if (x - 1 < n - y) {
        ans1 = 1;
        ans2 = n - ((n - y) - (x - 1));
      } else {
        ans1 = ((x - 1) - (n - y)) + 2;
        ans2 = n;
      }
    }
    ans1 = min(ans1, n);
    ans2 = min(ans2, n);
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}