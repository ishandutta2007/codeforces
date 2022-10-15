#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ll sqr(ll x) {
  return x * x;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << sqr(min(max(2 * b, a), max(2 * a, b))) << "\n";
  }

  return 0;
}