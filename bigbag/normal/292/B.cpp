#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long kol, n, n1, i, j, f, a, b, m[111111];

int main()
{
  scanf("%d%d", &n, &n1);
  f = 0;
  for (i = 1; i <= n1; i++)
  {
    scanf("%d%d", &a, &b);
    m[a]++;
    m[b]++;
  }
  if (n - 1 == n1)
  {
    kol = 0;
    f = 0;
    for (i = 1; i <= n; i++)
    {
      if (m[i] == 1) kol++;
      else if (m[i] != 2)
      {
        f = 1;
        break;
      }
    }
      if ((f == 0) && (kol == 2)) printf("bus topology");
      else
      {
        f = 0;
        kol = 0;
        for (i = 1; i <= n; i++)
        {
          if (m[i] == n - 1) kol++;
          else if (m[i] != 1)
          {
            f = 1;
            break;
          }
        }
        if ((f == 0) && (kol == 1)) printf("star topology");
        else printf("unknown topology");
      }
  }
  else
  {
    f = 0;
    for (i = 1; i <= n; i++)
      if (m[i] != 2)
      {
        f = 1;
        break;
      }
    if (f == 0) printf("ring topology");
    else printf("unknown topology");
  }
}