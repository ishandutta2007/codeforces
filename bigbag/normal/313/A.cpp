#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, a, b, c, d;

long max1(long x, long y)
{
  return (a > b) ? a : b;
}

int main()
{
  scanf("%d", &n);
  if (n >= 0) printf("%d", n);
  else
  {
    n = -n;
    a = -(n / 10);
    b = -((n / 100) * 10 + (n % 10));
    printf("%d", max1(a, b));
  }
}