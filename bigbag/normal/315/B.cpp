#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, n1, i, j, izm[111111], a, b, c, m[111111], m1[111111], x;

int main()
{
  scanf("%d%d", &n, &n1);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  izm[1] = 0;
  x = 0;
  for (i = 1; i <= n1; i++)
  {
    scanf("%d", &a);
    if (a == 1)
    {
      scanf("%d%d", &b, &c);
      m[b] = c;
      m1[b] = x;
    }
    if (a == 2)
    {
      scanf("%d", &b);
      x++;
      izm[x] = izm[x - 1] + b;
    }
    if (a == 3)
    {
      scanf("%d", &b);
      //printf("%d %d %d\n", m[b], izm[x], izm[m1[b]]);
      printf("%d\n", m[b] + izm[x] - izm[m1[b]]);
    }
  }
}