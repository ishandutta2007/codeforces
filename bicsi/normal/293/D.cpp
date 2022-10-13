#include <bits/stdc++.h>
 
using namespace std;
 
using Point = complex<long long>;
 
long long det(Point a, Point b, Point c) {
  b -= a; c -= a;
  return (conj(b) * c).imag();
}

void Trim(vector<Point>& p) {
  while (p[0].real() == p[1].real()) p.erase(p.begin());
  while (p.end()[-1].real() == p.end()[-2].real()) p.pop_back();
}
 
long double Solve(vector<Point> p) {
  int n = p.size();
  
  double area = 0;
  for (int i = 0, j = n - 1; i < n; j = i++) 
    area += det(0, p[j], p[i]);  
  if (area < 0) reverse(p.begin(), p.end());
  
  tuple<long long, long long, int> fst = {+2000000, -1, -1};
  for (int i = 0; i < n; ++i)
    fst = min(fst, make_tuple(p[i].real(), p[i].imag(), i));
  rotate(p.begin(), p.begin() + get<2>(fst), p.end());
  p.push_back(p[0]); 
  tuple<long long, long long, int> snd = {-2000000, -1, -1};
  for (int i = 0; i < n; ++i)
    snd = max(snd, make_tuple(p[i].real(), p[i].imag(), i));
  
  vector<Point> lo(p.begin(), p.begin() + get<2>(snd) + 1);
  vector<Point> hi(p.begin() + get<2>(snd), p.end());
  reverse(hi.begin(), hi.end());
  Trim(lo); Trim(hi);

  long long minx = get<0>(fst), maxx = get<0>(snd);
  vector<int> cnt(maxx - minx + 1);
  
  long long miny = 0, maxy = 0;
  int i = 0, j = 0;
  for (long long x = minx; x <= maxx; ++x) {
    while (det(lo[i], lo[i + 1], Point{x, miny}) < 0) ++miny;
    while (det(lo[i], lo[i + 1], Point{x, miny - 1}) >= 0) --miny;
    while (det(hi[j], hi[j + 1], Point{x, maxy}) > 0) --maxy;
    while (det(hi[j], hi[j + 1], Point{x, maxy + 1}) <= 0) ++maxy;
    
    cnt[x - minx] = maxy - miny + 1;
    
    if (x == lo[i + 1].real()) ++i;
    if (x == hi[j + 1].real()) ++j;
  }
 
  long long total = 0;
  for (int x = 0; x <= maxx - minx; ++x)
    total += cnt[x];
    
  long double exp = 0, expsq = 0;
  for (int x = 0; x <= maxx - minx; ++x) {
    exp += 1.0L * x * cnt[x] / total;
    expsq += 1.0L * x * x / total * cnt[x];
  }
  
  long double ans = 0;
  for (int x = 0; x <= maxx - minx; ++x) {
    long double add = 1.0L * x * x + expsq - 2.0L * x * exp;
    ans += add / (total - 1) * cnt[x];
  }
  
  return ans;
}
 
int main() {
  int n; cin >> n;
  vector<Point> p(n);
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y; 
    p[i] = Point{x, y};
  }
  
  long double ans = 0;
  for (int it = 0; it < 2; ++it) {
    ans += Solve(p);
    for (int i = 0; i < n; ++i) {
      long long x = p[i].real(), y = p[i].imag();
      p[i] = Point{y, x};
    }
  }
  cout << fixed << setprecision(20) << 0.5L * ans << endl;
 
 
  return 0;
}