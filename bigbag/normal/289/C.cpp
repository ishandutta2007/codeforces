#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long n, k, i, j;

int main()
{
  scanf("%d%d", &n, &k);
  if ((k == 1) && (n == 1)) printf("a");
  else
  if ((k == 1) || (n < k)) printf("-1");
  else
  {
    for (i = 0; i < n - k + 2; i++)
      printf("%c", (i % 2) + 97);
    for (i = 99; i < 99 + k - 2; i++)
      printf("%c", i);
  }
  return 0;
}