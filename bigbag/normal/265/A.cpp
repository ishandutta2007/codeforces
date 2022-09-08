#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, j, x, n, t, m[55];
char s[55], s1[55];

int main()
{
  gets(s);
  gets(s1);
  n = strlen(s1);
  x = 1;
  for (i = 0; i <= n; i++)
    if (s[x - 1] == s1[i]) x++;
  printf("%d", x);
  return 0;
}