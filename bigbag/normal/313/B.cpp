#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

long n, i, j, l, a, b, m[111111], m1[111111];
char s[111111];
int main()
{
  gets(s);
  l = strlen(s);
  for (i = 0; i < l; i++)
    m[i + 1] = (s[i] == 46) ? 1 : 0;
  scanf("%d", &n);
  m1[l] = 0;
  for (i = l - 1; i > 0; i--)
  {
    m1[i] = m1[i + 1];
    if (m[i] == m[i + 1]) m1[i]++;
  }
  for (i = 1; i <= n; i++)
  {
    scanf("%d %d", &a, &b);
    printf("%d\n", m1[a] - m1[b]);
  }
}