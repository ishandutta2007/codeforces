// solution based on tutorial
#include <bits/stdc++.h>

using namespace std;

int n, k, c;
int cost = 0;
int dp[2][1001];
int tot[1001];
vector <int> um[100002];

int main() {
  scanf ("%d %d", &n, &k);
  c = min ((int) sqrt (6 * k) + 1, n);
  for (int i = 0; i < k; i++) {
    int r, cc;
    scanf ("%d %d", &r, &cc);
    if (r <= n - c) {
      cost += 3;
    }
    else {
      um[cc].push_back(n - r);
    }
  }
  dp[n % 2][1] = 0;
  if (um[n].empty()) {
    dp[n % 2][0] = 0;
  }  
  else {
    dp[n % 2][0] = 3;
  }
  //  printf ("dp[%d][%d] = %d\n", n, 0, dp[n%2][0]); 
  for (int i = n - 1; i >= 1; i--) {
    for (int j = 0; j <= c; j++) tot[j] = 0;
    for (int j = 0; j < (int) um[i].size(); j++) {
      tot[um[i][j]]++;
    }
    for (int j = c - 1; j >= 0; j--) {
      tot[j] += tot[j + 1];
    }
    int moo = 1000000000;
    for (int j = min (n - i, c); j >= 0; j--) {
      moo = min (moo, 2 + (j + 1) * (j + 2) / 2 + 3 * tot[j + 1] + dp[(i+1)%2][j]);
      //   printf ("MOO: %d\n", moo);
      dp[i % 2][j] = ((j == 0) ? dp[(i+1)%2][j] : dp[(i+1)%2][j-1]) + 3 * tot[j];
      dp[i % 2][j] = min (dp[i % 2][j], moo);
      //  printf ("dp[%d][%d] = %d\n", i, j, dp[i % 2][j]);
    }
  }
  printf ("%d\n", dp[1][0] + cost);
}