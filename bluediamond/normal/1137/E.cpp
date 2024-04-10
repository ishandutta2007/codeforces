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

struct point {
  int x, y;
};

ld f(point a, point b) {
  return (ld) (a.x - b.x) * (ld) (a.y + b.y);
}

bool func(point a, point b, point c) {
  return f(a, b) + f(b, c) + f(c, a) < 0;
}

int n, m, a, b;

signed realMain() {
  cin >> n >> m;
  vector<point> hull = {{0, 0}};
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int k;
      cin >> k;
      hull = {{0, 0}};
      n += k;
      a = b = 0;
    }
    if (type == 2) {
      int k;
      cin >> k;
      point p = {n, -(a * n + b)};
      while ((int) hull.size() >= 2 && func(hull[(int) hull.size() - 2], hull[(int) hull.size() - 1], p)) {
        hull.pop_back();
      }
      hull.push_back(p);
      n += k;
    }
    if (type == 3) {
      int ff, ss;
      cin >> ff >> ss;
      a += ss;
      b += ff;
    }
    while ((int) hull.size() >= 2 && a * hull[(int) hull.size() - 2].x + hull[(int) hull.size() - 2].y <= a * hull[(int) hull.size() - 1].x + hull[(int) hull.size() - 1].y) {
      hull.pop_back();
    }
    cout << hull.back().x + 1 << " " << hull.back().x * a + hull.back().y + b << "\n";
  }
  return 0;
}