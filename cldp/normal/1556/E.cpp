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

class RMaxQ {
public:
  RMaxQ(int _n) {
    n = _n;
    logn = log2(n) + 1;
    x = vector<LL>(n);
    f = vector<vector<int>>(n, vector<int>(logn));
  }

  void Build() {
    for (int i = 0; i < n; ++i) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        if (x[f[i][j - 1]] > x[f[i + (1 << (j - 1))][j - 1]]) {
          f[i][j] = f[i][j - 1];
        } else {
          f[i][j] = f[i + (1 << (j - 1))][j - 1];
        }
      }
    }
  }

  LL Query(int a, int b) {
    if (a > b) swap(a, b);
    int k = log2(b - a + 1);
    if (x[f[a][k]] > x[f[b + 1 - (1 << k)][k]]) {
      return x[f[a][k]];
    } else {
      return x[f[b + 1 - (1 << k)][k]];
    }
  }

  int n, logn;
  vector<LL> x;
  vector<vector<int>> f;
};

class RMinQ {
public:
  RMinQ(int _n) {
    n = _n;
    logn = log2(n) + 1;
    x = vector<LL>(n);
    f = vector<vector<int>>(n, vector<int>(logn));
  }

  void Build() {
    for (int i = 0; i < n; ++i) f[i][0] = i;
    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        if (x[f[i][j - 1]] < x[f[i + (1 << (j - 1))][j - 1]]) {
          f[i][j] = f[i][j - 1];
        } else {
          f[i][j] = f[i + (1 << (j - 1))][j - 1];
        }
      }
    }
  }

  LL Query(int a, int b) {
    if (a > b) swap(a, b);
    int k = log2(b - a + 1);
    if (x[f[a][k]] < x[f[b + 1 - (1 << k)][k]]) {
      return x[f[a][k]];
    } else {
      return x[f[b + 1 - (1 << k)][k]];
    }
  }

  int n, logn;
  vector<LL> x;
  vector<vector<int>> f;
};

const int MAXN = 100010;

LL x[MAXN], sum[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<LL> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  RMaxQ rmaxq(n);
  RMinQ rminq(n);
  for (int i = 0; i < n; ++i) {
    x[i + 1] = a[i] - b[i];
    sum[i + 1] = sum[i] + x[i + 1];
    rmaxq.x[i] = sum[i + 1];
    rminq.x[i] = sum[i + 1];
  }
  rmaxq.Build();
  rminq.Build();
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (sum[b] - sum[a - 1] != 0) {
      cout << -1 << "\n";
      continue;
    }
    if (rmaxq.Query(a - 1, b - 1) - sum[a - 1] > 0) {
      cout << -1 << "\n";
      continue;
    }
    cout << -(rminq.Query(a - 1, b - 1) - sum[a - 1]) << "\n";
  }
  return 0;
}