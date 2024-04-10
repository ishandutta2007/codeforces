#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long k, s, t, i, n, kol, kol1, m[222];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &m[i]);
    m[i + n] = m[i];
  }
  scanf("%d%d", &s, &t);
  if (s == t) printf("0");
  else
  {
    if (s > t)
    {
      k = s;
      s = t;
      t = k;
    }
    kol = 0;
    kol1 = 0;
    for (i = s; i < t; i++)
      kol = kol + m[i];
    for (i = t; i < n + s; i++)
      kol1 = kol1 + m[i];
    if (kol < kol1) printf("%d", kol);
    else printf("%d", kol1);
  }
  return 0;
}