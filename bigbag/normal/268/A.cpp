#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, j, n, kol, m[99], m1[99];

int main()
{
  scanf("%d", &n);
  for(i = 1; i <= n; i++)
    scanf("%d%d", &m[i], &m1[i]);
  kol = 0;
  for (i = 1; i < n; i++)
    for (j = i + 1; j <= n; j++)
    {
      if (m[i] == m1[j]) kol++;
      if (m1[i] == m[j]) kol++;
    }
  printf("%d", kol);
  return 0;
}