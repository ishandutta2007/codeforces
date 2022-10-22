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

class SCC {
public:
  SCC(int _n) 
    : n(_n), x(_n), y(_n) {}

  void AddEdge(int a, int b) {
    x[a].push_back(b);
    y[b].push_back(a);
  }

  void FDfs(int a, int& cnt, vector<bool>& z) {
    z[a] = true;
    for (int i : x[a]) {
      if (!z[i]) FDfs(i, cnt, z);
    }
    list[--cnt] = a;
  }

  void RDfs(int a, vector<bool>& z, vector<int>& ans) {
    z[a] = true; 
    ans.push_back(a);
    for (int i : y[a]) {
      if (!z[i]) RDfs(i, z, ans);
    }
  }

  vector<vector<int>> GetScc() {
    list = vector<int>(n);
    vector<bool> z(n);
    int cnt = n;
    for (int i = 0; i < n; ++i) {
      if (!z[i]) FDfs(i, cnt, z);
    }
    z = vector<bool>(n);
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i) {
      if (!z[list[i]]) {
        vector<int> temp;
        RDfs(list[i], z, temp);
        ans.push_back(temp);
      }
    }
    return ans;
  }

  int n;
  // Forward edges.
  vector<vector<int>> x;
  // Backward edges.
  vector<vector<int>> y;
  vector<int> list;
};


using LL = long long;

const int MAXN = 400010;

vector<int> e[MAXN];
bool z[MAXN], in[MAXN];

void Dfs(int a) {
  z[a] = true;
  for (int b : e[a]) {
    if (z[b]) continue;
    in[b] = true;
    Dfs(b);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector<int> abc(m);
  for (int i = 0; i < m; ++i) cin >> abc[i];

  dsu dsu(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (x[i][j] == '.') continue;
      if (i + 1 < n && x[i + 1][j] == '#') dsu.merge(i * m + j, i * m + j + m);
      if (i > 0 && x[i - 1][j] == '#') dsu.merge(i * m + j, i * m + j - m);
      if (j + 1 < m && x[i][j + 1] == '#') dsu.merge(i * m + j, i * m + j + 1);
      if (j > 0 && x[i][j - 1] == '#') dsu.merge(i * m + j, i * m + j - 1);
    }
  }

  vector<vector<int>> dt(n, vector<int>(m));
  for (int j = 0; j < m; ++j) {
    if (x[n - 1][j] == '.') {
      dt[n - 1][j] = n;
    } else {
      dt[n - 1][j] = n - 1;
    }
  }
  for (int i = n - 2; i >= 0; --i) {
    for (int j = 0; j < m; ++j) {
      dt[i][j] = dt[i + 1][j];
      if (x[i][j] == '.') continue;
      dt[i][j] = i;
    }
  }

  SCC scc(n * m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (x[i][j] == '.') continue;
      int ld = dsu.leader(i * m + j);
      if (j > 0) {
        int ii = dt[i][j - 1], jj = j - 1;
        if (ii != n && !dsu.same(ii * m + jj, i * m + j)) {
          int ld2 = dsu.leader(ii * m + jj);
          in[ld2] = true;
          scc.AddEdge(ld, ld2);
          e[ld].push_back(ld2);
        }
      }
      if (j + 1 < m) {
        int ii = dt[i][j + 1], jj = j + 1;
        if (ii != n && !dsu.same(ii * m + jj, i * m + j)) {
          int ld2 = dsu.leader(ii * m + jj);
          in[ld2] = true;
          scc.AddEdge(ld, ld2);
          e[ld].push_back(ld2);
        }
      }
      if (i + 1 < n) {
        int ii = dt[i + 1][j], jj = j;
        if (ii != n && !dsu.same(ii * m + jj, i * m + j)) {
          int ld2 = dsu.leader(ii * m + jj);
          in[ld2] = true;
          scc.AddEdge(ld, ld2);
          e[ld].push_back(ld2);
        }
      }
    }
  }
  int ans = 0;
  vector<vector<int>> all = scc.GetScc();
  for (int i = 0; i < all.size(); ++i) {
    if (z[all[i][0]]) continue;
    if (dsu.leader(all[i][0]) != all[i][0]) continue;
    if (x[all[i][0] / m][all[i][0] % m] == '.') continue;
    ++ans;
    for (int j : all[i]) Dfs(j);
  }
  cout << ans << endl;
  return 0;
}