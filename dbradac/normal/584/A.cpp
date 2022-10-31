#include <cstdio>

int main()
{
  int n, t;

  scanf("%d%d", &n, &t);

  if (n == 1 && t < 10)
    printf("%d\n", t);
  else {
    if (t == 10) {
      if (n == 1)
        printf("-1\n");
      else {
        printf("1");
        for (int i=0; i<n-1; i++)
          printf("0");
        printf("\n");
      }
    }
    else {
      int ost=1;
      for (int i=0; i<n-1; i++)
        ost = (ost * 10) % t;

      printf("1");
      for (int i=0; i<n-2; i++)
        printf("0");
      printf("%d\n", t - ost);
    }
  }

  return 0;
}