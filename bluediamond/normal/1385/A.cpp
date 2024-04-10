#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, y, z;
    cin >> x >> y >> z;
    ll a = min(x, y);
    ll b = min(x, z);
    ll c = min(y, z);
    if (max(a, b) == x && max(a, c) == y && max(b, c) == z) {
      cout << "YES\n";
      cout << a << " " << b << " " << c << "\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}