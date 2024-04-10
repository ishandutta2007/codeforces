/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.16
 */

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

const dbl eps = 1e-12;

struct pnt
{
  dbl x, y;

  pnt( dbl _x = 0, dbl _y = 0 ) : x(_x), y(_y) { }

  inline pnt operator - () const { return pnt(-x, -y); }

  inline pnt operator + ( const pnt &p ) const { return pnt(x + p.x, y + p.y); }
  inline pnt operator - ( const pnt &p ) const { return pnt(x - p.x, y - p.y); }
  inline pnt operator * ( const dbl &k ) const { return pnt(x * k, y * k); }
  inline pnt operator / ( const dbl &k ) const { return pnt(x / k, y / k); }

  inline dbl operator * ( const pnt &p ) const { return x * p.y - y * p.x; }
  inline dbl operator ^ ( const pnt &p ) const { return x * p.x + y * p.y; }

  inline bool operator == ( const pnt &p ) const { return fabs(x - p.x) + fabs(y - p.y) < eps; }
  inline bool operator != ( const pnt &p ) const { return fabs(x - p.x) + fabs(y - p.y) > eps; }

  inline dbl d2() const { return x * x + y * y; }
  inline dbl d() const { return sqrt(d2()); }

  inline pnt norm() const { return *this / d(); }
  inline pnt ort() const { return pnt(-y, x); }
  inline dbl ang() const { return atan2(y, x); }

  pnt rot( dbl a )
  {
    dbl co = cos(a), si = sin(a);
    return pnt(x * co - y * si, x * si + y * co);
  }
};

inline pnt pntByAng( dbl a ) { return pnt(cos(a), sin(a)); }

int xp, yp, vp, x, y, v, r;
double R;
dbl ans = 1e100;

pnt Tangent( pnt A, int sign )
{
  dbl d = A.d();
  dbl ang = asin(r / d);
  return A + ((-A).rot(ang * sign) * cos(ang));
}

dbl rDist( pnt a, pnt b )
{
  dbl x = b.ang() - a.ang();
  while (x < -M_PI) x += 2 * M_PI;
  while (x > M_PI) x -= 2 * M_PI;
  return fabs(x) * r;
}

dbl F( dbl ang )
{
  pnt A(x, y), B = pntByAng(ang) * R;
  if (A == B)
    return 0;

  dbl dist = (B - A).d();
  dbl res = dist;
  if (((B - A) ^ -A) > 0 && ((A - B) ^ -B) > 0 && fabs(A ^ (B - A).ort()) / dist < r)
  {
    // tangent
    res = 1e100;
    for (int s1 = -1; s1 <= 1; s1 += 2)
      for (int s2 = -1; s2 <= 1; s2 += 2)
      {
        pnt AA = Tangent(A, s1);
        pnt BB = Tangent(B, s2);
        res = min(res, (AA - A).d() + (BB - B).d() + rDist(AA, BB));
      }
  }

  dbl t = res / v, w = vp / R, w2 = v / R, st = atan2(yp, xp);

  dbl diff = ang - (st + w * t);
  diff -= floor(diff / (2 * M_PI)) * (2 * M_PI);
  while (diff < -eps) diff += 2 * M_PI;
  while (diff > 2 * M_PI - eps) diff -= 2 * M_PI;

  assert(w2 > w);
  dbl T1 = diff / (w + w2);
  dbl T2 = (2 * M_PI - diff) / (w2 - w);

  res = t + min(T1, T2);
  ans = min(ans, res);
  return res;
}

void Solve( double L, double R )
{
  const int K = 100;
  forn(t, K)
  {
    double a = (4 * L + R) / 5;
    double b = (L + 4 * R) / 5;
    if (F(a) < F(b))
      R = b;
    else
      L = a;
  }
}

int main()
{
  scanf("%d%d%d", &xp, &yp, &vp);
  scanf("%d%d%d%d", &x, &y, &v, &r);
  R = sqrt(xp * xp + yp * yp);

  int N = 100;
  forn(i, N)
    Solve(2 * M_PI * i / N, 2 * M_PI * (i + 1) / N);
  printf("%.20f\n", (double)ans);
  return 0;
}