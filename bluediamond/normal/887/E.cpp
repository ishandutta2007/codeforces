#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

struct ve {
  ld x;
  ld y;
};

ve operator - (ve a, ve b) {
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

ve operator + (ve a, ve b) {
  a.x += b.x;
  a.y += b.y;
  return a;
}

ve operator / (ve a, ld val) {
  a.x /= val;
  a.y /= val;
  return a;
}

ve operator * (ve a, ld val) {
  a.x *= val;
  a.y *= val;
  return a;
}

ve operator * (ld val, ve a) {
  a.x *= val;
  a.y *= val;
  return a;
}


ld dot(ve a, ve b) {
  return a.x * b.x + a.y * b.y;
}

ld norm(ve a) {
  return sqrt(dot(a, a));
}

ve normalize(ve a) {
  return a / norm(a);
}

ve getinv(ve a) {
  return { -a.y,a.x };
}

struct Circle {
  ve p;
  ld r;
};

bool do_intersect(Circle a, Circle b) {
  ld d = norm(a.p - b.p);
  return a.r + b.r >= d;
}

bool do_contain(Circle a, Circle b) {
  ld d = norm(a.p - b.p);
  return a.r - b.r >= d;
}


const int N = (int)1e5 + 7;
int n;
Circle circles[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  ve a, b;

  {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a = { x1, y1 };
    b = { x2, y2 };
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int xx, yy, radius;
    cin >> xx >> yy >> radius;
    circles[i].p = { xx, yy };
    circles[i].r = radius;
  }

  ld INF = (ld)1e12;
  ld print = INF;

  ve midpoint = (a + b) / 2;
  ld d = norm(a - b) / 2;

  ve dir = normalize(getinv(a - b));

  function<Circle(ld)>getc = [&](ld h) {
    ld myr = sqrt(d * d + h * h);
    ve mycen = midpoint + dir * h;
    Circle my = { mycen, myr };
    return my;
  };

  int cntbs = 100;

  dir = dir * -1;
  ld sol = print;

  vector<pair<ld, ld>> s;



  for (int i = 1; i <= n; i++) {
    ld low = -INF, high = INF;

    int is_low = do_intersect(getc(low), circles[i]);
    int is_high = do_intersect(getc(high), circles[i]);

    ld pivot = 777, __low, __high;


    if (is_low) {
      for (int it = 1; it <= cntbs; it++) {
        ld h = (low + high) / 2;
        if (do_intersect(getc(h), circles[i])) {
          low = h;
        }
        else {
          high = h;
        }
      }
      low = -INF;
      __low = low;
      __high = high;
      for (int it = 1; it <= cntbs; it++) {
        ld h = (low + high) / 2;
        if (do_contain(getc(h), circles[i])) {
          low = h;
        }
        else {
          high = h;
        }
      }
      pivot = low;
      s.push_back({ pivot, __high });
    }
    else {
      for (int it = 1; it <= cntbs; it++) {
        ld h = (low + high) / 2;
        if (do_intersect(getc(h), circles[i])) {
          high = h;
        }
        else {
          low = h;
        }
      }
      high = +INF;
      __low = low;
      __high = high;
      for (int it = 1; it <= cntbs; it++) {
        ld h = (low + high) / 2;
        if (do_contain(getc(h), circles[i])) {
          high = h;
        }
        else {
          low = h;
        }
      }
      pivot = low;
      s.push_back({ __low, pivot });
    }
  }
  map<ld, int> add;
  add[0] = 0;
  ld mx = -INF;
  for (auto& it : s) {
    add[it.first]++;
    add[it.second]--;
    mx = max(mx, it.second);
  }

  print = min(print, abs(mx));
  int cur = 0;
  ld last = -INF;
  for (auto& it : add) {
    ld now = it.first;
    if (cur == 0) {
      print = min(print, abs(now));
      print = min(print, abs(last));
    }
    last = now;

    cur += it.second;
  }


  print = sqrt(d * d + print * print);
  cout << fixed << setprecision(6) << print << "\n";

  return 0;
}