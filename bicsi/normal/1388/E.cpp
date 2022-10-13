#include <bits/stdc++.h>
 
using namespace std;
 
struct Point {
  int x, y;
  bool operator<(const Point& oth) const {
    if (y == 0 && oth.y == 0) return x < oth.x;
    return 1LL * x * oth.y < 1LL * y * oth.x;
  }
};
 
int main() {
  int n; cin >> n;
  vector<tuple<int, int, int>> segs;
  for (int i = 0; i < n; ++i) {
    int x1, x2, y; cin >> x1 >> x2 >> y;
    segs.emplace_back(y, x1, x2);
  }
 
  sort(segs.begin(), segs.end());
 
  vector<Point> minl(n, Point{-1, 0}), maxl(n, Point{-1, 0}), 
    minr(n, Point{1, 0}), maxr(n, Point{1, 0});
  vector<tuple<Point, int, int>> evs;
  evs.emplace_back(Point{0, 1}, 3, 0);
  for (int i = 0; i < n; ++i) {
    auto [ay, ax1, ax2] = segs[i];
    for (int j = i + 1; j < n; ++j) {
      auto [by, bx1, bx2] = segs[j];
      if (by == ay) {
        maxl[i] = Point{1, 0};
        maxr[i] = Point{-1, 0};
        minl[j] = Point{1, 0};
        minr[j] = Point{-1, 0};
      } else {
        Point p1{bx1 - ax2, by - ay};
        evs.emplace_back(p1, 4, 0);
        maxr[j] = min(maxr[j], p1);
        minr[i] = min(minr[i], p1);
        Point p2{bx2 - ax1, by - ay};
        evs.emplace_back(p2, 2, 0);
        minl[j] = max(minl[j], p2);
        maxl[i] = max(maxl[i], p2);
        evs.emplace_back(p1, 3, 0);
        evs.emplace_back(p2, 3, 0);
      }
    }
  }
  
  for (int i = 0; i < n; ++i) {
    if (!(minr[i] < minl[i])) 
      evs.emplace_back(minl[i], 0, i);
    if (!(maxr[i] < maxl[i])) 
      evs.emplace_back(maxl[i], 1, i);
  }
  
  sort(evs.begin(), evs.end());
  int cnt = 0, li = -1, ri = -1;
  double best = 4e18;
  for (auto [at, tp, i] : evs) {
    if (tp == 0) li = i;
    if (tp == 1) ri = i;
    if (tp == 2) cnt -= 1;
    if (tp == 3 && !cnt) {
      auto [yl, x1l, x2l] = segs[li];
      auto [yr, x1r, x2r] = segs[ri];
      double lo = x1l - 1.0 * yl * at.x / at.y;
      double hi = x2r - 1.0 * yr * at.x / at.y;
      best = min(best, hi - lo);
    }
    if (tp == 4) cnt += 1;
  }
  cout << fixed << setprecision(20) << best << endl;
  return 0;
}