#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 2050) {
      cout << "-1\n";
    } else {
      n /= 2050;
      int sum = 0;
      while (n) {
        sum += n % 10;
        n /= 10;
      }
      cout << sum << "\n";
    }
  }
  return 0;
}