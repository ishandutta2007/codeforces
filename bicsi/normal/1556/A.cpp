#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int a = 0, b = 0, c, d; cin >> c >> d;
    if ((a + b + c + d) % 2) cout << -1 << '\n';
    else {
      if (a == c && b == d) cout << 0 << '\n';
      else {
        if (a + c == b + d) cout << 1 << '\n';
        else if (a - c == b - d) cout << 1 << '\n';
        else cout << 2 << '\n';
      }
    }
  }

  return 0;
}