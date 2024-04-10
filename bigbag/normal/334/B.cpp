#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int i, j, f, k, x[11], y[11];

int main()
{
  for (i = 1; i <= 8; i++)
    scanf("%d%d", &x[i], &y[i]);
  for (i = 1; i <= 8; i++)
    for (j = i + 1; j <= 8; j++)
      if (x[i] > x[j] || x[i] == x[j] && y[i] > y[j])
      {
        k = x[i];
        x[i] = x[j];
        x[j] = k;
        k = y[i];
        y[i] = y[j];
        y[j] = k;
      }
  f = 0;
  if (x[1] == x[2] && x[2] == x[3] && x[4] == x[5] && x[6] == x[7] && x[7] == x[8] && x[3] < x[4] && x[5] < x[6])
  {
    if (y[1] < y[2] && y[2] < y[3] && y[1] == y[4] && y[3] == y[5] && y[1] == y[6] && y[2] == y[7] && y[3] == y[8]) f = 1;
  }
  if (f == 1) printf("respectable");
  else printf("ugly");
}