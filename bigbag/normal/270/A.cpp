#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, j, a, n, f, x, m[111];

int main()
{
  scanf("%d", &n);
  for (i = 3; i <= 1000; i++)
    if (((i - 2) * 180) % i == 0)
    {
      a++;
      m[a] = ((i - 2) * 180) / i;
    }
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &x);
    f = 0;
    for (j = 1; j <= a; j++)
      if (x == m[j])
      {
        f = 1;
        break;
      }
    if (f == 1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}