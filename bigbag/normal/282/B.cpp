#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long i, j, n, sym, sym1, m[1111111], m1[1111111], v[11111111];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &m[i], &m1[i]);
  sym = m[1];
  v[1] = 1;
  for (i = 2; i <= n; i++)
  {
    if (abs(sym + m[i] - sym1) < abs(sym1 + m1[i] - sym))
    {
      v[i] = 1;
      sym = sym + m[i];
    }
    else
    {
      v[i] = 2;
      sym1 = sym1 + m1[i];
    }
  }
  if (abs(sym - sym1) <= 500)
  {
    for (i = 1; i <= n; i++)
    {
      if (v[i] == 1) printf("A");
      else printf("G");
    }
  }
  else
  {
    sym = 0;
    sym1 = m1[1];
    v[1] = 2;
    for (i = 2; i <= n; i++)
    {
      if (abs(sym + m[i] - sym1) < abs(sym1 + m1[i] - sym))
      {
        v[i] = 1;
        sym = sym + m[i];
      }
      else
      {
        v[i] = 2;
        sym1 = sym1 + m1[i];
      }
    }
    if (abs(sym - sym1) <= 500)
    {
      for (i = 1; i <= n; i++)
      {
        if (v[i] == 1) printf("A");
        else printf("G");
      }
    }
    else printf("-1");
  }
}