/**     ()
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

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

#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%Ld"
#endif

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

#define EOL(i, n) " \n"[i == (n) - 1]

typedef long double dbl;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

template <class T> T inline sqr(T x) { return x * x; }

const int maxd = (int)1e6;
const int maxn = (int)1e4 + 10;

vector <pii> v[maxd];
int rn, perm[maxn];
pii r[maxn];
dbl ang[maxn];

void Solve( int d )
{
  for (int x = 1; x * x < d; x++)
    for (int y = 0; x * x + y * y < d && y <= x; y++)
      v[x * x + y * y].pb(mp(x, y));

  int cnt = 0;
  forn(i, d + 1)
    cnt += (v[i].size() > 0);
//  fprintf(stderr, "%.3lf : %d\n", sqrt((double)d), cnt);
}

bool aless( int i, int j )
{
  return ang[i] < ang[j];
}

int main()
{
  Solve(maxd);

  int n;
  scanf("%d", &n);
//  for (int n = 3; n <= 100; n++)
  {
    int d = 1, cnt = 0, d0 = (int)1e9;
    while (cnt < n)
      cnt += (v[d++].size() > 0);

    ll sum = 0;
    #define SUM(pos, i) (v[pos][i].first + v[pos][i].second)
    for (int pos = d - 1; pos > 0; pos--)
      if (sz(v[pos]))
        sum += SUM(pos, 0);
    if (sum & 1)
    {
      int ind[2] = {-1, -1};
      forn(pos, d)
        if (sz(v[pos]) > 0)
          ind[SUM(pos, 0) & 1] = pos;

      d0 = d - 1;
      int skipped = 0;
      while (1)
      {
        if (sz(v[d]) > 0 && ind[!(SUM(d, 0) & 1)])
        {
          d0 = ind[!(SUM(d, 0) & 1)];
          break;
        }
        skipped += (sz(v[d]) > 0);
        d++;
      }
    }
    else
      d--;

    int dx = 0, dy = 0;
    for (int pos = d; pos > 0; pos--)
      if (sz(v[pos]) && pos != d0)
      {
        int cx = v[pos][0].first;
        int cy = v[pos][0].second;
        int mi = (int)1e9, rx = 0, ry = 0;
        forn(t, 2)
        {
          for (int kx = -1; kx <= 1; kx += 2)
            for (int ky = -1; ky <= 1; ky += 2)
            {
              int tmp, x = dx + cx * kx, y = dy + cy * ky;
              if (mi > (tmp = x * x + y * y))
                mi = tmp, rx = x, ry = y;
            }
          swap(cx, cy);
        }
        r[rn++] = mp(rx - dx, ry - dy);
        dx = rx, dy = ry;
      }

    forn(i, rn)
      ang[i] = atan2((double)r[i].second, (double)r[i].first), perm[i] = i;
    sort(perm, perm + rn, aless);

    puts("YES");
    dx = 0, dy = 0;
    forn(i, n)
    {
      printf("%d %d\n", dx, dy);
      dx += r[perm[i]].first;
      dy += r[perm[i]].second;
    }
  }
  return 0;
}