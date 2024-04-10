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

const int MAXN = 50010;

int x[MAXN][5];

bool Win(int a, int b) {
  int cnt = 0;
  for (int i = 0; i < 5; ++i) {
    cnt += x[a][i] < x[b][i];
  }
  return cnt > 2;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> x[i][j];
      }
    }
    int p = 0;
    for (int i = 1; i < n; ++i) {
      if (Win(p, i)) continue;
      p = i;
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
      if (i == p) continue;
      if (Win(i, p)) flag = false;
    }
    if (!flag) p = -1; else ++p;
    cout << p << "\n";
  }

  return 0;
}