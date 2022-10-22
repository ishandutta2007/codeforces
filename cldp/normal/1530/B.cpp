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
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> x(n, vector<int>(m, 0));
    for (int i = 0; i < n; i += 2) {
      x[i][0] = x[i][m - 1] = 1;
    }
    for (int j = 2; j + 2 < m; j += 2) {
      x[0][j] = x[n - 1][j] = 1;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << x[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}