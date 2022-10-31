#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 55;

int p[2][MAX];
int pref[2][MAX];
int cross[MAX];
int n;

int Eval(int x)
{
  return pref[0][x-1] + cross[x] + pref[1][n-1] - pref[1][x-1];
}

int main()
{
  scanf("%d", &n);

  for (int j=0; j<2; j++)
    for (int i=1; i<n; i++) {
      scanf("%d", &p[j][i]);
      pref[j][i] = pref[j][i-1] + p[j][i];
    }

  for (int i=1; i<=n; i++)
    scanf("%d", &cross[i]);

  int rje = 1e9;
  for (int i=1; i<=n; i++)
    for (int j=i+1; j<=n; j++)
      rje = min(rje, Eval(i) + Eval(j));

  printf("%d\n", rje);

  return 0;
}