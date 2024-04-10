#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long l, i, j, poz, a, m[111111];
char s[111111];

int main()
{
  gets(s);
  l = strlen(s);
  a = 0;
  poz = 0;
  i = 0;
  while (i < l)
  {
    if (s[i] == 34)
    {
      i++;
      printf("<");
      while (s[i] != 34)
      {
        printf("%c", s[i]);
        i++;
      }
      i++;
      printf(">\n");
    }
    else
    {
      if (s[i] == 32)
        while ((s[i] == 32) && (i < l))
          i++;
      else
      {
        printf("<");
        while ((s[i] != 32) && (s[i] != 34) && (i < l))
        {
          printf("%c", s[i]);
          i++;
        }
        printf(">\n");
      }
    }
  }
}