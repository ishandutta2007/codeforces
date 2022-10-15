#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c, eq;
    cin >> a >> b >> c >> eq;
    int mx = a - 1 + b - 1 + c - 1;
    int mn = mx + 1;
    /// a = max
    if (b > a) swap(a, b);
    if (c > a) swap(a, c);
    assert(a >= c && a >= b);

    int places_for_a = b + c + 1;
    mn = max(0, a - places_for_a);

    if (mn <= eq && eq <= mx) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}