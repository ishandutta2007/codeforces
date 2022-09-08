#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long k, x, n, n1, i, j, f, kol, m[111][111], m1[111];
int dfs(long a)
{
  long i;
  m1[a] = 1;
  for (i = 1; i <= n1; i++)
    if (m[a][i] == 1)
    {
      for (j = 1; j <= n; j++)
        if ((m[j][i] == 1) && (m1[j] == 0)) dfs(j);
    }
}
int main()
{
  scanf("%d%d", &n, &n1);
  f = 0;
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &k);
    for (j = 1; j <= k; j++)
    {
      scanf("%d", &x);
      m[i][x] = 1;
      f = 1;
    }
  }
  kol = -1;
  if (f == 0) printf("%d", n);
  else
  {
    do
    {
      f = 0;
      for (i = 1; i <= n; i++)
        if (m1[i] == 0)
        {
          f = i;
          break;
        }
      if (f != 0)
      {
        kol++;
        dfs(f);
      }
      else break;
    }
    while (1);
    printf("%d", kol);
  }
  return 0;
}