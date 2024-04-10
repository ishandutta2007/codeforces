#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  if (n == 1) {
    return 0;
  }
  if (n == 2) {
    return 1;
  }
  if (n == 3) {
    return 2;
  }
  if (n % 2 == 0) {
    return 2;
  } else {
    return 3;
  }
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << solve(n) << "\n";
  }

}