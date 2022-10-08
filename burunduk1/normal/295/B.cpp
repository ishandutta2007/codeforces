/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.11
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int N = 503;

int n, a[N][N], p[N], u[N];
ll r[N], d[N][N];

inline void relax( ll &a, ll b )
{
  a = min(a, b);
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
    forn(j, n)
      scanf("%d", &a[i][j]);
  forn(i, n)
    scanf("%d", &p[i]), p[i]--;
  reverse(p, p + n);

  forn(i, n)
    forn(j, n)
      d[i][j] = (ll)1e18;
  forn(i, n)
    d[i][i] = 0;
  forn(_i, n)
  {
    int i = p[_i];
    u[i] = 1;
    forn(j, n)
      if (u[j])
        forn(k, n)
          if (u[k])
          {
            relax(d[i][j], a[i][k] + d[k][j]);
            relax(d[j][i], d[j][k] + a[k][i]);
          }
    forn(j, n)
      if (u[j])
        forn(k, n)
          if (u[k])
          {
            relax(d[j][k], d[j][i] + d[i][k]);
            r[_i] += d[j][k];
          }
  }
  while (n--)
    printf("%I64d ", r[n]);
  return 0;
}