#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long kol, i, x, j, l, m[123];
char s[1111];

int main()
{
  gets(s);
  l = strlen(s);
  for (i = 0; i < l; i++)
    m[s[i]]++;
  kol = 0;
  for (i = 97; i < 123; i++)
    if (m[i] % 2 == 1) kol++;
  if ((kol == 0) || (kol % 2 == 1)) printf("First");
  else(printf("Second"));
  return 0;
}