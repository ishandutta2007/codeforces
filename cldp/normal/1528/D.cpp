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

const int MAXN = 610;
const LL INF = 1000000000000000000L;

int n, m;
vector<pair<int, int>> x[MAXN];
LL ans[MAXN][MAXN];

void Solve(int s) {
  vector<bool> z(n);
  vector<LL> d(n, INF);
  d[s] = 0;
  for (int tt = 1; tt <= n; ++tt) {
    LL dist = INF;
    int p = -1;
    for (int i = 0; i < n; ++i) {
      if (z[i]) continue;
      if (d[i] < dist) {
        dist = d[i];
        p = i;
      }
    }
    z[p] = true;
    ans[s][p] = d[p];
    if (tt == n) break;
    vector<LL> td(n, INF);
    for (auto [q, dd] : x[p]) {
      int to = (q + d[p]) % n;
      td[to] = min(td[to], d[p] + dd);
    }
    LL mintd = INF;
    for (int i = 0; i < n; ++i) {
      mintd = min(mintd, td[i]);
      if (!z[i]) d[i] = min(d[i], mintd);
      ++mintd;
    }
    for (int i = 0; i < n; ++i) {
      if (!z[i]) d[i] = min(d[i], mintd);
      ++mintd;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    x[a].push_back({b, c});
  }
  for (int i = 0; i < n; ++i) Solve(i);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}