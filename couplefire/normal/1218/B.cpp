#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

struct pt {
  ld x, y;

  pt(ld x, ld y) : x(x), y(y) {}

  pt() = default;

  ld ang() const {
    return atan2(y, x);
  }

  ld dist2() const {
    return x * x + y * y;
  }
};

pt operator-(const pt &a, const pt &b) {
  return pt(a.x - b.x, a.y - b.y);
}

ld cross(const pt &a, const pt &b) {
  return a.x * b.y - a.y * b.x;
}

struct line {
  ld a, b, c;

  line(const pt &p, const pt &q) {
    a = q.y - p.y;
    b = p.x - q.x;
    c = -(a * p.x + b * p.y);
    if (a < 0 || (abs(a) < 1e-8 && b < 0)) {
      a = -a;
      b = -b;
      c = -c;
    }
  }

  bool operator==(const line &rhs) const {
    return a == rhs.a &&
           b == rhs.b &&
           c == rhs.c;
  }

  bool operator!=(const line &rhs) const {
    return !(rhs == *this);
  }
};

bool canIntersect(const line &a, const line &b) {
  return abs(a.a * b.b - a.b * b.a) > 1e-8;
}

pt intersect(const line &a, const line &b) {
  ld det = a.a * b.b - a.b * b.a;
  return pt((-a.c * b.b + a.b * b.c) / det, (-a.a * b.c + b.a * a.c) / det);
}

struct ev {
  vector<pair<pt, int>> add;
  vector<pair<pt, int>> remove;
  vector<pair<line, int>> addLine;
  vector<pair<line, int>> removeLine;
};

struct polyPt {
  pt p;
  int id;
};

bool operator<(const polyPt &a, const polyPt &b) {
  ld dx = a.p.dist2() - b.p.dist2();
  if (abs(dx) > 1e-8) {
    return dx < 0;
  } else {
    return a.id < b.id;
  }
}

ld area(const vector<pt> &pts) {
  vector<int> p(pts.size());
  iota(p.begin(), p.end(), 0);
  ld res = -1e18;
  do {
    ld cur = 0;
    for (int i = 1; i + 1 < (int) p.size(); i++) {
      cur += cross(pts[p[i]] - pts[0], pts[p[i + 1]] - pts[0]);
    }
    res = max(res, cur);
  } while (next_permutation(p.begin() + 1, p.end()));
  return res / 2;
}

vector<pt> rearrange(const vector<pt> &pts) {
  vector<int> p(pts.size());
  iota(p.begin(), p.end(), 0);
  ld res = -1e18;
  vector<pt> best;
  do {
    ld cur = 0;
    vector<pt> ptsCur(pts.size());
    for (int i = 0; i < (int) pts.size(); i++) {
      ptsCur[i] = pts[p[i]];
    }
    for (int i = 1; i + 1 < (int) p.size(); i++) {
      cur += cross(pts[p[i]] - pts[0], pts[p[i + 1]] - pts[0]);
    }
    if (res < cur) {
      res = cur;
      best = ptsCur;
    }
  } while (next_permutation(p.begin() + 1, p.end()));
  return best;
}
const ld PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  cout << fixed;

  int n;
  cin >> n;
  map<ld, ev> evs;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<pt> pts(k);
    for (int j = 0; j < k; j++) {
      cin >> pts[j].x >> pts[j].y;
    }
    pts.push_back(pts[0]);
    for (int j = 0; j < k; j++) {
      pt p1 = pts[j], p2 = pts[j + 1];
      ld a1 = pts[j].ang();
      ld a2 = pts[j + 1].ang();
      if (a1 < a2) {
        swap(a1, a2);
        swap(p1, p2);
      }
      if (a1 - a2 > PI) {
        evs[-PI].add.emplace_back(p1, i);
        evs[-PI].addLine.emplace_back(line(p1, p2), i);

        evs[a2].remove.emplace_back(p1, i);
        evs[a2].removeLine.emplace_back(line(p1, p2), i);

        evs[a1].add.emplace_back(p2, i);
        evs[a1].addLine.emplace_back(line(p1, p2), i);

        evs[PI].remove.emplace_back(p2, i);
        evs[PI].removeLine.emplace_back(line(p1, p2), i);
      } else {
        evs[a2].add.emplace_back(p2, i);
        evs[a2].addLine.emplace_back(line(p1, p2), i);

        evs[a1].remove.emplace_back(p2, i);
        evs[a1].removeLine.emplace_back(line(p1, p2), i);
      }
    }
  }

  ld res = 0;
  vector<vector<line>> polyLines(n);
  multiset<polyPt> near;
  ld prevX = -20;
  for (auto[x, e]: evs) {
    if (prevX != -20 && !near.empty()) {
      int nearId = near.begin()->id;
      vector<pt> subPoly;
      for (line l1: {line(pt(0, 0), pt(cos(prevX), sin(prevX))), line(pt(0, 0), pt(cos(x), sin(x)))}) {
        for (line l2: polyLines[nearId]) {
          if (canIntersect(l1, l2)) {
            subPoly.push_back(intersect(l1, l2));
          }
        }
      }
      res += area(subPoly);
    }
    prevX = x;
    for (auto[p, id]: e.add) {
      near.insert(polyPt{p, id});
    }
    for (auto[p, id]: e.remove) {
      const auto &position = near.find(polyPt{p, id});
      if (position != near.end()) {
        near.erase(position);
      }
    }
    for (auto[l, id]: e.addLine) {
      polyLines[id].push_back(l);
    }
    for (auto[l, id]: e.removeLine) {
      const auto &position = find(polyLines[id].begin(), polyLines[id].end(), l);
      if (position != polyLines[id].end()) {
        polyLines[id].erase(position);
      }
    }
  }
  cout << res;
  return 0;
}