#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, j, n, kol, m[99], m1[99];

int main()
{
  scanf("%d", &n);
  kol = 0;
  for(i = 1; i <= n; i++)
    kol += (n - i) * i + 1;
  printf("%d", kol);
  return 0;
}