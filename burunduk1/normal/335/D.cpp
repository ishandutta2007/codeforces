/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.08.03
 */

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <bitset>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (a); i <= (b); i++)

const int K = (int)1e5;
const int N = 3010;

bitset<K> was;
int n, sx[K], sy[K], u[N][N], no[N][N];
short u1[N][N], u2[N][N];

void add_h( int x, int y, int x2 )
{
  while (x < x2)
    u1[y][x++] = 1;
}

void add_v( int x, int y, int y2 )
{
  while (y < y2)
    u2[y++][x] = 1;
}

void out( int x1, int y1, int x2, int y2 )
{
  forab(y, y1, y2 - 1)
    forab(x, x1, x2 - 1)
      was[no[y][x]] = 1;

  int cnt = 0;
  forn(i, K)
    cnt += was[i];
  printf("YES %d\n", cnt);
  forn(i, K)
    if (was[i])
      printf("%d ", i + 1);
}

int main()
{
  scanf("%d", &n);
  forn(i, n)
  {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1++, y1++, x2++, y2++;
    add_h(x1, y1, x2);
    add_h(x1, y2, x2);
    add_v(x1, y1, y2);
    add_v(x2, y1, y2);
    forab(y, y1, y2 - 1)
      forab(x, x1, x2 - 1)
        u[y][x] = 1, no[y][x] = i;
    sx[i] = x2, sy[i] = y2;
  }
  forab(y, 1, N - 1)
    forab(x, 1, N - 1)
    {
      u[y][x] += u[y - 1][x] + u[y][x - 1] - u[y - 1][x - 1];
      if (u1[y][x])
        u1[y][x] += u1[y][x - 1];
      if (u2[y][x])
        u2[y][x] += u2[y - 1][x];
    }
  forn(i, n)
  {
    const int x = sx[i] - 1, y = sy[i] - 1;
    const int ma = min(u1[y + 1][x], u2[y][x + 1]);
    //printf("(%d,%d) --> %d\n", x, y, ma);
    forab(s, 1, ma)
    {
      int lx = x - s, ly = y - s;
      //printf("%d: %d %d [%d %d]\n", s, u1[ly + 1][x] >= s , u2[y + 1][lx] >= s , u[y][x] - u[ly][x] - u[y][lx] + u[ly][lx] , s * s);
      if (u1[ly + 1][x] >= s && u2[y][lx + 1] >= s && u[y][x] - u[ly][x] - u[y][lx] + u[ly][lx] == s * s) 
      {
        out(lx + 1, ly + 1, x + 1, y + 1);
        return 0;
      }
    }
  }
  puts("NO");
  return 0;
}