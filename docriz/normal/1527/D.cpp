#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> where(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = i - 1;
      where[a[i]] = i;
    }
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      x += 1;
      y += 1;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    vector<int> depth(n + 1);
    vector<int> sub_max(n + 1);
    vector<int> son(n + 1);
    vector<int> size(n + 1);
    vector<int> father(n + 1);
    function<void(int, int, int)> dfs1 = [&](int cur, int fa, int dep) -> void {
      depth[cur] = dep;
      sub_max[cur] = a[cur];
      size[cur] = 1;
      father[cur] = fa;
      for (auto nx: G[cur]) {
        if (nx == fa) {
          continue;
        }
        dfs1(nx, cur, dep + 1);
        sub_max[cur] = max(sub_max[cur], sub_max[nx]);
        size[cur] += size[nx];
        if (size[nx] > size[son[cur]]) {
          son[cur] = nx;
        }
      }
    };
    vector<int> top(n + 1);
    vector<int> dfn(n + 1);
    int dfs_clock = 0;
    function<void(int, int)> dfs2 = [&](int cur, int tp) -> void {
      top[cur] = tp;
      dfn[cur] = ++dfs_clock;
      if (son[cur]) {
        dfs2(son[cur], tp);
      }
      for (auto nx: G[cur]) {
        if (nx == father[cur] || nx == son[cur]) {
          continue;
        }
        dfs2(nx, nx);
      }
    };
    auto lca = [&](int x, int y) -> int {
      int t1 = top[x];
      int t2 = top[y];
      while (t1 != t2) {
        if (depth[t1] < depth[t2]) {
          swap(t1, t2);
          swap(x, y);
        }
        x = father[t1];
        t1 = top[x];
      }
      return depth[x] < depth[y] ? x : y;
    };
    auto inPath = [&](int x, int y, int z) -> bool {
      int g = lca(x, y);
      auto in = [&](int a, int b, int c) -> bool {
        // b is a's ancester
        return depth[c] >= depth[b] && lca(a, c) == c;
      };
      return in(x, g, z) || in(y, g, z);
    };
    dfs1(1, 0, 0);
    dfs2(1, 1);
    vector<ll> count(n + 1); // how many pairs that mex >= i
    count[0] = 1LL * n * (n - 1) / 2;
    count[1] = count[0];
    for (auto nx: G[1]) {
      count[1] -= 1LL * size[nx] * (size[nx] - 1) / 2;
    }
    int x = where[0];
    int y = where[1];
    int mex = 2;
    auto update = [&]() -> void {
      int g = lca(x, y);
      if (g != x && g != y) {
        count[mex] += 1LL * size[x] * size[y];
      } else {
        if (g == x) {
          for (auto t: G[x]) {
            if (lca(y, t) == t) {
              count[mex] += 1LL * size[y] * (n - size[t]);
              break;
            }
          }
        } else {
          assert(g == y);
          for (auto t: G[y]) {
            if (lca(x, t) == t) {
              count[mex] += 1LL * size[x] * (n - size[t]);
              break;
            }
          }
        }
      }
    };
    update();
    for (int i = 2; i <= n - 1; i++) {
      int p = where[i];
      if (inPath(x, y, p)) {
        mex += 1;
      } else {
        if (inPath(x, p, y)) {
          y = p;
          mex += 1;
        } else if (inPath(p, y, x)) {
          x = p;
          mex += 1;
        } else {
          break;
        }
      }
      update();
    }
    /*
    for (int i = 0; i <= n; i++) {
      cout << count[i] << " ";
    }
    cout << endl;
    */
    vector<ll> ans(n + 1);
    for (int i = 0; i <= n; i++) {
      if (i < n) {
        ans[i] = count[i] - count[i + 1];
      } else {
        ans[i] = count[i];
      }
    }
    for (int i = 0; i <= n; i++) {
      cout << ans[i] << (i == n ? "\n" : " ");
    }
  }
  return 0;
}