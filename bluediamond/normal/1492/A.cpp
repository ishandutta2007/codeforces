#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int ll

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int p, a, b, c; cin >> p >> a >> b >> c;
    cout << min({(p + a - 1) / a * a, (p + b - 1) / b * b, (p + c - 1) / c * c}) - p << "\n";
  }
}