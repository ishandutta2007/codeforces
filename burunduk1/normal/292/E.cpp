/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.04.15
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = (int)1e9;
const int N = 1 << 17;

int n, m, a[N], b[N], t[2 * N];

void Set( int v, int vl, int vr, int l, int r, int x )
{
  if (vr < l || r < vl)
    return;
  if (l <= vl && vr <= r)
  {
    t[v] = x;
    return;
  }
  if (t[v] != inf)
    t[2 * v] = t[2 * v + 1] = t[v], t[v] = inf;
  int vm = (vl + vr) / 2;
  Set(2 * v, vl, vm, l, r, x);
  Set(2 * v + 1, vm + 1, vr, l, r, x);
}

int main()
{
  scanf("%d%d", &n, &m);
  forn(i, n)
    scanf("%d", &a[i]);
  forn(i, n)
    scanf("%d", &b[i]);
  forn(i, 2 * N)
    t[i] = inf;
  forn(i, m)
  {
    int type;
    scanf("%d", &type);
    if (type == 2)
    {
      int x;
      scanf("%d", &x), x--;
      int ans = b[x];
      for (int j = N + x; j > 0; j /= 2)
        if (t[j] != inf)
          ans = a[x + t[j]];
      printf("%d\n", ans);
    }
    else
    {
      int x, y, k;
      scanf("%d%d%d", &x, &y, &k), x--, y--;
      Set(1, 0, N - 1, y, y + k - 1, x - y);
    }
  }
  return 0;
}