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
    vector<string> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    bool R1 = false, R0 = false, W1 = false, W0 = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (x[i][j] == '.') continue;
        if ((i + j) & 1) {
          if (x[i][j] == 'R') R1 = true; else W1 = true;
        } else {
          if (x[i][j] == 'R') R0 = true; else W0 = true;
        }
      }
    }
    if (R1 && R0) {
      cout << "NO\n";
      continue;
    }
    if (W1 && W0) {
      cout << "NO\n";
      continue;
    }
    if (W1 && R1) {
      cout << "NO\n";
      continue;
    }
    if (W0 && R0) {
      cout << "NO\n";
      continue;
    }
    if (R1 || W0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if ((i + j) & 1) x[i][j] = 'R'; else x[i][j] = 'W';
        }
      }
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if ((i + j) & 1) x[i][j] = 'W'; else x[i][j] = 'R';
        }
      }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) cout << x[i] << '\n';
  }
  return 0;
}