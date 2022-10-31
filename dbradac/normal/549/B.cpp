#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 105;

char s[MAX][MAX];
int treba[MAX], ima[MAX];
int done[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%s", s[i]);

  for (int i=0; i<n; i++)
    scanf("%d", &treba[i]);

  int kol=0;
  for (;;) {
    int dalje = 0;
    for (int i=0; i<n; i++) {
      if (!done[i] && ima[i] == treba[i]) {
        done[i] = 1;
        dalje = 1;
        kol++;
        for (int j=0; j<n; j++)
          ima[j] += s[i][j] - '0';

        break;
      }
    }
    if (!dalje)
      break;
  }

  printf("%d\n", kol);

  for (int i=0; i<n; i++)
    if (done[i])
      printf("%d ", i+1);
  printf("\n");

  return 0;
}