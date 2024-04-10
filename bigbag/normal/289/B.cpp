#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long l1, r1, kol, f, x, y, a, n, n1, d, i, j, m[11111];

int QuickSort(long l, long r)
{
  long i, j, k, x;
  i = l;
  j = r;
  x = m[i + 1];
  do
  {
    while (m[i] < x)
      i++;
    while (m[j] > x)
      j--;
    if (i <= j)
    {
      k = m[i];
      m[i] = m[j];
      m[j] = k;
      i++;
      j--;
    }
  }
  while (i <= j);
  if (l < j) QuickSort(l, j);
  if (i < r) QuickSort(i, r);
}

int main()
{
  scanf("%d%d%d%d", &n, &n1, &d, &m[1]);
  x = m[1] % d;
  f = 0;
  for (i = 2; i <= n * n1; i++)
  {
    scanf("%d", &m[i]);
    if (m[i] % d != x) f = 1;
  }
  if (f == 1) printf("-1");
  else
  {
    n = n * n1;
    QuickSort(1, n);
    kol = 0;
    x = 0;
    if (n % 2 == 1) x = 1;
    x += n / 2;
    for (i = 1; i <= n; i++)
      kol += abs(m[x] - m[i]) / d;
    printf("%d", kol);
  }
  return 0;
}