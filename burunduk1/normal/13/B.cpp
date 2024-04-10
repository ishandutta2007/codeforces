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

#include <cstdio>

struct pnt
{
  int x, y;

  pnt() { }
  pnt( int x_, int y_ ) : x(x_), y(y_) { }

  void read()
  {
    scanf("%d%d", &x, &y);
  }

  ll d2() { return (ll)x * x + (ll)y * y; }
  dbl d() { return sqrt(d2()); }
};

pnt A[3], B[3];
pnt a[3], b[3];
int p[3];

pnt operator + ( pnt a, pnt b ) { return pnt(a.x + b.x, a.y + b.y); }
pnt operator - ( pnt a, pnt b ) { return pnt(a.x - b.x, a.y - b.y); }
pnt operator * ( pnt a, int k ) { return pnt(a.x * k, a.y * k); }

ll operator * ( pnt a, pnt b ) { return (ll)a.x * b.y - (ll)a.y * b.x; }
ll operator ^ ( pnt a, pnt b ) { return (ll)a.x * b.x + (ll)a.y * b.y; }

bool operator == ( pnt a, pnt b ) { return a.x == b.x && a.y == b.y; }

int IsIn( pnt a, pnt b, pnt p )
{
  return (a - b) * (p - a) == 0 &&
    min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
    min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y) &&
    !(a == p || b == p);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  while (tn--)
  {
    forn(i, 3)
      A[i].read(), B[i].read(), p[i] = i;
    
    int res = 0;
    do
    {
      forn(i, 3)
        a[i] = A[p[i]], b[i] = B[p[i]];
      forn(pr, 8)
      {
        forn(i, 3)
          if ((pr >> i) & 1)
            swap(a[i], b[i]);

/*&
        puts("Try:");
        forn(i, 3)
          printf("(%d,%d) - (%d,%d)\n", a[i].x, a[i].y, b[i].x, b[i].y);
*/

        int f = 1;
        if (!(a[0] == a[1]))
          f = 0;
        if ((b[0] - a[0]) * (b[1] - a[1]) == 0)
          f = 0;
        if (((b[0] - a[0]) ^ (b[1] - a[1])) < 0)
          f = 0;
//        printf("f=%d\n", f);
        if (!IsIn(a[0], b[0], a[2]) || !IsIn(a[1], b[1], b[2]))
          f = 0;
        if (f)
        {
          const dbl eps = 1e-12;
          dbl d1, d2;
          d1 = (a[2] - a[0]).d();
          d2 = (a[2] - b[0]).d();
          if (max(d1, d2) / min(d1, d2) > 4.0 + eps)
            f = 0;
          d1 = (b[2] - a[1]).d();
          d2 = (b[2] - b[1]).d();
          if (max(d1, d2) / min(d1, d2) > 4.0 + eps)
            f = 0;
        }
        res |= f;

        forn(i, 3)
          if ((pr >> i) & 1)
            swap(a[i], b[i]);
      }
    } while (next_permutation(p, p + 3));
    puts(res ? "YES" : "NO");
  }
  return 0;
}