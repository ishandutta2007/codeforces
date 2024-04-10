#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long n, x, i;
char s[5];
int main()
{
  scanf("%d\n", &n);
  for (i = 1; i <= n; i++)
  {
    gets(s);
    if (s[1] == 43) x++;
    else x--;
  }
  printf("%d", x);
}