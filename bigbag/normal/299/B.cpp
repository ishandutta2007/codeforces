#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long n, poz, k, f, i, j, x, m[311111], m1[311111], head, tail, och[1111111];
char s[311111];

int main()
{
  scanf("%d%d\n", &n, &k);
  gets(s);
  for (i = 0; i < n; i++)
  {
    m1[i + 1] = 0;
    m[i + 1] = 1;
    if (s[i] == 46) m[i + 1] = 0;
  }
  f = 0;
  i = 1;
  while (i <= n)
  {
    poz = -1;
    x = (i + k < n) ? i + k : n;
    for (i = i + 1; i <= x; i++)
      if (m[i] == 0) poz = i;
    if (poz == -1) break;
    i = poz;
    if (i == n)
    {
      f = 1;
      break;
    }
  }
  if (f == 1) printf("YES");
  else printf("NO");
}