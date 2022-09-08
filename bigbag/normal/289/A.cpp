#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long n, k, sym, x, y, i;

int main()
{
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++)
  {
    scanf("%d%d", &x, &y);
    sym = sym + y - x + 1;
  }
  printf("%d", (k - (sym % k)) % k);
  return 0;
}