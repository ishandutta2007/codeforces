#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

bool ok(int r, int c, int r2, int c2) {
  if (r > r2 || c > c2) return 0;
  return (c2 - c) <= r2 - r;
}


int dist(int r, int c, int r2, int c2) {
  assert(ok(r, c, r2, c2));
  int sol = 0;
  for (int i = r; i <= r2 - 1; i++) {
    if ((i + c) % 2 == 0) {
      if (ok(i + 1, c, r2, c2)) {
        continue;
      }
      sol++;
      c++;
    } else {
      if (ok(i + 1, c + 1, r2, c2)) {
        c++;
        continue;
      }
      sol++;
    }
  }
  assert(c == c2);
  return sol;
}

int nr = 0;

int f(int r, int c, int r2, int c2) {
  int init = (r + c) % 2, x = c2 - c, y = (r2 - r) - x;
  /// init = 0 => primul x = free
  /// init = 1 => primul y = free
  if (init == 0) {
    if (x == 0) {
      return y / 2;
    }
    if (!ok(r + 1, c, r2, c2)) return c2 - c;
    return y / 2;
  } else {
    return (y + 1) / 2;
  }
  nr++;
 /// return dist(r, c, r2, c2);
}

const int N = (int) 2e5 + 7;
int n, r[N], c[N];

int dist(int i) {
  return f(r[i - 1], c[i - 1], r[i], c[i]);
  ///return dist(r[i - 1], c[i - 1], r[i], c[i]);
}

signed realMain() {
  /**int cnt = 0, ct = 30;
  for (int r = 1; r <= ct; r++) {
    for (int r2 = 0; r2 <= ct; r2++) {
      for (int c = 1; c <= r; c++) {
        for (int c2 = 1; c2 <= r2; c2++) {
          if (!ok(r, c, r2, c2)) continue;
          cnt++;
          int d = dist(r, c, r2, c2);
          int d2 = f(r, c, r2, c2);
          if (d != d2) {
            cout << "WA!\n";
            cout << r << " " << c << " and " << r2 << " " << c2 << "\n";
            cout << d << "\n";
            cout << d2 << "\n";
            return 0;
          }
          //assert(d == d2);
        }
      }
    }
  }
  cout << "OK!\n";
  cout << cnt << "\n";
  cout << "to do : " << nr << "\n";
  return 0;**/
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first;
    for (auto &x : a) cin >> x.second;
    sort(a.begin(), a.end());
    r[0] = c[0] = 1;
    for (int i = 1; i <= n; i++) {
      r[i] = a[i - 1].first;
      c[i] = a[i - 1].second;
    ///  cout << r[i] << " " << c[i] << "\n";
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
      ret += dist(i);
    }
    cout << ret << "\n";
  }
  return 0;
}