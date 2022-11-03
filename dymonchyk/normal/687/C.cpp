#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool dp[505][505][505];
int arr[505];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", &arr[i]);
  dp[0][0][0] = true;
  for (int i = 0; i < n; ++i) {
    for (int a = 0; a <= k; ++a) {
      for (int b = 0; b <= k; ++b) {
        if (!dp[i][a][b]) continue;
        dp[i + 1][a][b] = true;
        if (a + arr[i] <= k) dp[i + 1][a + arr[i]][b] = true;
        if (b + arr[i] <= k) dp[i + 1][a][b + arr[i]] = true;
      }
    }
  }

  set<int> ret;
  for (int i = 0; i <= k; ++i)
    if (dp[n][i][k - i]) ret.insert(i);

  cout << ret.size() << endl;
  for (int x : ret)
    cout << x << " ";
  cout << endl;

  return 0;
}