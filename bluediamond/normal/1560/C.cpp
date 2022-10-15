#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, location;
    cin >> n;
    location = sqrt(n - 1) + 1;
    n = n - (location - 1) * (location - 1);
    if (n <= location) {
      cout << n << " " << location << "\n";
    } else {
      cout << location << " " << 2 * location - n << "\n";
    }
  }
  return 0;
}