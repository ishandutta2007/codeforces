#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct pt {
  ll x, y;

  pt(ll x, ll y) : x(x), y(y) {}

  pt() = default;
};

pt operator-(const pt &a, const pt &b) {
  return pt(a.x - b.x, a.y - b.y);
}

bool operator==(const pt &a, const pt &b) {
  return a.x == b.x && a.y == b.y;
}

struct line {
  ll a, b, c;

  line(const pt &p, const pt &q) {
    a = q.y - p.y;
    b = p.x - q.x;
    c = -(a * p.x + b * p.y);
  }

  bool lies(const pt &p) {
    return a * p.x + b * p.y + c == 0;
  }
};

ld dist(const pt &a, const pt &b) {
  return hypot(a.x - b.x, a.y - b.y);
}

bool operator<(const pt &a, const pt &b) {
  return pair<ll, ll>(a.x, a.y) < pair<ll, ll>(b.x, b.y);
}

ld subSolve(const vector<pt> &pts, optional<pt> other, bool mayBegin = false) {
  ld all = 0;
  for (int i = 0; i + 1 < (int) pts.size(); i++) {
    all += dist(pts[i], pts[i + 1]);
  }
  if (other) {
    ld res = 1e18;
    if (mayBegin) {
      res = min(res, all + dist(pts[0], *other));
    } else {
      res = min(res, all + dist(pts.back(), *other));
      for (int i = 0; i + 1 < (int) pts.size(); i++) {
        res = min(res, all - dist(pts[i], pts[i + 1]) + dist(pts[i], *other) + dist(*other, pts[i + 1]));
      }
    }
    return res;
  } else {
    return all;
  }
}

ld subSolve2(const vector<pt> &pts, pt start, pt other) {
  ld res1 = 0, res2 = 0;
  pt end1 = *max_element(pts.begin(), pts.end());
  pt end2 = *min_element(pts.begin(), pts.end());
  res1 += dist(start, other);
  res1 += dist(other, end1);
  res1 += dist(end1, end2);
  res2 += dist(start, other);
  res2 += dist(other, end2);
  res2 += dist(end1, end2);
  return min(res1, res2);
}

ld subSolve3(const vector<pt> &pts, pt start, pt other) {
  ld all = 0;
  all += dist(pts[0], other);
  all += dist(pts.back(), other);
  ld res = 1e18;
  for (int i = 0; i < (int) pts.size(); i++) {
    if (i + 1 < (int) pts.size()) {
      res = min(res, all + dist(start, pts[i]) + dist(pts[i], pts[0]) + dist(pts[i + 1], pts.back()));
      res = min(res, all + dist(start, pts[i + 1]) + dist(pts[i + 1], pts.back()) + dist(pts[i], pts[0]));
    }
  }
  return res;
}

ld solve(vector<pt> pts, int k) {
  int n = (int) pts.size();
  k--;
  ld res = 1e18;
  vector<pt> pts2 = pts;
  sort(pts2.begin(), pts2.end());
  pts2.resize(unique(pts2.begin(), pts2.end()) - pts2.begin());
  if (pts2.size() == 1) {
    return 0;
  } else if (pts2.size() == 2) {
    return dist(pts2[0], pts2[1]);
  }
  pt START = pts[k];
  pts = pts2;
  n = (int) pts.size();
  for (line l: vector<line>{line(pts2[0], pts2[1]), line(pts2[0], pts2[2]), line(pts2[1], pts2[2])}) {
    vector<pt> onLine;
    optional<pt> other;
    for (const pt &p: pts) {
      if (l.lies(p)) {
        onLine.push_back(p);
      } else {
        other = p;
      }
    }
    if (onLine.size() >= n - 1) {
      sort(onLine.begin(), onLine.end());
      vector<pt> order1;
      vector<pt> order2;
      vector<pt> order3;
      vector<pt> order4;
      for (int i = 0; i < (int) onLine.size(); i++) {
        if (START == onLine[i]) {
          order1.insert(order1.end(), onLine.begin() + i, onLine.end());
          int sz1 = (int) order1.size();
          order1.insert(order1.end(), onLine.begin(), onLine.begin() + i);
          reverse(order1.begin() + sz1, order1.end());
          order2.insert(order2.end(), onLine.begin(), onLine.begin() + i + 1);
          reverse(order2.begin(), order2.end());
          order2.insert(order2.end(), onLine.begin() + i + 1, onLine.end());

          order3 = order1;
          order4 = order2;
          break;
        }
      }
      bool mayBegin = false;
      if (order1.empty()) {
        order1 = onLine;
        order2 = onLine;
        reverse(order2.begin(), order2.end());
        mayBegin = true;
      }
      res = min(res, subSolve(order1, other, mayBegin));
      res = min(res, subSolve(order2, other, mayBegin));
      if (other && count(onLine.begin(), onLine.end(), START)) {
        vector<pt> order5 = onLine;
        order5.erase(find(order5.begin(), order5.end(), START));
        res = min(res, subSolve3(order5, START, *other));
      }
      if (!order3.empty() && other) {
        {
          pt start = order3[0];
          order3.erase(order3.begin());
          res = min(res, subSolve2(order3, start, *other));
        }
        {
          pt start = order4[0];
          order4.erase(order4.begin());
          res = min(res, subSolve2(order4, start, *other));
        }
      }
    }
  }
  return res;
}

ld brute(vector<pt> pts, int k) {
  ld res = 1e18;
  --k;
  int n = pts.size();
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  do {
    if (p[0] != k) {
      continue;
    }
    ld cur = 0;
    for (int i = 0; i + 1 < n; i++) {
      cur += dist(pts[p[i]], pts[p[i + 1]]);
    }
    res = min(res, cur);
  } while (next_permutation(p.begin(), p.end()));
  return res;
}

mt19937 rnd;

int next(int l, int r) {
  return l + rnd() % (r - l + 1);
}

pair<vector<pt>, int> gen() {
  int tg = next(0, 10);
  int n = next(3, 8);
  int k = next(1, n);
  vector<pt> pts(n);
  for (int i = 0; i + 1 < n; i++) {
    int x = next(-5, 5);
    pts[i] = pt(x, tg * x);
  }
  pts.back() = pt(next(-5, 5), next(-5, 5));
  shuffle(pts.begin(), pts.end(), rnd);
  return {pts, k};
}

void stress() {
  while (true) {
    auto[pts, k] = gen();
    auto jans = brute(pts, k);
    auto pans = solve(pts, k);
    if (abs(jans - pans) > 1e-8) {
      cout << pts.size() << " " << k << endl;
      for (auto[x, y]: pts) {
        cout << x << " " << y << endl;
      }
      cout << "Expected: " << jans << endl;
      cout << "Found: " << pans << endl;
      for (auto[x, y]: pts) {
        cout << "(" << x << "," << y << ")" << endl;
      }
      exit(0);
    }
    cout << "YES" << endl;
  }
}

void runSolve() {
  int n, k;
  cin >> n >> k;
  vector<pt> pts(n);
  for (int i = 0; i < n; i++) {
    cin >> pts[i].x >> pts[i].y;
  }
  cout << solve(pts, k) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  cout << fixed;

//  stress();
  runSolve();

  return 0;
}