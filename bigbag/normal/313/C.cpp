#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long k, x, y, n, i, j;
long long sum, m[2111111];

int main()
{
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%I64d", &m[i]);
  sort(m, m + n);
  x = 0;
  k = n;
  while (k != 0)
  {
    k = k / 4;
    x++;
  }
  sum = m[n - 1];
  y = 4;
  for (i = 1; i < x; i++)
  {
    for (j = n - 1; j >= n - y; j--)
      sum += m[j];
    y = y * 4;
  }
  printf("%I64d", sum);
}