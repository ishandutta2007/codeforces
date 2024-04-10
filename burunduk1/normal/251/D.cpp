/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.12.06
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

const int N = (int)1e5 + 10;
const int M = 61;

int n;
ll a[N];
int rn, r[M][N], x[N], ind[M];
int is[N];

int main()
{
  while (scanf("%d", &n) == 1)
  {
    rn = 0;
    forn(i, n)
      scanf("%I64d", &a[i]);
    forn(t, 2)
      for (int b = M - 1; b >= 0; b--)
      {
        int cnt = 0;
        forn(j, n)
          cnt += (x[j] = (a[j] >> b) & 1);
        x[n] = 1;
        if ((cnt & 1) != t)
          continue;
        forn(i, rn)
          if (x[ind[i]])
            forn(j, n + 1)
              x[j] ^= r[i][j];

        int p = 0;
        while (p < n && !x[p])
          p++;
        if (p < n)
        {
          memcpy(r[rn], x, sizeof(x));
          ind[rn++] = p;
        }
      }

    memset(is, 0, sizeof(is));
    for (int i = rn - 1; i >= 0; i--)
    {
      int p = ind[i];
      is[p] = r[i][n];
      for (int j = i + 1; j < rn; j++)
        is[p] ^= is[ind[j]] * r[i][ind[j]];
    }

    forn(i, n)
      printf("%d ", is[i] + 1);
    puts("");
  }
  return 0;
}