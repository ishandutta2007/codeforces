/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.06.16
 */

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

const int maxN = (int)1e5 + 3;

int n, k, d[2][maxN];
int qst, qen, qx[maxN], qy[maxN];
char s[2][maxN];

inline void add( int x, int y, int D )
{
  if (y > n)
  {
    puts("YES");
    exit(0);
  }
  if (y < 0 || d[x][y] || s[x][y] == 'X')
    return;
  //printf("[%d,%d] : %d\n", x, y, D);
  d[x][y] = D;
  if (D <= y)
    qx[qen] = x, qy[qen++] = y;
}

int main()
{
  scanf("%d%d ", &n, &k);
  forn(i, 2)
    gets(s[i]);
  
  add(0, 0, 0);
  while (qst < qen)
  {
    int x = qx[qst], y = qy[qst++], D = d[x][y] + 1;
    add(x ^ 1, y + k, D);
    add(x, y + 1, D);
    add(x, y - 1, D);
  }
  puts("NO");
  return 0;
}