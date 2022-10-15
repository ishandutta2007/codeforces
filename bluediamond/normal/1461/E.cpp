#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
#define int long long
const int INF = (int) 3e18;
int l, r, alpha, beta;

int mult(int a, int b) {
  if (a == 0 || b == 0) return 0;
  if (a == INF || b == INF) return INF;
  int c = a * b;
  if (c % a == 0 && c / a == b && c <= INF) return c;
  else return INF;
}

bool okay(int k, int t) {
  if (t == 0) {
    return 1;
  }
  if (k <= r) {
    if (alpha <= 0) {
      return k - l >= mult(-alpha, t);
    } else {
      /// k + alpha * (c - 1) <= r
      /// alpha * (c - 1) <= r - k
      int c = (r - k) / alpha + 1;
      c = min(c, t);
      k += alpha * c;
      return okay(k, t - c);
    }
  }
  /// beta <= 0
  /// k + beta * (c - 1) >= r + 1
  int c = (r + 1 - k) / beta + 1;
  c = min(c, t);
  k += beta * c;
  if (k < l) {
    return 0;
  }
  return okay(k, t - c);
}

signed main() {
  ios::sync_with_stdio(0);cin.tie(0);

///  freopen ("input", "r", stdin);

  int k, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  alpha = y - x;
  beta = -x;
  r -= y;
  if (okay(k, t)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}