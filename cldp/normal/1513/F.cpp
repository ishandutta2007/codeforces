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

const LL INF = 1000000000;

void Solve(vector<LL>& x, vector<LL>& y, LL& diff) {
  int n = x.size();
  map<LL, LL> rb;
  for (int i = 0; i < n; ++i) {
    if (x[i] >= y[i]) continue;
    rb[x[i]] = max(rb[x[i]], y[i]);
  }
  int r = 0;
  for (auto& [a, b] : rb) {
    if (r > b) {
      b = r;
      continue;
    }
    r = b;
  }
  for (int i = 0; i < n; ++i) {
    if (x[i] <= y[i]) continue;
    auto iter = rb.find(y[i]);
    if (iter == rb.end()) {
      iter = rb.lower_bound(y[i]);
      if (iter == rb.begin()) continue;
      --iter;
    } 
    if (iter->second <= y[i]) continue;
    if (x[i] > iter->second) {
      diff = max(diff, iter->second - y[i]);
    } else {
      diff = max(diff, x[i] - y[i]);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<LL> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 0; i < n; ++i) cin >> y[i];
  LL diff = 0;
  Solve(x, y, diff);
  Solve(y, x, diff);
  LL ans = 0;
  for (int i = 0; i < n; ++i) ans += abs(x[i] - y[i]);
  ans -= diff + diff;
  cout << ans << endl;
  return 0;
}