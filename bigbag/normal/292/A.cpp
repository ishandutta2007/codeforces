#include <stdio.h>
#include <stdlib.h>

long x, n, a, b, ka, kb, i, j, max1, t, kol;

int main()
{
  scanf("%d%d%d", &n, &a, &b);
  if (n == 1) printf("%d %d", a + b, b);
  else
  {
    kol = b;
    ka = a;
    kb = b;
    max1 = b;
    for (i = 2; i <= n; i++)
    {
      scanf("%d%d", &a, &b);
      kol -= a - ka;
      if (kol < 0) kol = 0;
      kol += b;
      if (kol > max1) max1 = kol;
      ka = a;
      kb = b;
    }
    printf("%d %d", a + kol, max1);
  }
}