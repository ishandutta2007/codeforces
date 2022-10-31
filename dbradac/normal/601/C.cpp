#include <cstdio>
#include <algorithm>

using namespace std;

typedef long double llf;

const int MAXN = 105, MAXS = 100100;

llf dp[MAXN][MAXS];
int n, m;
int p[MAXN];

int main()
{
  scanf("%d%d", &n, &m);

  if (m == 1) {
    printf("1.000000000000\n");
    return 0;
  }

  int sum = 0;
  for (int i=0; i<n; i++) {
    scanf("%d", &p[i]);
    sum += p[i];
  }

  dp[0][0] = 1;  

  for (int i=0; i<n; i++) {
    llf tmp = 0, koef = ((llf) 1) / (m - 1);
    llf ss = 0;

    for (int j=0; j<MAXS; j++) {
      if (j)
        tmp += dp[i][j-1];
      if (j - m - 1 >= 0)
        tmp -= dp[i][j-m-1];
      
      llf od = 0;
      if (j - p[i] >= 0)
        od = dp[i][j - p[i]];
      
      dp[i+1][j] = (tmp - od) * koef;
      ss += dp[i+1][j];
    } 
  }


  llf rez = 0;
  for (int i=0; i<sum; i++)
    rez += dp[n][i];

  printf("%.14lf\n", 1.0 + (double)rez * (m - 1));

  return 0;
}