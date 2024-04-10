#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long h, i, j, n, t, m[111111];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  t = 0;
  h = 0;
  m[n + 1] = 111111111;
  for (i = 1; i <= n; i++)
  {
    t += (m[i] - h) + 2;
    h = m[i];
    if (h > m[i + 1])
    {
      t += h - m[i + 1];
      h = m[i + 1];
    }
  }
  printf("%d", t - 1);
  return 0;
}