#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 31;

double dp[205][MAX][MAX];
int p[MAX];
int n, k;
int brmog;

int Npoz(int l, int r, int poz)
{
  if (poz < l || poz > r)
    return poz;

  return r + l - poz;
}

double Rek(int a, int b, int kor)
{
  if (kor == k) {
    if (a > b)
      return 1;    
    return 0;
  }

  if (dp[kor][a][b] > -0.5)
    return dp[kor][a][b];
  
  double rje=0;
  for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {
      int na = Npoz(i, j, a), nb = Npoz(i, j, b);
      rje += Rek(na, nb, kor + 1);
    }
  }

  return dp[kor][a][b] = rje / brmog;
}

int main()
{
  double rje=0;

  scanf("%d%d", &n, &k);
  brmog = n * (n - 1) / 2 + n;

  for (int i=0; i<n; i++) 
    scanf("%d", &p[i]);

  for (int i=0; i<205; i++)
    for (int j=0; j<MAX; j++)
      for (int k=0; k<MAX; k++)
        dp[i][j][k] = -1;

  for (int i=0; i<n; i++) {
    for (int j=i; j<n; j++) {
      if (p[i] > p[j])
        rje += 1 - Rek(i, j, 0);
      else
        rje += Rek(i, j, 0);
    }
  }

  printf("%.12lf\n", rje);

  return 0;
}