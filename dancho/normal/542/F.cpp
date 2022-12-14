#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;

int n, t;
int dp[101][1001];

vector<int> lv[128];
int cbl[128];
int sbl[128];

int getDP(int l, int nd) {
  if (l >= t) {
    return (0);
  }
  if (nd == 0) {
    return 0;
  }
  if (cbl[l] <= nd) {
    return (sbl[l]);
  }
  if (dp[l][nd] != -1) {
    return dp[l][nd];
  }
  dp[l][nd] = getDP(l + 1, nd * 2);
  int k = 0;
  for (int i = 0; i < (int) lv[l].size() && i < nd; ++i) {
    k += lv[l][i];
    dp[l][nd] = max(dp[l][nd], getDP(l + 1, (nd - i - 1) * 2) + k);
  }
  return dp[l][nd];
}

int main() {
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; ++i) {
    int ti, q;
    scanf("%d %d", &ti, &q);
    lv[t - ti].push_back(q);
  }
  for (int i = 0; i <= t; ++i) {
    sort(lv[i].begin(), lv[i].end(), greater<int>());
  }
  for (int i = t - 1; i >= 0; --i) {
    cbl[i] = cbl[i + 1] + lv[i].size();
    sbl[i] = sbl[i + 1];
    for (int j = 0; j < (int) lv[i].size(); ++j) {
      sbl[i] += lv[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));
  printf("%d\n", getDP(0, 1));

  return 0;
}