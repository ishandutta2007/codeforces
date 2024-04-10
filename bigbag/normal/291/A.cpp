#include <stdio.h>
#include <stdlib.h>

long k, n, i, kol, f, m[1111];

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
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  QuickSort(1, n);
  f = 0;
  i = 1;
  kol = 0;
  m[n + 1] = -1;
  while (m[i] == 0)
    i++;
  while  (i <= n)
  {
    k = 1;
    while ((m[i] == m[i + 1]) && (i < n))
    {
      i++;
      k++;
    }
    if (k > 2)
    {
      f = 1;
      break;
    }
    if (k == 2) kol++;
    i++;
  }
  if (f == 1) printf("-1");
  else printf("%d", kol);
}