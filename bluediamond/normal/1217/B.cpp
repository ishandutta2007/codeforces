#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, x, mx = 0, dif = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
      int a, b;
      cin >> a >> b;
      mx = max(mx, a);
      dif = max(dif, a - b);
    }
    if (x - mx <= 0) {
      cout << "1\n";
      continue;
    }
    if (dif == 0) {
      cout << "-1\n";
      continue;
    }
    cout << (x - mx) / dif + (((x - mx) % dif ) > 0) + 1 << '\n';
  }

  return 0;
}