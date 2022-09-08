#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long i, x, n, kol, sym;

int main()
{
  scanf("%d", &n);
  sym = 0;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    sym = sym + x;
  }
  kol = 0;
  for (i = 1; i < 6; i++)
    if ((sym + i) % (n + 1) != 1) kol++;
  printf("%d", kol);
  return 0;
}