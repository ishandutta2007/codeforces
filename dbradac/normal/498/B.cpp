#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 5005;

double dp[MAX][MAX];
double p[MAX];
int t[MAX];

int main()
{
  int n=0, ukt;
  double rje=0;

  scanf("%d%d", &n, &ukt);

  for (int i=0; i<n; i++) {
    int tmp;
    scanf("%d%d", &tmp, &t[i]);
    p[i] = tmp / 100.0;
  }

  dp[0][0] = 1;
  for (int i=0; i<n; i++) {
    double pot = 1;
    for (int j=0; j<t[i]-1; j++)
      pot *= (1 - p[i]);

    double prob=0;
    for (int j=0; j<=ukt; j++) {
      dp[i+1][j] = prob * p[i];
      if (j >= t[i])
        dp[i+1][j] += dp[i][j-t[i]] * pot;      

      prob *= (1 - p[i]);
      prob += dp[i][j];
      if (j >= t[i] - 1)
        prob -= dp[i][j-t[i]+1] * pot;
    }
  }

  t[n] = MAX;
  p[n] = 0.0;

  for (int i=0; i<=n; i++) {
    double pot = 1;
    for (int j=ukt; j>=0 && j>ukt-t[i]; j--) {
      rje += (dp[i][j] * i * pot);
      pot *= (1 - p[i]);
    }
  } 

  printf("%lf\n", rje);

  return 0;
}