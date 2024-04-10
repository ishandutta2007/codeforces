#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long kol;
long i, j, n, m[311111];
int QuickSort(long l, long r)
{
  long i, j, k, x;
  i = l;
  j = r;
  x = m[(l + r) / 2] ;
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
  scanf("%d", &n);
  for (i = n; i >= 1; i--)
    scanf("%d", &m[i]);
  QuickSort(1, n);
  for (i = 1; i <= n; i++)
    kol += abs(i - m[i]);
  printf("%I64d", kol);
  return 0;
}