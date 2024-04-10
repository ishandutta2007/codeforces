#include <algorithm>
#include <bitset>
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

class RMiQ {
public:
  RMiQ(int _n) {
    n = _n;
    logn = log2(n) + 1;
    x = vector<int>(n);
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

  int Query(int a, int b) {
    if (a > b) swap(a, b);
    int k = log2(b - a + 1);
    if (x[f[a][k]] < x[f[b + 1 - (1 << k)][k]]) {
      return x[f[a][k]];
    } else {
      return x[f[b + 1 - (1 << k)][k]];
    }
  }

  int n, logn;
  vector<int> x;
  vector<vector<int>> f;
};


class RMaQ {
public:
  RMaQ(int _n) {
    n = _n;
    logn = log2(n) + 1;
    x = vector<int>(n);
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

  int Query(int a, int b) {
    if (a > b) swap(a, b);
    int k = log2(b - a + 1);
    if (x[f[a][k]] > x[f[b + 1 - (1 << k)][k]]) {
      return x[f[a][k]];
    } else {
      return x[f[b + 1 - (1 << k)][k]];
    }
  }

  int n, logn;
  vector<int> x;
  vector<vector<int>> f;
};



const int MAXN = 300010;

vector<int> e[MAXN];
int d[MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      e[i].clear();
      d[i] = -1;
    }
    vector<int> x(n);
    RMaQ rmaxq(n);
    RMiQ rminq(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i];
      --x[i];
      rmaxq.x[i] = rminq.x[i] = x[i];
    }
    rmaxq.Build();
    rminq.Build();
    vector<pair<int, int>> p;
    for (int i = 0; i < n; ++i) {
      while (!p.empty() && p.back().first < x[i]) {
        p.pop_back();
      }
      if (p.empty()) {
        p.push_back({x[i], i});
        continue;
      }
      p.push_back({x[i], i});
      if (rminq.Query(p[0].second, i) == x[i]) {
        e[p[0].second].push_back(i);
        continue;
      }
      int L = 0, R = p.size() - 1;
      while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (rminq.Query(p[mid].second, i) == x[i]) {
          R = mid;
        } else {
          L = mid;
        }
      }
      if (R != p.size() - 1) e[p[R].second].push_back(i);
    }
    p.clear();
    for (int i = 0; i < n; ++i) {
      while (!p.empty() && p.back().first > x[i]) {
        p.pop_back();
      }
      if (p.empty()) {
        p.push_back({x[i], i});
        continue;
      }
      p.push_back({x[i], i});
      if (rmaxq.Query(p[0].second, i) == x[i]) {
        e[p[0].second].push_back(i);
        continue;
      }
      int L = 0, R = p.size() - 1;
      while (L + 1 < R) {
        int mid = (L + R) >> 1;
        if (rmaxq.Query(p[mid].second, i) == x[i]) {
          R = mid;
        } else {
          L = mid;
        }
      }
      if (R != p.size() - 1) e[p[R].second].push_back(i);
    }
    queue<int> Q;
    Q.push(0);
    d[0] = 0;
    while (!Q.empty()) {
      int a = Q.front();
      Q.pop();
      for (int b : e[a]) {
        if (d[b] != -1) continue;
        d[b] = d[a] + 1;
        Q.push(b);
      }
    }
    cout << d[n - 1] << "\n";
  }
  return 0;
}