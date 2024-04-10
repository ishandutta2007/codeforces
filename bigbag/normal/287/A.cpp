#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int m[5][5], i, j, f;
char ch, s[5], s1[5];
int main()
{
  for (i = 1; i < 5; i++)
  {
    gets(s);
    strcpy(s1, s);
    for (j = 0; j < 4; j++)
    {
      if (j > 0)
      {
        strcpy(s, s1);
        strcpy(s, s + j);
        strcpy(s + j + 1, s + 3 - j);
      }
      if (strncmp(s, "#", 1) == 0) m[i][j + 1] = 1;
    }
  }
  f = 0;
  for (i = 1; i < 4; i++)
  {
    for (j = 1; j < 4; j++)
      if (m[i][j] + m[i][j + 1] + m[i + 1][j] + m[i + 1][j + 1] != 2)
      {
        printf("YES");
        f = 1;
        break;
      }
    if (f == 1) break;
  }

  if (f == 0) printf("NO");
  return 0;
}