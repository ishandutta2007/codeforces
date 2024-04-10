#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct point {
  int x;
  int y;
};

bool dir(point a, point b, ld x, ld y) {
  return (ld) (b.x - a.x) * (y - a.y) - (ld) (b.y - a.y) * (x - a.x) > 0;
}

ld dist(point a, ld x, ld y) {
  ld dx = a.x - x;
  ld dy = a.y - y;
  return sqrt(dx * dx + dy * dy);
}

const int N = (int) 2e5 + 7;
int n;
int h;
point a[N];
point p;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> h;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  p = {a[n].x, a[n].y + h};

  ld sol = 0;
  int j = n;
  for (int i = n - 1; i >= 1; i--) {
    ld x1 = a[i].x, y1 = a[i].y;
    ld x2 = a[i + 1].x, y2 = a[i + 1].y;
    if (dir(p, a[j], a[i].x, a[i].y)) {
      x1 = a[i].x;
      y1 = a[i].y;
    } else {
      for (int it = 1; it <= 30; it++) {
        ld xm = (x1 + x2) * 0.5, ym = (y1 + y2) * 0.5;
        if (!dir(p, a[j], xm, ym)) {
          x1 = xm;
          y1 = ym;
        } else {
          x2 = xm;
          y2 = ym;
        }
      }
    }
    if (!dir(p, a[j], a[i].x, a[i].y)) {
      j = i;
    }
    sol += dist(a[i], x1, y1);
  }
  cout << fixed << setprecision(9) << sol << "\n";
}