#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1<<9;

int p[MAX][MAX];

int main()
{
  int n;
  char sl[3] = "+*";

  scanf("%d", &n);

  for (int i=0; i<(1<<n); i++)
    p[i][i] = 1;

  for (int i=0; i<(1<<n); i++) {
    for (int j=0; j<n; j++) {
      for (int k=0; k<(1<<n); k++) {
        if (!(k & (1<<j))) {
          int a = p[i][k];
          int b = p[i][k ^ (1<<j)];
          p[i][k] = a - b;
          p[i][k ^ (1<<j)] = a + b;
        }
      }
    }
  }

  for (int i=0; i<(1<<n); i++) {
    for (int j=0; j<(1<<n); j++) {
//      printf("ASDF %d %d %d\n", i, j, p[i][j]);
      printf("%c", sl[(p[i][j] + 1) / 2]);
    }
    printf("\n");
  }

  return 0;
}