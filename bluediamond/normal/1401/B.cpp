#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a[3], b[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    int t = min(a[2], b[1]), sol = 0;
    a[2] -= t;
    b[1] -= t;
    sol += t * 2;
    int lol = min(a[1], b[0] + b[1]);
    a[1] -= lol;
    sol -= 2 * min(a[1], b[2]);
    cout << sol << "\n";
  }
  return 0;
}