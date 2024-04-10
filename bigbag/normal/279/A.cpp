#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

long a, f, x, y, kol, pol, i, j;

int main()
{
  scanf("%d%d", &x, &y);
  i = 0;
  j = 0;
  f = 0;
  kol = 0;
  pol = 1;
  do
  {
    if (pol == 1)
    {
      a = i;
      for (i = a; i < a + (kol / 2) + 1; i++)
        if ((i == x) && (j == y))
        {
          f = 1;
          break;
        }
      pol = 2;
    }
    if ((i == x) && (j == y)) f = 1;
    if (f == 1) break;
    kol++;
    //printf("%d %d\n", i, j);
    //getch();
    if (pol == 2)
    {
      a = j;
      for (j = a; j < a + (kol / 2) + 1; j++)
        if ((i == x) && (j == y))
        {
          f = 1;
          break;
        }
      pol = 3;
    }
    if ((i == x) && (j == y)) f = 1;
    if (f == 1) break;
    kol++;
    //printf("%d %d\n", i, j);
    //getch();
    if (pol == 3)
    {
      a = i;
      for (i = i; i > a - (kol / 2) - 1; i--)
        if ((i == x) && (j == y))
        {
          f = 1;
          break;
        }
      pol = 4;
    }
    if ((i == x) && (j == y)) f = 1;
    if (f == 1) break;
    kol++;
    //printf("%d %d\n", i, j);
    //getch();
    if (pol == 4)
    {
      a = j;
      for (j = j; j > a - (kol / 2) - 1; j--)
        if ((i == x) && (j == y))
        {
          f = 1;
          break;
        }
      pol = 1;
    }
    if ((i == x) && (j == y)) f = 1;
    if (f == 1) break;
    kol++;
    //printf("%d %d\n", i, j);
    //getch();
  }
  while(1);
  printf("%d", kol);
  return 0;
}