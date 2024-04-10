#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long bred, x, n, i, j, k, a, max1, m[111111], m1[111111], s[22];

int main()
{
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    scanf("%d", &m[i]);
  s[0] = 1;
  for (i = 1; i <= 20; i++)
    s[i] = s[i - 1] * 2;
  a = 0;
  i = n;
  m[0] = -11;
  for (bred = 1; bred <= 10; bred++)
  {
    while (i > 0)
    {
      j = i;
      while (m[j] == m[j - 1] && j > 1)
        j--;
      x = i - j + 1;
      i = j - 1;
      while (x != 0)
      {
        for (j = 0; j <= 17; j++)
          if (s[j] > x) break;
        j--;
        a++;
        m1[a] = m[i + 1] + j;
        x = x - s[j];
      }
    }
    for (i = 1; i <= a; i++)
      m[i] = m1[i];
    sort(m + 1, m + a + 1);
    i--;
    k = a;
    a = 0;
  }
  a = k;
  printf("%d", m[a] - a + 1);
}