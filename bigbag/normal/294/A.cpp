#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long i, j, n, n1, x, y, m[111];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  scanf("%d", &n1);
  for (i = 1; i <= n1; i++)
  {
    scanf("%d%d", &x, &y);
    if (x != 1) m[x - 1] += y - 1;
    if (x != n) m[x + 1] += m[x] - y;
    m[x] = 0;
  }
  for (i = 1; i <= n; i++)
    printf("%d\n", m[i]);

  return 0;
}