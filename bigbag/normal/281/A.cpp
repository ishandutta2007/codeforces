#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char s[1111];
int main()
{
  gets(s);
  if (s[0] > 90) s[0] = s[0] - 32;
  printf("%s", s);
  return 0;
}