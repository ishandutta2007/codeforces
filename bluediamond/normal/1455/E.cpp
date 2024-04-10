#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

const ll INF = (ll) 1e18 + 7;

struct Point {
  ll x, y;
};

bool operator < (Point a, Point b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

ll evaluate_median(vector<ll> v) {
  assert((int) v.size() == 4);
  sort(v.begin(), v.end());
  ll x = v[1], sol = 0;
  for (auto &val : v) {
    sol += abs(x - val);
  }
  return sol;
}

ll get(vector<Point>& points, ll len) {
  return evaluate_median({points[0].x, points[1].x + len, points[2].x, points[3].x + len}) + evaluate_median({points[0].y, points[1].y, points[2].y + len, points[3].y + len});
}

ll get(vector<Point>& points) {
  assert((int) points.size() == 4);
  ll low = 1, high = (ll) 1e9, sol = INF, steps = 0;
  while (low <= high) {
    steps++;
    assert(steps <= 40);
    ll mid = (low + high) / 2;
    ll f1 = get(points, mid);
    ll f2 = get(points, mid + 1);
    sol = min(sol, f1);
    sol = min(sol, f2);
    if (f1 > f2) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return sol;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int tests;
  cin >> tests;

  for (int tc = 1; tc <= tests; tc++) {
    vector<Point> points(4);
    for (auto &p : points) {
      cin >> p.x >> p.y;
    }
    sort(points.begin(), points.end());
    ll sol = get(points);
    while (next_permutation(points.begin(), points.end())) {
      sol = min(sol, get(points));
    }
    cout << sol << "\n";
  }

}