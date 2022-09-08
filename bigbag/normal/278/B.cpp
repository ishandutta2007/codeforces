#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long f, f1, i, i1, j, j1, n, x, m[33][22], l[22];
char s[22];

int main()
{
  scanf("%d\n", &n);
  for (i = 1; i <= n; i++)
  {
    gets(s);
    l[i] = strlen(s);
    for (j = 0; j < l[i]; j++)
    {
      x = s[j];
      m[i][j] = x;
    }

  }
  f1 = 0;
  for (i = 97; i < 123; i++)
  {
    f = 0;
    for (j = 1; j <= n; j++)
      for (j1 = 0; j1 < l[j]; j1++)
        if (i == m[j][j1])
        {
          f = 1;
          break;
        }
    if (f == 0)
    {
      f1 = 1;
      printf("%c", i);
      break;
    }
  }
  if (f1 == 0)
  {
    for (i = 97; i < 123; i++)
    {
      for (i1 = 97; i1 < 123; i1++)
      {
        f = 0;
        for (j = 1; j <= n; j++)
          for (j1 = 0; j1 < l[j] - 1; j1++)
            if ((i == m[j][j1]) && (i1 == m[j][j1 + 1]))
            {
              f = 1;
              break;
            }
        if (f == 0)
        {
          f1 = 1;
          printf("%c%c", i, i1);
          break;
        }
      }
      if (f1 == 1) break;
    }
  }
  return 0;
}