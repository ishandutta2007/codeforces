#include <cstdio>

int main()
{
  printf("2001\n");

  for (int i=1; i<=1000; i++)
    printf("%d 1 %d 2\n", i, i);

  printf("1 1 2 2\n");

  for (int i=1; i<=1000; i++)
    printf("%d 1 %d 2\n", i, i);

  return 0;
}