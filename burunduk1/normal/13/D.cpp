#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef long double dbl;
typedef vector <int> vi;
typedef pair <int, int> pii;

struct pnt
{
  int x, y;

  pnt() { }
  pnt( int x_, int y_ ) : x(x_), y(y_) { }

  void read()
  {
    scanf("%d%d", &x, &y);
  }

};

pnt operator + ( pnt a, pnt b ) { return pnt(a.x + b.x, a.y + b.y); }
pnt operator - ( pnt a, pnt b ) { return pnt(a.x - b.x, a.y - b.y); }
pnt operator * ( pnt a, int k ) { return pnt(a.x * k, a.y * k); }

dbl operator * ( pnt a, pnt b ) { return (dbl)a.x * b.y - (dbl)a.y * b.x; }

bool operator == ( pnt a, pnt b ) { return a.x == b.x && a.y == b.y; }

const int maxn = 512;

typedef unsigned long long ull;

int n, m;
pnt p[maxn], q[maxn];

ull is[maxn][maxn][maxn / 64];

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, n)
    p[i].read();
  random_shuffle(p, p + n);
  forn(i, m)
    q[i].read();
  random_shuffle(q, q + m);
  forn(i, n)
  {
    pnt st = p[i];
    forn(j, n)
      p[j] = p[j] - st;
    forn(j, m)
      q[j] = q[j] - st;

    forn(j, i)
      forn(k, m)
        if (q[k] * p[j] > 0)
          is[i][j][k >> 6] |= 1ULL << (k & 63);

    forn(j, n)
      p[j] = p[j] + st;
    forn(j, m)
      q[j] = q[j] + st;
  }

  int cnt = 0;
  forn(i, n)
  {
    pnt st = p[i];
    forn(j, n)
      p[j] = p[j] - st;
    forn(j, i)
      forn(k, j)
      {
        int x = p[k] * p[j] > 0;
        ull *is1 = is[i][j];
        ull *is2 = is[i][k];
        ull *is3 = is[j][k];

        int good = 1, num = m;
        while (1)
        {
          ull f;
          if (x)
            f = *is1++ & ~*is2++ & *is3++;
          else
            f = ~*is1++ & *is2++ & ~*is3++;
          if (num <= 64)
          {
            f &= ((ull)-1) >> (64 - num);
            if (f != 0)
              good = 0;
            break;
          }
          if (f != 0)
          {
            good = 0;
            break;
          }
          num -= 64;
        }
        cnt += good;
      }
    forn(j, n)
      p[j] = p[j] + st;
  }
  cout << cnt << endl;
  return 0;
}