#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAX = 5005, MAXVEL = 10000005;

int ima[MAXVEL];
int p[MAX];

int main()
{
  int n, kolko, q;

  scanf("%d%d", &n, &kolko);

  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    ima[p[i]] = 1;
  }

  scanf("%d", &q);

  for (int i=0; i<q; i++) {
    int val;
    scanf("%d", &val);
    int rje = MAX;
    for (int j=0; j<n; j++) {
      for (int k=0; k<=kolko; k++) {
        if (k * p[i] == val)
          rje = min(rje, k);
        for (int l=1; l<=kolko-k; l++) {
          int tmp = val - k * p[j], x = tmp / l;
          if (!(tmp % l) && x >= 0 && x < MAXVEL && ima[x] == 1)
            rje = min(rje, k + l);
        }
      }
    }
    if (rje == MAX)
      printf("-1\n");
    else
      printf("%d\n", rje);
  }

  return 0;
}