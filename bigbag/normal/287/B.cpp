#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long y, z, n, kol, f, k;
long bin(long long l, long long l1)
{
  long long x;
  x = (l * (l - 1)) / 2;
  x = y - x;
  if ((x - l < n) && (x >= n))
  {
    kol = k - l + 2;
    printf("%I64d", kol);
    f = 1;
  }
  z = l - l1;
  if (z < 0) z = -z;
  if ((f == 0) && (x < n) && (z == 0)) z = 2;
  //printf("%I64d  %I64d  %I64d   %I64d\n", x, l, l1, z);
  //getch();
  if ((f == 0) && (x < n)) bin(l - (z / 2), l);
  if ((f == 0) && (x > n)) bin(1 + l + (z / 2), l);
}
int main()
{
  scanf("%I64d%I64d", &n, &k);
  if (n == 1) printf("0");
  else if (n <= k) printf("1");
  else
  {
    f = 0;
    n = n - k;
    k = k - 2;
    y = (k * (k + 1)) / 2;
    if (y < n) printf("-1");
    //printf("%I64d\n", n);
    if (y - 1 == n) printf("%I64d", k);
    else if (y >= n) bin(1, k);
  }
  return 0;
}