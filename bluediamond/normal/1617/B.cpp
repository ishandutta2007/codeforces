#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, x = 2;
    cin >> n;
    while (1) {
      int y = n - 1 - x;
      if (__gcd(x, y) == 1) {
        cout << x << " " << y << " " << 1 << "\n";
        break;
      }
      x++;
    }

  }

  return 0;
}