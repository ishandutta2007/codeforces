#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, i, j, f, kol, m[111], m1[111];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d%d", &m[i], &m1[i]);
  kol = 0;
  for (i = 1; i <= n; i++)
  {
    f = 0;
    for (j = 1; j < i; j++)
      if (m[i] == m1[j])
      {
        f = 1;
        break;
      }
    for (j = i + 1; j <= n; j++)
      if (m[i] == m1[j])
      {
        f = 1;
        break;
      }
    if (f == 0) kol++;
  }
  printf("%d", kol);
}