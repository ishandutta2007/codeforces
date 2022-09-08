#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long i, j, n, t, m[55];
char s[55];

int main()
{
  scanf("%d%d\n", &n, &t);
  gets(s);
  for(i = 0; i < n; i++)
    m[i + 1] = s[i];
  for (i = 1; i <= t; i++)
  {
    j = 1;
    while (j < n)
    {
      if ((m[j] == 66) && (m[j + 1] == 71))
      {
        m[j] = 71;
        m[j + 1] = 66;
        j++;
      }
      j++;
    }
  }
  for (i = 1; i <= n; i++)
    printf("%c", m[i]);
  return 0;
}