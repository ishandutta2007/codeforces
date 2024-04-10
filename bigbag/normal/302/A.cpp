#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long l, r, x, n, n1, i, j, m[211111], m1[5];
int main()
{
  scanf("%d%d", &n, &n1);
  for (i = 1; i <= n; i++)
  {
    scanf("%d", &m[i]);
    m1[m[i] + 1]++;
  }
  for (i = 1; i <= n1; i++)
  {
    scanf("%d%d", &l, &r);
    x = r - l + 1;
    if ((x % 2 == 0) && (m1[0] >= x / 2) && (m1[2] >= x / 2)) printf("1\n");
    else printf("0\n");
  }
}