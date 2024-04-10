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

  ld dist2() {
    return x * x + y * y;
  }
};

struct line {
  ld a, b, c;

  line(const pt &p, const pt &q) {
    a = q.y - p.y;
    b = p.x - q.x;
    c = -(a * p.x + b * p.y);
  }

  line(ld a, ld b, ld c) : a(a), b(b), c(c) {}

  line perp(const pt &p) {
    return line(-b, a, -(-b * p.x + a * p.y));
  }
};

const ld EPS = 1e-8;

vector<pt> intersect(ld r, const line &l) {
  ld a = l.a;
  ld b = l.b;
  ld c = l.c;

  ld x0 = -a * c / (a * a + b * b), y0 = -b * c / (a * a + b * b);
  if (c * c > r * r * (a * a + b * b) + EPS)
    return {};
  else if (abs(c * c - r * r * (a * a + b * b)) < EPS) {
    return {pt(x0, y0)};
  } else {
    ld d = r * r - c * c / (a * a + b * b);
    ld mult = sqrt(d / (a * a + b * b));
    ld ax, ay, bx, by;
    ax = x0 + b * mult;
    bx = x0 - b * mult;
    ay = y0 - a * mult;
    by = y0 + a * mult;
    return {pt(ax, ay), pt(bx, by)};
  }
}

ld ang(const pt &p) {
  return atan2(p.y, p.x);
}

const ld PI = acos(-1);

const bool DEBUG = false;

void print_crl(const pt &p, ld r) {
  if (DEBUG) {
    cout << "(x-" << p.x << ")^2+(y-" << p.y << ")^2=" << r << "^2" << endl;
  }
}

bool ok(ld r, const vector<pt> &pts, const vector<line> &lines, int k) {
  map<ld, int> evs;
  ld r2 = r * r * 4;
  int cnt = 0;
  for (int i = 0; i < (int) lines.size(); i++) {
    auto p = pts[i];
    if (p.dist2() > r2) {
      if (DEBUG) {
        cout << "Skip (" << p.x << ", " << p.y << ")" << endl;
      }
      continue;
    }
    if (p.dist2() < EPS) {
      cnt += 1;
      continue;
    }
    vector<pt> inter = intersect(r, lines[i]);
    if (DEBUG) {
      cout << "For (" << p.x << ", " << p.y << ")" << endl;
    }
    if (inter.size() == 1) {
      ld ang1 = ang(inter[0]);
      evs[ang1 - EPS] += 1;
      evs[ang1 + EPS] -= 1;
      print_crl(inter[0], r);
    } else if (inter.size() == 2) {
      ld ang1 = ang(inter[0]);
      ld ang2 = ang(inter[1]);
      if (ang1 > ang2) {
        swap(ang1, ang2);
      }
      if (ang2 - ang1 > PI) {
        evs[-PI] += 1;
        evs[ang1] -= 1;
        evs[ang2] += 1;
        evs[PI] -= 1;
      } else {
        evs[ang1] += 1;
        evs[ang2] -= 1;
      }
      print_crl(inter[0], r);
      print_crl(inter[1], r);
    } else {
      assert(false);
    }
    if (DEBUG) {
      cout << endl;
    }
  }
  for (auto[a, delta]: evs) {
    cnt += delta;
    if (cnt >= k) {
      return true;
    }
  }
  return cnt >= k;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  if (DEBUG) {
    cout.precision(4);
  } else {
    cout.precision(20);
  }
  cout << fixed;

  int n, k;
  cin >> n >> k;
  vector<line> lines;
  vector<pt> pts(n);
  for (auto&[x, y]: pts) {
    int tx, ty;
    cin >> tx >> ty;
    x = tx;
    y = ty;
    if (DEBUG) {
      cout << "(" << x << ", " << y << ")\n";
    }
    lines.push_back(line(pt(0, 0), pt(x, y)).perp(pt(x / 2, y / 2)));
  }

  ld l = 0, r = 2e5;
  while (r - l > 1e-4) {
    ld m = (l + r) / 2;
    if (ok(m, pts, lines, k)) {
      r = m;
    } else {
      l = m;
    }
  }
  cout << r;
  return 0;
}