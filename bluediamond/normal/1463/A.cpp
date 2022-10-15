#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

bool ok(int a, int b, int c, int k) {
  int all = k / 7;
  int normal = k - all;
  a -= all;
  b -= all;
  c -= all;
  a = max(a, 0LL);
  b = max(b, 0LL);
  c = max(c, 0LL);
  return a + b + c <= normal;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int l = 0, r = (int) 1e9, k = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (ok(a, b, c, m)) {
        k = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    int all = k / 7;
    int normal = k - all;
    a -= all;
    b -= all;
    c -= all;
    if (k % 7 == 0 && a >= 0 && b >= 0 && c >= 0 && a + b + c == normal) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}