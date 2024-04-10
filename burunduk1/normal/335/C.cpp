/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.03
 */

#include <cstdio>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

const int N = 103;

int x = 0, h, k, r[N], c[N], p[N], m[N][4];
int cc, u[N * N];

inline bool rless( int i, int j )
{
  return r[i] < r[j];
}

inline int get( int n, int t )
{
  if (n >= 1)
    return m[n][t];
  if (t == 0)
    return 0;
  if (t == 3)
    return n == 0;
  return t == 1 ? n == 0 : n == -1;
}

inline void add( int i, int j )
{ 
  x ^= get(i, j);
}

int main()
{

  scanf("%d%d", &h, &k);
  forn(i, k)
    scanf("%d%d", &r[i], &c[i]), p[i] = i;
  sort(p, p + k, rless);

  forab(n, 1, h)
    forn(t, 4)
    {
      cc++;
      forn(i, n)
      {
        //#define DO(x, y) printf("i=%d, t=%d, x=%d, y=%d: [%d,%d]=%d ^ [%d,%d]=%d\n", i, t, x, y, i - 1, x, get(i - 1, x), n - i - 2, y, get(n - i - 2, y)), u[get(i - 1, x) ^ get(n - i - 2, y)] = cc
        #define DO(x, y) u[get(i - 1, x) ^ get(n - i - 2, y)] = cc
        if (t == 0)
          DO(1, 1);
        else if (t == 1)
          DO(2, 1), DO(3, 1);
        else if (t == 2)
          DO(2, 2), DO(3, 3);
        else 
          DO(2, 3), DO(3, 2);
      }
      if (t >= 1)
        u[get(n - 1, t)] = cc;

      int &f = m[n][t];
      while (u[f] == cc)
        f++;

      //printf("f[%d, %d] = %d\n", n, t, f);
    }

  if (k == 0)
    add(h, 0);
  else
  {
    add(r[p[0]] - 2, 1);
    add(h - r[p[k - 1]] - 1, 1);
    forn(i, k - 1)
      add(r[p[i + 1]] - r[p[i]] - 3, c[p[i]] == c[p[i + 1]] ? 2 : 3);
  }

  puts(x ? "WIN" : "LOSE");
  return 0;
}