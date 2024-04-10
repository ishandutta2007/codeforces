#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long i, j, n, m[5], kol;
char s[211111];

int main()
{
  scanf("%d\n", &n);
  gets(s);
  for (i = 0; i < n; i++)
  {
    if (s[i] == 65) m[1]++;
    if (s[i] == 70) m[2]++;
    if (s[i] == 73) m[3]++;
  }
  if (m[3] == 0) printf("%d", m[1]);
  else if (m[3] == 1) printf("1");
  else printf("0");
}