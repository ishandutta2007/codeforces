#include <cstdio>

const int MAX = 105;

int p[MAX];

int main()
{
  int n, pr=-1, zad=-1;

  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    if (p[i]) {
      if (pr == -1)
        pr = i;
      zad = i;
    }
  }

  if (pr == -1)
    printf("0\n");
  else {
    int rje=zad - pr + 1;
    for (int i=pr; i<zad; i++)
      if (!p[i] && (!p[i+1] || (i && !p[i-1])))
        rje--;

    printf("%d\n", rje);
  }

  return 0;
}