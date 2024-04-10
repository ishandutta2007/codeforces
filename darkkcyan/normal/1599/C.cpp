#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ld p;
  cin >> n >> p;
  p *= 6;
  for (int k = 0; k <= n; k++) {
    ld pr = k * 1.0l * (k - 1) * (k - 2);
    pr += k * 1.0l * (k - 1) * (n - k) * 3;
    pr += k * 1.0l * (n - k - 1) * (n - k) * 3 * 0.5;
    pr *= 6;
    if (pr >= p * n * 1.0l * (n - 1) * (n - 2)) {
      cout << k << endl;
      return 0;
    }
  }
  return 0;
}