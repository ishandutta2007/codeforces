#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long n, i, j, kol, kol1, kol2, m[2111111], m1[2111111];
char s[2111111], s1[2111111];

int main()
{
  scanf("%d\n", &n);
  gets(s);
  gets(s1);
  n = 2 * n;
  for (i = 0; i < n; i++)
    m[i + 1] = s[i] - 48;
  for (i = 0; i < n; i++)
    m1[i + 1] = s1[i] - 48;
  kol = 0;
  kol1 = 0;
  kol2 = 0;
  for (i = 1; i <= n; i++)
  {
    if ((m[i] == 1) && (m1[i] == 1)) kol++;
    else
    {
      kol1 += m[i];
      kol2 += m1[i];
    }
  }
  //printf("%d %d %d", kol, kol1, kol2);
  if (kol % 2 == 0)
  {
    if ((kol1 == kol2) || (kol1 + 1 == kol2)) printf("Draw");
    else
    {
      if (kol1 > kol2) printf("First");
      if (kol2 > kol1) printf("Second");
    }
  }
  else
  {
    kol1++;
    if ((kol1 == kol2) || (kol1 + 1 == kol2)) printf("Draw");
    else
    {
      if (kol1 > kol2) printf("First");
      if (kol2 > kol1) printf("Second");
    }
  }
}