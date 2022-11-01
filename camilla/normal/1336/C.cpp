#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;

const int MOD = 998244353;
const int N = 3000 + 10;
char s[N], t[N];
int dp[N][N];

void add(int& x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}

int solve(char *s, int n, char* t, int m) {
  int ret = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = n + 1; j > i; --j) {
      int rem = i + n - j + 1;
      int k = n - rem;
      dp[i][j] = 0;
      if (i < 1 && j > m) {
        dp[i][j] = rem + 1;
      } else {
        if (i >= 1 && i <= m) {
          if (s[k] == t[i]) add(dp[i][j], dp[i - 1][j]);
        } else {
          if (i - 1 >= 0) add(dp[i][j], dp[i - 1][j]);
        }
        if (j >= 1 && j <= m) {
          if (s[k] == t[j]) add(dp[i][j], dp[i][j + 1]);
        } else {
          if (j + 1 <= n + 1) add(dp[i][j], dp[i][j + 1]);
        }
      }
      //cout << i << " " << j << " " << dp[i][j] << endl;
      //cout << i << " " << j << " " << k << " " << dp[i][j] << endl;
      if (i + 1 == j) add(ret, dp[i][j]);
    }
  }
  return ret;
}

int main() {
  scanf("%s%s", s, t + 1);
  int n = strlen(s), m = strlen(t + 1);
  int ret = solve(s, n, t, m);
  printf("%d\n", ret);
  return 0;
}