#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long a, k, i, j, j1, n, m[5];

int main()
{
  scanf("%d", &n);
  i = n + 1;
  do
  {
    k = i;
    a = 0;
    while (k != 0)
    {
      a++;
      m[a] = k % 10;
      k = k / 10;
    }
    k = 0;
    for (j = 1; j < a; j++)
      for (j1 = j + 1; j1 <= a; j1++)
        if (m[j] == m[j1]) k = 1;
    if (k == 0)
    {
      printf("%d", i);
      break;
    }
    i++;
  }
  while (1);
  return 0;
}