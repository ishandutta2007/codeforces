#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int i, j, n, x, y;

int main()
{
  scanf("%d", &n);
  x = n * n;
  y = 1;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n / 2; j++)
    {
      printf("%d %d ", x, y);
      x--;
      y++;
    }
    printf("\n");
  }
}