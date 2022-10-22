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

const int MAXN = 510;
const int INF = 100000000;

int n, m, k;
int cr[MAXN][MAXN], cd[MAXN][MAXN];
int ans[MAXN][MAXN][12];

void Update(int& a, int b) {
  if (a == 0 || a > b) a = b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < m; ++j) cin >> cr[i][j];
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < m; ++j) cin >> cd[i][j];
  }
  if (k & 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << -1 << " ";
      }
      cout << '\n';
    }
    return 0;
  }
  k /= 2;
  for (int t = 0; t < k; ++t) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (i > 0) {
          Update(ans[i][j][t + 1], ans[i - 1][j][t] + cd[i - 1][j]);
        }
        if (i + 1 < n) {
          Update(ans[i][j][t + 1], ans[i + 1][j][t] + cd[i][j]);
        }
        if (j > 0) {
          Update(ans[i][j][t + 1], ans[i][j - 1][t] + cr[i][j - 1]);
        }
        if (j + 1 < m) {
          Update(ans[i][j][t + 1], ans[i][j + 1][t] + cr[i][j]);
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[i][j][k] * 2 << " ";
    }
    cout << '\n';
  }
  return 0;
}