#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <cmath>

using namespace std;

double dp[5005][5005];
int tm[5005];
double prob[5005];

int main() {
  int n, T;
  cin >> n >> T;
  dp[0][0] = 1.0;
  tm[n + 1] = T + 5; prob[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    double p; int t;
    cin >> p >> t; p /= 100;
    tm[i] = t; prob[i] = p; 
    double pr = 1;
    for (int q = 1; q < t; ++q) {
      pr *= (1 - p);
    }
    if (fabs(p - 1.0) < 1e-6) {
      for (int j = 1; j <= T; ++j)
        dp[i][j] = dp[i - 1][j - 1];
      continue;
    }
    double sum = 0;
    for (int j = i - 1; j <= T; ++j) {
      dp[i][j] = sum * p;
      if (j - t >= 0)
        dp[i][j] += dp[i - 1][j - t] * pr;
      sum *= (1 - p);
      sum += dp[i - 1][j];
      if (j - t + 1 >= 0)
        sum -= dp[i - 1][j - t + 1] * pr;
    }
  }
  // for (int i = 0; i <= n; ++i) {
  //   for (int j = 0; j <= T; ++j)
  //     cout << dp[i][j] << " ";
  //   cout << endl;
  // }
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    double mult = 1;
    for (int j = T; j > max(0, T - tm[i + 1]); --j) {
      // cout << i << "  " << j << endl;
      ans += i * dp[i][j] * mult;
      mult *= (1 - prob[i + 1]);
    }
  }
  printf("%.9lf\n", ans);
  return 0;
}