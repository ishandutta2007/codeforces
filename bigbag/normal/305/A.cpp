#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, i, j, f, kol, m[111], m1[111], a, b, c, d, e;

int main()
{
  scanf("%d", &n);
  a = 0;
  b = 0;
  c = 0;
  d = 0;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &m[i]);
    if (m[i] == 0) a++;
    if (m[i] > 0 && m[i] < 10) b = m[i];
    if (m[i] >= 10 && m[i] < 100 && m[i] % 10 == 0) c = m[i];
    if (m[i] >= 10 && m[i] < 100 && m[i] % 10 != 0) e = m[i];
    if (m[i] == 100) d = 1;
  }
  kol = a;
  if (b != 0) kol++;
  if (c != 0) kol++;
  if (c == 0 && b == 0 && e != 0)
  {
    f = 1;
    kol++;
  }
  if (d != 0) kol++;
  printf("%d\n", kol);
  for (i = 1; i <= a; i++)
    printf("0 ");
  if (b != 0) printf("%d ", b);
  if (c != 0) printf("%d ", c);
  if (f == 1) printf("%d ", e);
  if (d != 0) printf("100");
}