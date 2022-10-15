#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct T {
  int x, y;
};

const int N = (int) 1e5 + 7;
const ld eps = 1e-14;
int n, poz, neg;
T a[N];

bool ok(ld r) {
  ld y = r;
  ld lmax = -(ld) 1e18, rmin = -lmax;
  for (int i = 1; i <= n; i++) {
    ld x1 = a[i].x, y1 = a[i].y;
    ld dif = 2 * y1 * r - y1 * y1;
    if (dif < -eps) return 0;
    dif = sqrt(dif);
    lmax = max(lmax, x1 - dif);
    rmin = min(rmin, x1 + dif);
    if (lmax - rmin > eps) return 0;
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    poz += (a[i].y > 0);
    neg += (a[i].y < 0);
  }
  if (poz > 0 && neg > 0) {
    cout << "-1\n";
    return 0;
  }
  if (neg > 0) for (int i = 1; i <= n; i++) a[i].y *= -1;
  ld l = 0, r = 50000000000000;
  for (int test = 1; test <= 100; test++) {
    ld mid = (l + r) * 0.5;
    if (ok(mid)) r = mid;
    else l = mid;
  }
  cout << fixed << setprecision(6) << l << "\n";
}