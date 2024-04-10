#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long i, x, n, a, b, ma, k, m[11111];

int main()
{
  ma = -1111111111;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++)
  {
    scanf("%d%d", &a, &b);
    if (b <= k) x = a;
    else x = a - (b - k);
    if (x > ma) ma = x;
  }
  printf("%d", ma);
  return 0;
}