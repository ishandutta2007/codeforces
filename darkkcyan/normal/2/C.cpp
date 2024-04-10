#include <bits/stdc++.h>
using namespace std;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()

#define point complex<long double>
#define X real()
#define Y imag()
#define sqr(x) ((x) * (x))
#define eps ((long double) 1e-8)
#define inf ((long double)(INT_MAX))

struct intersectable {
  virtual ~intersectable() {}
  virtual vector<point> intersect(intersectable* other) = 0;
};


struct line : public intersectable {
  long double a, b, c;

  line() {}
  line(long double a_, long double b_, long double c_)
    :a(a_), b(b_), c(c_) {}
  line(const point& normal, const point& p)
    : line(normal.X, normal.Y, -(normal.X * p.X + normal.Y * p.Y)) {}

  point normal() const { return {a, b}; }

  long double dis(const point& p, bool sign = false) {
    long double res = (a * p.X + b * p.Y + c) / abs(normal());
    if (!sign) res = abs(res);
    return res;
  }

  point reflect(const point& p) {
    return p - normal() / abs(normal()) * (long double) 2 * dis(p, true);
  }

  virtual vector<point> intersect(intersectable* other);
};

struct circle : public intersectable {
  point cen;
  long double r;

  circle() {}
  circle(point cen_, long double r_): cen(cen_), r(r_) {}

  virtual vector<point> intersect(intersectable* other);
};

vector<point> line::intersect(intersectable* other) {
  if (auto cir = dynamic_cast<circle*>(other)) return cir->intersect(this);
  auto oline = dynamic_cast<line*>(other);
  if (!oline) return {};
  long double delta = a * oline->b - b * oline->a;
  long double delta_x = (-c) * oline->b - b * (-oline->c);
  long double delta_y = a * (-oline->c) - (-c) * oline->a;
  if (abs(delta) < eps) return {};
  return {{delta_x / delta, delta_y / delta}};
}

vector<point> circle::intersect(intersectable* other) {
  circle other_cir;
  if (auto ln = dynamic_cast<line*>(other)) {
    other_cir.cen = ln->reflect(cen);
    other_cir.r = r;
  } else if (auto ocir = dynamic_cast<circle*>(other)) {
    other_cir = *ocir;
  } else return {};

  point ab = other_cir.cen - cen;
  long double dis = abs(ab);
  if (dis > r + other_cir.r || dis < abs(r - other_cir.r)) return {};
  long double cos_ang = (sqr(r) + sqr(dis) - sqr(other_cir.r)) / (2 * r * dis);
  long double sin_ang = sqrt(1 - sqr(cos_ang));
  point trans = ab / dis * r;
  return {
    point(cos_ang, sin_ang) * trans + cen,
    point(cos_ang, -sin_ang) * trans + cen
  };
}

intersectable* find_satisfy_set(const circle& a, const circle& b) {
  if (abs(a.r - b.r) < eps) {
    return new line(b.cen - a.cen, (a.cen + b.cen) / (long double) 2);
  } else {
    point p1 = (b.cen - a.cen) * a.r / (a.r + b.r) + a.cen;
    point p2 = (a.cen - b.cen) * a.r / (b.r - a.r) + a.cen;
    return new circle((p1 + p2) / (long double)2, abs(p1 - p2) / 2);
  }
}


circle a, b, c;
bool ok(const point& x) {
  long double coef = abs(x - a.cen) / a.r;
  if (coef < 1) return false;
  for (auto i: {b, c}) {
    if (abs(abs(x - i.cen) / i.r - coef) > eps) return false;
  }
  return true;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (auto i: {&a, &b, &c}) {   // for (auto i: {a, b, c}) will give an compilation error, since i is const circle
      int x, y, r; cin >> x >> y >> r;
      i->cen = point(x, y);
      i->r = r;
    }

    auto* u = find_satisfy_set(a, b);
    auto* v = find_satisfy_set(a, c);
    pair<long double, point> ans(inf, {0, 0});
    for (auto i: u->intersect(v)) {
      if (!ok(i)) continue;
      ans = min(ans, {abs(i - a.cen), i}, [](auto x, auto y) { return x.xx < y.xx; });
    }

    if (ans.xx < inf - eps) 
      cout << fixed << setprecision(5) << ans.yy.X << ' ' << ans.yy.Y;

    delete u;
    delete v;

    return 0;
}