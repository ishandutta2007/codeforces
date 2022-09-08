#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long n, k, i, j, m[111111];
int main()
{
  scanf("%d%d", &n, &k);
  for (i = 1; i < n - k; i++)
    printf("%d ", i);
  for (i = n - k; i <= n; i++)
    printf("%d ", n + n - k - i);
}