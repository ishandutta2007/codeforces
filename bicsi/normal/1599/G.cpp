#include <bits/stdc++.h>
  
using namespace std;
using ll = long long;
using Point = complex<long long>;
  
const double PI = 4.0 * atan(1.0);
const double EPS = 1e-9; // Good eps for long double is ~1e-11
  
// int sgn(double d) { 
//   return (d > EPS) - (d < -EPS); 
// }
ll dot(Point a, Point b) { 
  return a.real() * b.real() + a.imag() * b.imag(); 
}
ll cross(Point a, Point b) { 
  return a.real() * b.imag() - a.imag() * b.real(); 
}
ll det(Point a, Point b, Point c) { 
  return cross(b - a, c - a); 
}

double nrm(Point p) { return sqrt(dot(p, p)); }
  
  
int main() {
  ios::sync_with_stdio(false);
  int n, k; cin >> n >> k; --k;
  vector<Point> P(n);
  for (int i = 0; i < n; ++i) {
    long long x, y; cin >> x >> y;
    P[i] = {x, y};
  }
  
  double ans = 4e18;
  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  if (n <= 5) {
    do {
      if (o[0] == k) {
        double now = 0;
        for (int i = 1; i < n; ++i) 
          now += nrm(P[o[i]] - P[o[i - 1]]);
        ans = min(ans, now);
      }
    } while (next_permutation(o.begin(), o.end()));
  } else {
    mt19937 rng(42);
    while (true) {
      shuffle(o.begin(), o.end(), rng);
      int bad = -1;
      Point p = P[o[0]], q = P[o[1]];
      for (int i = 0; i < n; ++i) {
        if (det(p, q, P[i])) {
          if (bad == -1) bad = i;
          else bad = -2;
        }
      }
      if (bad == -2) continue;
  
      // line is p, q
      o.erase(find(o.begin(), o.end(), bad));
      stable_sort(o.begin(), o.end(), [&](int a, int b) {
        return dot(P[a] - p, q - p) < dot(P[b] - p, q - p);    
      });
      
  
      // for (auto x : o) cerr << P[x] << " "; cerr << endl;
      // cerr << "outsider: " << P[bad] << endl;
  
      for (int it = 0; it < 2; ++it) {
        if (bad == k) {
          // cerr << "bad = k" << endl;
          double now = nrm(P[k] - P[o[0]]);
          now += nrm(P[o.back()] - P[o.front()]);
          ans = min(ans, now);
        } else {
          /*
          vector<double> lp(n - 1), ls(n - 1);
          { 
            double acc = 0;
            for (int i = 0; i < n - 1; ++i) {
              if (i > 0) 
                acc += nrm(P[o[i]] - P[o[i - 1]]);
              lp[i] = acc;
            }
          }
          { 
            double acc = 0;
            for (int i = n - 1; i >= 0; --i) {
              if (i + 1 < n) 
                acc += nrm(P[o[i]] - P[o[i + 1]]);
              ls[i] = acc;
            }
          }
          */
          ans = min(ans, nrm(P[k] - P[bad]) + nrm(P[bad] - P[o.front()]) + nrm(P[o.back()] - P[o.front()]));
          ans = min(ans, nrm(P[k] - P[o.front()]) + nrm(P[o.back()] - P[o.front()]) + nrm(P[bad] - P[o.back()]));
          auto chk = [&](Point a, Point b, Point c, Point d) {
            double now = nrm(P[k] - a) + nrm(b - a) + nrm(P[bad] - b)
              + nrm(P[bad] - c) + nrm(d - c);
            ans = min(ans, now);
          };
          for (int i = 0; i < n - 2; ++i) {
            Point a = P[o.front()], b = P[o[i]], c = P[o[i + 1]], d = P[o.back()];
            chk(a, b, c, d);
            chk(a, b, d, c);
            chk(b, a, c, d);
            chk(b, a, d, c);
          } 
        }
        reverse(o.begin(), o.end());
      }
  
      break;
      
    }
    
  }
  cout << fixed << setprecision(20) << ans;
  
  return 0;
}