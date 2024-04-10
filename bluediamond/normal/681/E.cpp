#include <bits/stdc++.h>

using namespace std;

typedef double ld;

class point {
public:
  ld x;
  ld y;
  point(ld x, ld y) : x(x), y(y) {
  }

  point() {
  }
};

point operator - (point a, point b) {
  return {a.x - b.x, a.y - b.y};
}

ld dot(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

point norm(point a) {
  ld dist = sqrt(dot(a, a));
  return {a.x / dist, a.y / dist};
}

point mult(point a, point b) {
  return {a.x * b.x - a.y * b.y, a.x * b.y + b.x * a.y};
}

point perpendicularnormed(point a) {
  return norm({-a.y, a.x});
}

point operator * (point a, ld r) {
  return {a.x * r, a.y * r};
}

point operator + (point a, point b) {
  return point(a.x + b.x, a.y + b.y);
}

const ld pi = 2 * acos((ld) 0);

point ori;
int v, t, n;
ld myradius;

point rot(point origin, point to, ld ang) {
  point p = to - origin;
  ld dist = sqrt(dot(p, p));
  p = norm(p);
  p = mult(p, point(cos(ang), sin(ang)));

  return origin + p * dist;
}

point rot(point to, ld ang) {
  return rot(point(0, 0), to, ang);
}

ld getang(point p) {
  ld sol = atan2(p.y, p.x);
  if (sol < 0) sol += 2 * pi;
  return sol;
}

long double longdot(point a, point b) {
  long double xa = a.x;
  long double xb = b.x;

  long double ya = a.y;
  long double yb = b.y;

  return xa * xb + ya * yb;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> ori.x >> ori.y >> v >> t >> n;

  myradius = (ld) v * t;
  myradius = min(myradius, (ld) 1e10);
  vector<pair<ld, int>> events;
  events.push_back({0, 0});
  events.push_back({2 * pi, 0});

  for (int i = 1; i <= n; i++) {
    point p;
    ld radius;
    cin >> p.x >> p.y >> radius;

    p = p - ori;
    ld ang1, ang2;
    ld vasile = dot(p, p) - radius * radius;



    if (longdot(p, p) <= (long double) radius * radius) {
      cout << 1 << "\n";
      return 0;
    }
    vasile = sqrt(vasile);

    if (vasile <= myradius) {
      ld ang = asin(vasile / sqrt(dot(p, p)));
      point p1 = p - norm(rot(norm(p), ang)) * radius;
      point p2 = p - norm(rot(norm(p), -ang)) * radius;

      ang1 = getang(p1);
      ang2 = getang(p2);
    } else {
      point pnormed = norm(p);
      ld angle = pi / 2 - getang(pnormed);
      point pinit = p;
      p = rot(p, angle);


      ld y = (myradius * myradius - radius * radius + p.y * p.y) / (2 * p.y);
      ld x = myradius * myradius - y * y;

      if (x < 0) continue;
      x = sqrt(x);
      point p1(x, y);
      point p2(-x, y);
      p1 = rot(p1, -angle);
      p2 = rot(p2, -angle);
      p = pinit;
      ang1 = getang(norm(p1));
      ang2 = getang(norm(p2));
    }
    if (ang1 <= ang2) {
      events.push_back({ang1, 1});
      events.push_back({ang2, -1});
    } else {
      events.push_back({ang1, 1});
      events.push_back({2 * pi, -1});
      events.push_back({0, +1});
      events.push_back({ang2, -1});
    }
  }
  ld sol = 0, ant;
  int cur = 0;
  sort(events.begin(), events.end());
  for (auto &it : events) {
    if (cur) {
      sol += (it.first - ant);
    }
    ant = it.first;
    cur += it.second;

  }
  cout << fixed << setprecision(6) << sol / (2 * pi) << "\n";
  return 0;
}