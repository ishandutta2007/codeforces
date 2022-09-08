#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, k, i, x, y;

int main()
{
  scanf("%d %d", &n, &k);
  if (n * (n - 1) / 2 <= k) printf("no solution");
  else
  {
    printf("0 0\n");
    x = 10000;
    y = 0;
    for (i = 1; i < n; i++)
    {
      printf("%d %d\n", x, y);
      x -= 2;
      y -= 10000;
    }
  }
}