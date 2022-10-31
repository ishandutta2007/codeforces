#include <cstdio>
#include <ctime>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long double llf;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 105;
const double TL = 1.9;

llf koef[MAX];
llf p[MAX];
llf prefum[MAX], sufum[MAX];

int main()
{
  int n;

  scanf("%d", &n);

  for (int i=1; i<=n; i++) {
    int tmp;
    scanf("%d", &tmp);
    koef[i] = 1 - (tmp / 100.0);
  }

  llf rje = n;
  for (int i=1; i<=n; i++)
    p[i] = koef[i];

  llf tmpum = 1;
  for (int i=1; i<=n; i++)
    tmpum *= 1 - p[i];
  rje += 1 - tmpum;

  for (int i=0; (double) clock() / CLOCKS_PER_SEC < TL; i++) {

    int indm = 1;

    for (int j=2; j<=n; j++) {
      llf tmpja = (1 - p[j] * koef[j]) * (1 - p[indm]);
      llf tmpon = (1 - p[j]) * (1 - p[indm] * koef[indm]);
      if (tmpja > tmpon)
        indm = j;
    }

    p[indm] *= koef[indm];
    llf tmpum = 1;
    for (int j=1; j<=n; j++)
      tmpum *= 1 - p[j];

    rje += 1 - tmpum;
  }

  printf("%.10lf\n", (double) rje);

  return 0;
}