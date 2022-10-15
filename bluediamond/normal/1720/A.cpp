#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
 ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 /// freopen ("___input___.txt", "r", stdin);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    /// a / b = c / d
    /// a * d = b * c
    if (a * d == b * c) {
      cout << "0\n";
      continue;
    }
    ///cout << "???\n";
    a *= d;
    b *= c;
    if (a == 0 || b == 0) {
      cout << "1\n";
      continue;
    }
    if (a % b == 0 || b % a == 0) {
      cout << "1\n";
    } else {
      cout << "2\n";
    }
  }

  return 0;
}