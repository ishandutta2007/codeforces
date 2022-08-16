/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;
const ld inf = 1e18 + 42;

struct pt {
  ll x, y;
  bool operator<(const pt& o) const {
    return tie(x, y) < tie(o.x, o.y);
  }
  bool operator==(const pt& o) const {
    return tie(x, y) == tie(o.x, o.y);
  }
  ll dist2(const pt& o) {
    return (x - o.x) * (x - o.x) + (y - o.y) * (y - o.y);
  }
  ld dist(const pt& o) {
    return sqrt(dist2(o));
  }
};

bool on_line(pt& p1, pt& p2, pt& p3);

int main() {
  fast_cin();
  int n, k;
  cin >> n >> k;
  vector<pt> pts(n);
  for (auto& p : pts) {
    cin >> p.x >> p.y;
  }
  pt start = pts[k - 1];
  sort(pts.begin(), pts.end());
  int odd_id = 0;
  if (pts.size() > 3) {
    for (int i = 0; i < n; ++i) {
      vector<int> other;
      for (int j = 0; j < n and other.size() < 3; ++j) {
        if (i != j) {
          other.pb(j);
        }
      }
      bool ok = false;
      ok |= on_line(pts[i], pts[other[0]], pts[other[1]]);
      ok |= on_line(pts[i], pts[other[0]], pts[other[2]]);
      ok |= on_line(pts[i], pts[other[1]], pts[other[2]]);
      if (!ok) {
        odd_id = i;
        break;
      }
    }
  }
  pt odd = pts[odd_id];
  pts.erase(pts.begin() + odd_id);
  n = pts.size();
  ld tmp = inf;
  for (int i = 0; i < n; ++i) {
    if (pts[i] == start) {
      if (i > 0 and i < n - 1) {
        tmp = min(tmp, start.dist(pts[0]) + pts[0].dist(odd) + odd.dist(pts[i + 1]) + pts[i + 1].dist(pts.back()));
        tmp = min(tmp, start.dist(pts.back()) + pts.back().dist(odd) + odd.dist(pts[i - 1]) + pts[i - 1].dist(pts[0]));
      }
      pts.erase(pts.begin() + i);
      n = pts.size();
      break;
    }
  }
  ld line_length = pts[0].dist(pts.back());
  ld start_odd = start.dist(odd);
  ld start_p1 = start.dist(pts[0]);
  ld start_pn = start.dist(pts.back());
  ld odd_p1 = odd.dist(pts[0]);
  ld odd_pn = odd.dist(pts.back());
  ld to_odd_and_back = inf;
  for (int i = 0; i < n - 1; ++i) {
    to_odd_and_back = min(to_odd_and_back, pts[i].dist(odd) + odd.dist(pts[i + 1]) - pts[i].dist(pts[i + 1]));
  }
  ld ans = min({start_odd + odd_p1 + line_length,
                start_odd + odd_pn + line_length,
                start_p1 + line_length + odd_pn,
                start_pn + line_length + odd_p1,
                start_p1 + to_odd_and_back + line_length,
                start_pn + to_odd_and_back + line_length,
                tmp
              });
  cout << fixed << setprecision(10) << ans << endl;
}

bool on_line(pt& p1, pt& p2, pt& p3) {
  return (p2.x - p1.x) * (p3.y - p2.y) == (p3.x - p2.x) * (p2.y - p1.y);
}