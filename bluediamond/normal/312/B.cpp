#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ld a, b, c, d, p1, p2;
  cin >> a >> b >> c >> d;
  p1 = a / b;
  p2 = c / d;
  cout << fixed << setprecision(6) << p1 / (p1 + p2 - p1 * p2) << "\n";


}