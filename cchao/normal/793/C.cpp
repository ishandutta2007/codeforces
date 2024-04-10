
#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < int(n); ++i)
#define REPE(i, a, b) for (int i = (a); i <= int(b); ++i)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define EB emplace_back
using LL = long long;
using PII = pair<int, int>;
#define F first
#define S second
typedef pair<int, int> pii;
typedef complex<double> cd;
const double eps = 1e-8;
int dcmp(double x) { return (x > eps) - (x < -eps); }
namespace std {
bool operator<(const cd &a, const cd &b) {
  int x = dcmp(a.real() - b.real());
  int y = dcmp(a.imag() - b.imag());
  return pii(x, y) < pii(0, 0);
}
bool operator==(const cd &a, const cd &b) {
  int x = dcmp(a.real() - b.real());
  int y = dcmp(a.imag() - b.imag());
  return pii(x, y) == pii(0, 0);
}
}
double dot(cd a, cd b) { return real(conj(a) * b); }
double cross(cd a, cd b) { return imag(conj(a) * b); }
cd rotate(cd a, double rad) { return a * exp(cd(0, rad)); }
double tmp;
cd intersection(cd p, cd v, cd q, cd w) {
  if (dcmp(cross(v, w)) == 0) {
    tmp = -1;
    return p;
  }
  tmp = (cross(w, p - q) / cross(v, w));
  return p + v * tmp;
}
bool OnSegment(cd p, cd a1, cd a2) {
  if (p == a1 || p == a2) return true;
  return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}
int n;
int x1, y11, x2, y2;
int x, y, vx, vy;
cd r[4];

double lb = 0, rb = 1e12;

void f(cd p, cd v) {
  vector<double> a;
  if (x >= x1 && y >= y11 && x <= x2 && y <= y2) a.PB(0);
  REP(i, 4) {
    const auto &p1 = r[i];
    const auto &p2 = r[(i + 1) & 3];
    cd x = intersection(p, v, p1, p2 - p1);
    if (tmp < 0 || !OnSegment(x, p1, p2)) continue;
    a.PB(tmp);
  }
  sort(ALL(a));
  // for (auto x : a) printf("%f ", x); puts("");
  if (a.size() < 2) {
    puts("-1");
    exit(0);
  }
  double t = (a.back() + a.front()) / 2.0;
  cd x = p + v * t;
  double aa = real(x), bb = imag(x);
  if (dcmp(aa - x1) <= 0 || dcmp(bb - y11) <= 0 || dcmp(aa - x2) >= 0 || dcmp(bb - y2) >= 0) {
    puts("-1");
    exit(0);
  }
  lb = max(lb, a.front());
  rb = min(rb, a.back());
}

int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
  r[0] = cd(x1, y11);
  r[1] = cd(x2, y11);
  r[2] = cd(x2, y2);
  r[3] = cd(x1, y2);
  REP(i, n) {
    scanf("%d%d%d%d", &x, &y, &vx, &vy);
    cd p(x, y), v(vx, vy);
    if (vx == 0 && vy == 0) {
      if (x <= x1 || x >= x2 || y <= y11 || y >= y2) {
        puts("-1");
        exit(0);
      }
      continue;
    }
    f(p, v);
  }
  if (rb > lb) printf("%.12f\n", lb);
  else puts("-1");
  return 0;
}