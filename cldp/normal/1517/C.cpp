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

int x[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> x[i][i];
  for (int i = 1; i <= n; ++i) {
    bool flag = false;
    for (int j = 1; j <= n + 1 - i; ++j) {
      int v = x[i - 1 + j][j];
      if (v == i) {
        flag = true;
        continue;
      }
      if (!flag) x[i + j][j] = v; else x[i - 1 + j][j - 1] = v;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) cout << x[i][j] << " ";
    cout << '\n';
  }
  
  return 0;
}