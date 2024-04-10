#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1000 + 7;
int n, m, a[N][N], x, y;
bool home;

int ask(int h, int w, int r1, int c1, int r2, int c2) {
  if (home) {
    /**for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << a[r1 + i][c1 + j] << " ";
      }
      cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cout << a[r2 + i][c2 + j] << " ";
      }
      cout << "\n";
    }
    cout << "------\n";**/
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (a[r1 + i][c1 + j] != a[r2 + i][c2 + j]) {
          return 0;
        }
      }
    }
    return 1;
  }
  cout << "? " << h << " " << w << " " << r1 << " " << c1 << " " << r2 << " " << c2 << endl;
  int ret;
  cin >> ret;
  return ret;
}

signed main() {
  home = 0;
  if (home) {
    freopen ("input", "r", stdin);
  }
  cin >> n >> m;
  if (home) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
  }
  {
    x = 1;
    int num = n, cnt = 0;
    while (num % 2 == 0) {
      num /= 2;
      cnt++;
    }
    int rgh = n;
    for (int i = 1; i <= cnt; i++) {
      int half = rgh / 2;
      if (ask(half, m, 1, 1, half + 1, 1)) {
        x *= 2;
        rgh /= 2;
      } else {
        break;
      }
    }
    for (int d = 3; d <= num; d++) {
      int cnt = 0;
      while (num % d == 0) {
        num /= d;
        cnt++;
      }
      int rgh = n;
      for (int i = 1; i <= cnt; i++) {
        /// can I cut the segment [1, rgh] in d equal parts?
        /// x x x x x x
        int cnt = d / 2;
        int mul = (rgh / d);
        if (ask(cnt * mul, m, 1, 1, mul * cnt + 1, 1) && ask(cnt * mul, m, 1, 1, mul * (cnt + 1) + 1, 1)) {
          x *= d;
          rgh /= d;
        } else {
          break;
        }
      }
    }
  }
  {
    y = 1;
    int num = m, cnt = 0;
    while (num % 2 == 0) {
      num /= 2;
      cnt++;
    }
    int rgh = m;
    for (int i = 1; i <= cnt; i++) {
      int half = rgh / 2;
      if (ask(n, half, 1, 1, 1, half + 1)) {
        y *= 2;
        rgh /= 2;
      } else {
        break;
      }
    }
    for (int d = 3; d <= num; d++) {
      int cnt = 0;
      while (num % d == 0) {
        num /= d;
        cnt++;
      }
      int rgh = m;
      for (int i = 1; i <= cnt; i++) {
        /// can I cut the segment [1, rgh] in d equal parts?
        /// x x x x x x
        int cnt = d / 2;
        int mul = (rgh / d);
        if (ask(n, mul * cnt, 1, 1, 1, mul * cnt + 1) && ask(n, mul * cnt, 1, 1, 1, mul * (cnt + 1) + 1)) {
          y *= d;
          rgh /= d;
        } else {
          break;
        }
      }
    }
  }
  assert(x);
  assert(y);
  x = n / x;
  y = m / y;
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0 && i % x == 0) {
      cnt1++;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (m % i == 0 && i % y == 0) {
      cnt2++;
    }
  }
  cout << "! " << cnt1 * cnt2 << endl;

}