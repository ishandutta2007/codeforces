#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long double llf;

const int MAX = 1005;

int n;
int done[MAX];
int prvi[MAX];
llf p[MAX][MAX];
llf eksp[MAX], umn[MAX];

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int tmp;
      scanf("%d", &tmp);
      p[i][j] = tmp / 100.0;
    }
  }

  for (int i=0; i<MAX; i++)
    umn[i] = 1;

  eksp[n-1] = 0;
  done[n-1] = 1;

  int zad = n-1;
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<n; j++) {
      if (done[j] || p[j][zad] < 1e-4)
        continue;

      if (!prvi[j] || 1 + eksp[j] > eksp[zad]) {
        if (!prvi[j])
          eksp[j] = 1 / p[j][zad] + eksp[zad];
        else {
          llf edes = 0;
          if (umn[j] < 1 - (1e-7))
            edes = 1 + eksp[j] - 1 / (1 - umn[j]);

          eksp[j] = ((1 - umn[j]) * edes + umn[j] * p[j][zad] * (1 + eksp[zad]) + umn[j] * (1 - p[j][zad])) / 
                    (1 - umn[j] * (1 - p[j][zad]));
        }

        umn[j] *= (1 - p[j][zad]);
        prvi[j] = 1;
      }
    }

    int ind=-1;
    for (int j=0; j<n; j++)
      if (!done[j] && prvi[j] && (ind == -1 || eksp[j] < eksp[ind]))
        ind=j;

    zad = ind;
    done[ind] = 1;
  }

  printf("%.10lf\n", (double) eksp[0]);

  return 0;
}