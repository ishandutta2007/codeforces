#include <cstdio>

const int MAX = 105;

char s[MAX];

int main()
{
  int n;

  scanf("%d%s", &n, s);
  
  int da=0;
  for (int i=0; i<n; i++) {
    for (int j=1; j<n; j++) {
      int ne=0;
      for (int k=0; k<5; k++) {
        int poz = i + j * k;
        if (poz >= n || s[poz] == '.')
          ne = 1;
      }
      if (!ne)
        da = 1;
    }
  }

  if (da)
    printf("yes\n");
  else
    printf("no\n");

  return 0;
}