#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int i, j, ans, kol;
long long x, y, n, m[111];

int main()
{
  scanf("%I64d", &n);
  ans = 0;
  x = 1;
  for (i = 0; i <= 38; i++)
  {
    m[i] = x;
    if (i != 38) x *= 3;
  }

  for (i = 1; i <= 38; i++)
  {
      if (n % m[i] != 0)
      {
        x = n / m[i];
        printf("%I64d", x + 1);
        return 0;
      }
  }
  /*if (n % 3 == 0)
  {
    for (i = 1; i <= 38; i++)
      if (n % m[i] != 0)
      {
        printf("%d", n / m[i] + 1);
        return 0;
      }
    return 0;
  }

  x = 0;
  while (n > 1)
  {
    kol = 0;
    for (i = 38; i >= 0; i--)
      if (m[i] < n)
      {
        y = m[i];
        break;
      }
    //printf("y = %d ", y);
    if (n - y != m[x])
    {
      if ((n - y) % m[x] != 0) kol = (n - y) / m[x];
      else kol = (n - y) / m[x] - 1;
      ans += kol;
      n -= kol * m[x];
      if (kol == 0)
      {
        n -= y;
        ans++;
      }
      //printf("kol = %d  m[x] = %d\n", kol, m[x]);
    }
    x++;
  }
  printf("%d", ans + 1);*/
}