#include <bits/stdc++.h>

using namespace std;

typedef long double ld;


ld base_size(ld x, ld n) {
  return (n - x) / n;
}

ld trapez_area(ld x, ld n) {
  ld b1 = base_size(x, n);
  ld b2 = base_size(x + 1, n);

  /**

  ((n - x) / n + (n - x - 1) / n) / 2 = value
  (2 * n - 2 * x - 1) / n = 2 * value
  2 * n - 2 * x - 1 = 2 * n * value
  2 * n - 2 * n * value - 1 = 2 * x
  x = (2 * n - 2 * n * value - 1) / 2

  **/

}

ld get(vector<pair<ld, ld>> pts) {
  cout << "? " << (int) pts.size() << endl;
  for (auto &it : pts) {
    cout << fixed << setprecision(6) << it.first << " " << it.second << endl;
  }
  ld sol;
  cin >> sol;
  return sol;
}

const ld eps = 1e-7;

void check_is(ld l, ld r, ld x) {
  assert(l <= x && x <= r);
}

int n, m;


signed main() {
  cin >> n >> m;
  vector<pair<ld, ld>> pts;
  pts.push_back({0, -1});
  for (int i = 0; i < n; i++) {
    pts.push_back({(ld) i, 0});
    pts.push_back({(ld) i + 0.5, m});
  }
  pts.push_back({(ld) n, 0});
  pts.push_back({(ld) n, -1});

  ld value = get(pts);
  ld x = (2 * (ld) m - 2 * (ld) m * value - 1) / 2;

  pts.clear();
  pts.push_back({0, -1});
  for (int i = 0; i < m; i++) {
    pts.push_back({0, (ld) i});
    pts.push_back({n, (ld) i + 0.5});
  }
  pts.push_back({0, (ld) m});
  pts.push_back({-1, (ld) m});

  value = get(pts);
  ld y = (2 * (ld) n - 2 * (ld) n * value - 1) / 2;

  cout << "! " << fixed << setprecision(6) << y << " " << x << endl;

  return 0;
}