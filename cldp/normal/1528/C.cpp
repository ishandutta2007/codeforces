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

class SegTree {
 public:
  SegTree(int _n): n(_n) {
    x = vector<int>(_n * 4, -1);
    y = vector<int>(_n * 4);
  }

  void PushDown(int t, int l, int r) {
    if (l == r) return;
    if (x[t] == -1) return;
    x[t + t] = x[t + t + 1] = x[t];
    y[t + t] = y[t + t + 1] = x[t];
    x[t] = -1;
  }

  void Insert(int t, int a, int l, int r, int p, int q) {
    PushDown(t, l, r);
    if (p <= l && r <= q) {
      x[t] = a;
      y[t] = a;
      return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid) Insert(t + t, a, l, mid, p, q);
    if (mid + 1 <= q) Insert(t + t + 1, a, mid + 1, r, p, q);
    y[t] = max(y[t + t], y[t + t + 1]);
  }

  int Query(int t, int l, int r, int p, int q) {
    PushDown(t, l, r);
    if (p <= l && r <= q) return y[t];
    int mid = (l + r) >> 1;
    int ans = 0;
    if (p <= mid) ans = max(ans, Query(t + t, l, mid, p, q));
    if (mid + 1 <= q) ans = max(ans, Query(t + t + 1, mid + 1, r, p, q));
    return ans;
  }

  int n;
  vector<int> x, y;
};


class EulerTree {
public:
  EulerTree(int _n): n(_n), 
    tree(_n + _n), 
    x(vector<vector<int>>(n + 1)),
    s(vector<int>(n + 1)),
    px(vector<vector<int>>(n + 1)) {}

  void AddEdge(int a, int b) {
    x[a].push_back(b);
    x[b].push_back(a);
  }

  void BuildDfs(int a, int fa) {
    dfsx.push_back(a);
    px[a].push_back(dfsx.size());
    s[a] = 1;
    for (int b : x[a]) {
      if (b == fa) continue;
      BuildDfs(b, a);
      s[a] += s[b];
      dfsx.push_back(a);
      px[a].push_back(dfsx.size());
    }
  }

  void Build() {
    BuildDfs(1, -1);
  }

  void Add(int a, int b) {
    tree.Insert(1, b, 1, n + n - 1, px[a].front(), px[a].back());
  }

  int QueryRange(int a) {
    return tree.Query(1, 1, n + n - 1, px[a].front(), px[a].back());
  }

  int QueryPoint(int a) {
    return tree.Query(1, 1, n + n - 1, px[a].front(), px[a].front());
  }

  int n;
  SegTree tree;
  // Edges.
  vector<vector<int>> x;
  // Size of each subtree.
  vector<int> s;
  // Euler tour.
  vector<int> dfsx;
  // Position of each x in the tour.
  vector<vector<int>> px;
};

const int MAXN = 300010;

int ans;
vector<int> x[MAXN];

void Dfs(int a, int now, EulerTree& tree) {
  ans = max(ans, now);
  for (int b : x[a]) {
    int tp = tree.QueryPoint(b);
    if (tp != 0) {
      tree.Add(tp, 0);
      tree.Add(b, b);
      Dfs(b, now, tree);
      tree.Add(b, 0);
      tree.Add(tp, tp);
    } else {
      int tr = tree.QueryRange(b);
      if (tr != 0) {
        Dfs(b, now, tree);
      } else {
        tree.Add(b, b);
        Dfs(b, now + 1, tree);
        tree.Add(b, 0);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int times;
  cin >> times;
  while (times--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) x[i].clear();
    for (int i = 2; i <= n; ++i) {
      int a;
      cin >> a;
      x[a].push_back(i);
    }
    EulerTree tree(n);
    for (int i = 2; i <= n; ++i) {
      int a;
      cin >> a;
      tree.AddEdge(i, a);
    }
    tree.Build();
    ans = 0;
    tree.Add(1, 1);
    Dfs(1, 1, tree);
    cout << ans << '\n';
  }
  return 0;
}