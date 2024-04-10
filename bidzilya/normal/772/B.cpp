#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using namespace std::chrono;

const long double INF = 1e+18;

struct point_t {
  int x, y;
};

long double sqr(long double x) {
  return x * x;
}

long double get_dist(const point_t& a, const point_t& b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

long double get_dist(const point_t& a, const point_t& b, const point_t& c) {
  long double A = (b.y - a.y);
  long double B = (a.x - b.x);
  long double C = -a.y * B - a.x * A;

  long double len = sqrt(sqr(A) + sqr(B));
  A /= len;
  B /= len;
  C /= len;

  return abs(A * c.x + B * c.y + C);
}

int main() {
  auto start = high_resolution_clock::now();

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  vector<point_t> vp(n);
  for (int i = 0; i < n; ++i)
    cin >> vp[i].x >> vp[i].y;

  long double ans = INF;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    ans = min(ans, get_dist(vp[i], vp[j]) / 2);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;

      int p = (i + 1) % n;
      if (p != j && p != i)
        ans = min(ans, get_dist(vp[i], vp[j], vp[p]) / 2);
      p = (i + n - 1) % n;
      if (p != j && p != i)
        ans = min(ans, get_dist(vp[i], vp[j], vp[p]) / 2);

      p = (j + 1) % n;
      if (p != j && p != i)
        ans = min(ans, get_dist(vp[i], vp[j], vp[p]) / 2);
      p = (j + n - 1) % n;
      if (p != j && p != i)
        ans = min(ans, get_dist(vp[i], vp[j], vp[p]) / 2);
    }
  }

  cout << ans << endl;

  cerr << "Total execution time : " << duration_cast<milliseconds>(high_resolution_clock::now() - start).count() << " ms" << endl;

  return 0;
}