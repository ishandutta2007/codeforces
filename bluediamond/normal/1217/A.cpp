#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int a, b, c;
    cin >> a >> b >> c;
    int mn = max((b + c - a + 2) / 2, 0), mx = c;
    cout << max(0, mx - mn + 1) << '\n';
  }

  return 0;
}