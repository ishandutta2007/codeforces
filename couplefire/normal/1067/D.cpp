#include <bits/stdc++.h>

using namespace std;

typedef double ld;
typedef long long ll;

vector<pair<ld, ld>> convex_hull(vector<pair<ld, ld>> points) {
  vector<pair<ld, ld>> hull;
  for (auto p : points) {
    if (!hull.empty() && hull.back().first == p.first) {
      hull.pop_back();
    }
    while (hull.size() > 1 && (hull[hull.size() - 1].first - hull[hull.size() - 2].first) * (p.second - hull[hull.size() - 2].second) >= (hull[hull.size() - 1].second - hull[hull.size() - 2].second) * (p.first - hull[hull.size() - 2].first)) {
      hull.pop_back();
    }
    hull.push_back(p);
  }
  return hull;
}

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  ll t;
  cin >> n >> t;
  vector<pair<ld, ld>> points;
  ld s = 0;
  for (int i = 0; i < n; ++i) {
    int a, b;
    ld p;
    cin >> a >> b >> p;
    s = max(s, b * p);
    points.emplace_back(p, a * p);
  }
  sort(points.begin(), points.end());
  points = convex_hull(points);
  ll index = 0;
  ld value = 0;

  auto sum1 = [&](ld q, ll n) {
    return (1 - pow(q, n)) / (1 - q);
  };

  auto sum2 = [&](ld q, ll n) {
    return (sum1(q, n) - 1 - (n - 1) * pow(q, n)) / (1 - q);
  };
  
  auto check = [&](ll from, ll to, ld value, ld x, ld y) {
    if (from == to) {
      return value;
    }
    ld result = pow(1 - x, to - from) * value;
    result += (y + x * s * (to - 1)) * sum1(1 - x, to - from);
    result -= x * s * sum2(1 - x, to - from);
    return result;
  };

  for (int i = 0; i < points.size(); ++i) {
    ll l = index, r = t - 1, result = t;
    if (i == points.size() - 1) {
      l = t;
    }
    while (l <= r) {
      ll mid = l + r >> 1;
      if ((points[i].second - points[i + 1].second) / (points[i + 1].first - points[i].first) <= s * mid - check(index, mid, value, points[i].first, points[i].second)) {
        result = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    value = check(index, result, value, points[i].first, points[i].second);
    index = result;
  }
  cout << fixed << setprecision(20) << value << endl;
  return 0;
}