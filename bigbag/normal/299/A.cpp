#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long n, i, j, min1, f, m[111111];

int main()
{
  scanf("%d", &n);
  min1 = 1111111111;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &m[i]);
    if (m[i] < min1) min1 = m[i];
  }
  f = 0;
  for (i = 1; i <= n; i++)
    if (m[i] % min1 != 0) f = 1;
  if (f == 0) printf("%d", min1);
  else printf("-1");
}