#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

const int MOD = 1000000007;
const int MAXM = 200010;

LL f[10][MAXM][10];
LL g[10][MAXM];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int j = 0; j < 10; ++j) f[j][0][j] = 1;
  for (int i = 1; i < MAXM; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 1; k < 10; ++k) {
        f[j][i][k] = f[j][i - 1][k - 1];
      }
      f[j][i][1] = (f[j][i][1] + f[j][i - 1][9]) % MOD;
      f[j][i][0] = (f[j][i][0] + f[j][i - 1][9]) % MOD;
    }
  }
  for (int i = 0; i < MAXM; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < 10; ++k) {
        g[j][i] = (g[j][i] + f[j][i][k]) % MOD;
      }
    }
  }
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    LL ans = 0;
    while (n > 0) {
      int t = n % 10;
      n /= 10;
      ans = (ans + g[t][m]) % MOD;
    }
    cout << ans << "\n";
  }
  
  return 0;
}