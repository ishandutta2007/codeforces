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

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n), parent_or_size(n, -1) {}

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) return x;
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
      std::remove_if(result.begin(), result.end(),
                     [&](const std::vector<int>& v) { return v.empty(); }),
      result.end());
    return result;
  }

private:
  int _n;
  // root node: -1 * component size
  // otherwise: parent
  std::vector<int> parent_or_size;
};

}  // namespace atcoder

using LL = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n, m;
    cin >> n >> m;
    atcoder::dsu dsu(n);
    vector<int> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];
    LL ans = 0;
    int j = -1;
    vector<pair<int, int>> y;
    for (int i = 0; i < n; ++i) {
      y.push_back({x[i], i});
    }
    sort(y.begin(), y.end());
    vector<bool> zl(n), zr(n);
    for (int i = 0; i < n; ++i) {
      int s = y[i].second;
      if (x[s] >= m) break;
      if (!zl[s]) {
        zl[s] = true;
        for (int j = s + 1; j < n; ++j) {
          if (zl[j] || x[j] % x[s] != 0) break;
          zl[j] = true;
          if (!dsu.same(s, j)) {
            dsu.merge(s, j);
            ans += x[s];
          }
        }
      }
      if (!zr[s]) {
        zr[s] = true;
        for (int j = s - 1; j >= 0; --j) {
          if (zr[j] || x[j] % x[s] != 0) break;
          zr[j] = true;
          if (!dsu.same(s, j)) {
            dsu.merge(s, j);
            ans += x[s];
          }
        }
      }
    }
    LL cnt = dsu.groups().size();
    ans += 1LL * (cnt - 1) * m;
    cout << ans << "\n";
  }  
  return 0;
}