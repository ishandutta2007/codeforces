/**       
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.10.15
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <bitset>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define VAL(i) ((i) >= 0 && ((is[(i) >> 5] >> ((i) & 31)) & 1))
#define IS(a, i) (((a) >> (i)) & 1)

typedef long long ll;

const int N = (int)7.1e4;
const int N1 = N / 32;

int n, k, ma, a[N], p[N], ind[N], next[N];
bitset <N> out;
unsigned is[N1];

void NO()
{
  puts("-1");
  exit(0);
}

bool aless( int i, int j )
{
  return a[i] > a[j];
}

// [l..l+32)
inline unsigned get( int l )
{
  if (l <= -32)
    return 0;
  if (l < 0)
    return (ll)is[0] << -l;
  int r = l & 31;
  l >>= 5;
  return (is[l] >> r) + ((ll)is[l + 1] << (32 - r));
}

int main()
{
  scanf("%d%d", &n, &k);
  forn(i, n)
  {
    scanf("%d", &a[i]);
    ind[i] = i;
  }
  sort(ind, ind + n, aless);
  if (k < a[ma = ind[0]])
   	NO();
  k -= a[ma];
  is[0] = 1;

  forn(i, n)
    if (i != ma)
      for (int x = k >> 5; x >= 0; x--)
      {
/*
        unsigned tmp = 0;
        forn(y, 32)
          if (VAL((x << 5) + y - a[i]))
            tmp |= 1U << y;
*/
        unsigned tmp = get((x << 5) - a[i]);
        if (tmp & ~is[x])
        {
          unsigned r = is[x];
          forn(y, 32)
            if (!IS(r, y) && IS(tmp, y))
              p[(x << 5) + y] = i, is[x] |= 1U << y;
        }
      }
  if (!VAL(k))
    NO();
  out[ma] = 1;
  for (int i = k; i > 0; i -= a[p[i]])
    out[p[i]] = 1;

  fill(next, -1);
  forn(j, n)
    if (!out[ind[j]])
      next[ind[j - 1]] = ind[j];
  forn(j, n)
    if (next[j] == -1)
      printf("%d 0\n", a[j]);
    else
      printf("%d 1 %d\n", a[j] - a[next[j]], next[j] + 1);
  return 0;
}