#include <bits/stdc++.h>
#define int long long 

using namespace std;

int dist(int x0, int y0, int x1, int y1) {
  return abs(x0 - x1) + abs(y0 - y1);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int x0, y0, ax, ay, bx, by; cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  int xs, ys, t; cin >> xs >> ys >> t;
  
  vector<pair<int, int>> pts = {{x0, y0}};
  while (true) {
    int nx = pts.back().first * ax + bx;
    int ny = pts.back().second * ay + by;
    if (nx > 3e16 || ny > 3e16) break;
    pts.emplace_back(nx, ny);
  }

  int best = 0;
  for (int it = 0; it < 2; ++it) {
    for (int i = 0; i < (int)pts.size(); ++i) {
      int now_t = t - dist(xs, ys, pts[i].first, pts[i].second);
      for (int j = i; j < (int)pts.size(); ++j) {
        if (now_t < 0) break;
        best = max(best, j - i + 1);
        if (j + 1 == (int)pts.size()) break;
        now_t -= dist(pts[j].first, pts[j].second, pts[j + 1].first, pts[j + 1].second);
      }
    }
    reverse(pts.begin(), pts.end());
  }
  cout << best << endl;


  return 0;
}