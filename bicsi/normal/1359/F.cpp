#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
 
#include <bits/stdc++.h>
#define double long double
using namespace std;
using Point = complex<double>;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  srand(time(0));
  
  int n; cin >> n;
  vector<Point> p(n), q(n), d(n);
  vector<Point> a(n), b(n);
  vector<double> v(n);
  for (int i = 0; i < n; ++i) {
    auto read = [&]() {
      double x, y; cin >> x >> y;
      return Point{x, y};
    };
    p[i] = read(); d[i] = read();
    cin >> v[i];    
  }
 
  Point rot = polar(1.0L, ((double)rand() * RAND_MAX + rand()) * RAND_MAX + rand());
  
  auto look = [&](double mid) {
    for (int i = 0; i < n; ++i) {
      q[i] = p[i] + d[i] / abs(d[i]) * mid * v[i];
      // cerr << "CAR " << i << ": " << p[i] << " " << q[i] << endl;
    }
    
    vector<pair<double, int>> evs;
    for (int i = 0; i < n; ++i) {
      a[i] = p[i] * rot;
      b[i] = q[i] * rot;
      if (a[i].real() > b[i].real()) swap(a[i], b[i]);
      
      evs.emplace_back(a[i].real(), i);
      evs.emplace_back(b[i].real(), ~i);
    }
    sort(evs.begin(), evs.end());
    
    double at;
    
    auto sgn = [&](double d) {
      if (abs(d) < 1e-7L) return 0;
      return d < 0 ? -1 : 1;
    };
    auto eval = [&](int i) {
      double lam = (at - a[i].real()) / (b[i].real() - a[i].real());
      return a[i].imag() + lam * (b[i].imag() - a[i].imag());
    };
    auto cmp = [&](int i, int j) {
      return eval(i) + 1e-7L < eval(j);
    };
    set<int, decltype(cmp)> s(cmp);
 
    auto dot = [&](Point a, Point b) { return (conj(a) * b).real(); };
    auto cross = [&](Point a, Point b) { return (conj(a) * b).imag(); };
    auto check = [&](int i, int j) {
      Point s1 = a[i], e1 = b[i];
      Point s2 = a[j], e2 = b[j];
      Point v1 = e1-s1, v2 = e2-s2, d = s2-s1;
      auto a = cross(v1, v2), a1 = cross(v1, d), a2 = cross(v2, d);
      if (sgn(a) == 0) { //if parallel
        auto b1=dot(s1, v1), c1=dot(e1, v1),
             b2=dot(s2, v1), c2=dot(e2, v1);
        if (sgn(a1) || sgn(a2) || sgn(max(b1,min(b2,c2)) - min(c1,max(b2,c2))) > 0)
          return false;
        return true;
      }
      if (a < 0) { a = -a; a1 = -a1; a2 = -a2; }
      if (sgn(0 -a1)<0 || sgn(a-(-a1))<0 || sgn(0-a2)<0 || sgn(a-(-a2)) < 0)
        return false;
      return true;
    };
 
    bool ok = false;
    for (auto p : evs) {
      at = p.first;
      // cerr << p.first << ": " << endl;
      if (p.second >= 0) {
        // cerr << "I: " << a[p.second] << " " << b[p.second] << endl;
        auto pp = s.insert(p.second);
        if (!pp.second) {
          // cerr << "WTF" << endl;
          ok = true;
          break;
        }
        auto it = pp.first;
        if (it != s.begin()) {
          ok |= check(*prev(it), *it);
          // if (ok) cerr << "COLLIDE: " << *it << " " << *prev(it) << endl;
          if (ok) break;
        }
        if (next(it) != s.end()) {
          ok |= check(*it, *next(it));
          // if (ok) cerr << "COLLIDE: " << *it << " " << *next(it) << endl;
          if (ok) break;
        }
      } else {
        // cerr << "E: " << a[~p.second] << " " << b[~p.second] << endl;
        auto it = s.find(~p.second);
        if (it == s.end() || (*it) != (~p.second)) {
          // cerr << "WTF" << endl;
          ok = true;
          break;
        }
        if (it != s.begin() && next(it) != s.end()) {
          ok |= check(*prev(it), *next(it));
          if (ok) break;
          // if (ok) cerr << "COLLIDE: " << *prev(it) << " " << *next(it) << endl;
        }
        s.erase(it);
      }
      if (ok) break;
    }
    return ok;
  };
 
  double lo = 0, hi = 1;
  while (!look(hi)) {
    hi *= 2;
    if (hi > 1e12) {
      cout << "No show :(" << endl;
      return 0;
    }
  }
  for (int it = 0; it < 40; ++it) {
    // lo = hi = 0.59; it = 100;
    double mid = (lo + hi) / 2;
    if (look(mid)) {
      hi = mid;
    } else lo = mid;
  }
  double ans = (lo + hi) / 2;
  cout << fixed << setprecision(20) << ans << endl;
  
 
 
  return 0;
}