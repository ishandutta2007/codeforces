#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long k, f, n, s, t, i, j, kol, m[111111], m1[111111], poz;

int main()
{
  scanf("%d%d%d", &n, &s, &t);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  poz = s;
  kol = 0;
  f = 0;
  while (poz != t)
  {
    m1[poz] = 1;
    if (m1[m[poz]] == 0)
    {
      kol++;
      poz = m[poz];
    }
    else
    {
      f = 1;
      printf("-1");
      break;
    }
  }
  if (f == 0) printf("%d", kol);
}