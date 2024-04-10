#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, n, kol, x, y;
char s[55];

int main()
{
  scanf("%d\n", &n);
  gets(s);
  kol = 0;
  for(i = 0; i < n - 1; i++)
    if (s[i] == s[i + 1]) kol++;
  printf("%d", kol);
  return 0;
}