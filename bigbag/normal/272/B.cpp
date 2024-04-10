#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long x, m[1111111];
long n, i;
long fun(long a)
{
  do
  {
    if (a == 0)
    {
      return 0;
      break;
    }
    if (a % 2 == 0)
    {
      return fun(a / 2);
      break;
    }
    if (a % 2 == 1)
    {
      return fun(a / 2) + 1;
      break;
    }
  }
  while(1);
}

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    m[fun(x)]++;
  }
  x = 0;
  for (i = 1; i <= 1111100; i++)
    x = x + ((m[i] * (m[i] - 1)) / 2);
  printf("%I64d", x);
  return 0;
}