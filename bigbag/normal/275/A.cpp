#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long i, j, x, m[5][5], m1[5][5];

int main()
{
  for (i = 1; i < 4; i++)
    for (j = 1; j < 4; j++)
    {
      scanf("%d", &m[i][j]);
      x = m[i][j] % 2;
      m1[i][j] = (m1[i][j] + x) % 2;
      m1[i][j - 1] = (m1[i][j - 1] + x) % 2;
      m1[i][j + 1] = (m1[i][j + 1] + x) % 2;
      m1[i - 1][j] = (m1[i - 1][j] + x) % 2;
      m1[i + 1][j] = (m1[i + 1][j] + x) % 2;
    }
  for (i = 1; i < 4; i++)
  {
    for (j = 1; j < 4; j++)
      printf("%d", (m1[i][j] + 1) % 2);
    printf("\n");
  }
  return 0;
}