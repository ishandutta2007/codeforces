#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, n1, i, j, x, c, t, otv, m[111111];

long bin(long a, long b)
{
  long y;
  y = (a + b) / 2;
  if ((x > m[y]) && (x <= m[y + 1])) otv = y;
  else
  {
    if (x <= m[y]) bin(a, y);
    if (x > m[y]) bin(y, b);
  }
}

int main()
{
  scanf("%d%d", &n, &n1);
  m[1] = 0;
  m[n + 2] = -1;
  for (i = 1; i <= n; i++)
  {
    scanf("%d%d", &c, &t);
    m[i + 1] = m[i] + c * t;
  }
  for (i = 1; i <= n1; i++)
  {
    scanf("%d", &x);
    bin(1, n + 1);
    printf("%d\n", otv);
  }
}