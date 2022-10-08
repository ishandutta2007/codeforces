/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

const dbl pi = acosl(-1.0);

struct pnt {
  dbl x, y;

  inline pnt operator + ( const pnt &p ) const { return {x + p.x, y + p.y}; }
  pnt rot( dbl a ) {
    dbl co = cosl(a), si = sinl(a);
    return {x * co - y * si, x * si + y * co};
  }
};

const int N = 1 << 19;

pnt a[2 * N];
dbl b[2 * N];

void calc( int i ) {
  b[i] = b[2 * i] + b[2 * i + 1];
  a[i] = a[2 * i] + a[2 * i + 1].rot(b[2 * i]);
}

void up( int i ) {
  for (i /= 2; i; i /= 2)
    calc(i);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m, x, y, z;
  cin >> n >> m;
  forn(i, n)
    a[N + i + 1] = {1, 0};
  for (int i = N - 1; i; i--)
    calc(i);
  cout.precision(20);
  forn(i, m) {
    cin >> x >> y >> z, y += N;
    if (x == 1)
      a[y].x += z;
    else
      b[--y] += -z * pi / 180;
    up(y);
    //forn(i, 2 * N)
    //  printf("[%3d] %.2f,%.2f : %.2f\n", i, (double)a[i].x, (double)a[i].y, (double)b[i]);
    cout << fixed << (double)a[1].x << " " << (double)a[1].y <<"\n";
  }
  return 0;
}