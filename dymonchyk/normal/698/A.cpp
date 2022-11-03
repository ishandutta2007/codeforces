#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

void update(int &r, int a) {
  if (r == -1 || r > a) r = a;
}

int main() {
  int n, arr[102];
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];
  int dp[3][102] = {0};
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (dp[j][i] == -1) continue;
      if (j != 1 && (arr[i] & 1)) update(dp[1][i + 1], dp[j][i]);
      if (j != 2 && (arr[i] & 2)) update(dp[2][i + 1], dp[j][i]);
      update(dp[0][i + 1], dp[j][i] + 1);
    }
  }
  int r = 1e+9;
  for (int j = 0; j < 3; ++j)
    if (dp[j][n] != -1) r = min(r, dp[j][n]);
  cout << r << endl;
  return 0;
}