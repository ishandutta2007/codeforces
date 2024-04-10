#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 10000;

int n;
int l[5], r[5];
double rje;

double Vjer(int ind, int lo, int hi)
{
  if (hi < l[ind] || lo > r[ind])
    return 0;
  int pres = min(r[ind], hi) - max(l[ind], lo) + 1;
  return (double) pres / (r[ind] - l[ind] + 1);
}

void Rek(int val, int ind, int istih, int vise, double prob)
{
  if (ind == n) {
    if (vise <= 1 && istih + vise > 1)
      rje += val * prob;
    return;
  }

  Rek(val, ind+1, istih+1, vise, prob * Vjer(ind, val, val));
  Rek(val, ind+1, istih, vise+1, prob * Vjer(ind, val+1, MAX));
  Rek(val, ind+1, istih, vise,   prob * Vjer(ind, 1, val-1));
}

int main()
{
  scanf("%d", &n);

  for (int i=0; i<n; i++)
    scanf("%d%d", &l[i], &r[i]);
  
  for (int i=1; i<=MAX; i++)
    Rek(i, 0, 0, 0, 1.0);

  printf("%.12lf\n", rje);

  return 0;
}