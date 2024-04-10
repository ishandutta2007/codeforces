#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
  cin.sync_with_stdio(false), cin.tie(nullptr);

  int tests;
  cin >> tests;

  while (tests--) {
    int n;
    cin >> n;

    vector<vector<int>> g(n);

    for (int i = 1; i < n; i++) {
      int x;
      cin >> x;
      --x;

      g[x].push_back(i);
      g[i].push_back(x);
    }

    vector<int> a(n), depth(n);
    
    for (int i = 1; i < n; i++) {
      cin >> a[i];
    }

    function<void(int, int)> dfs = [&](int u, int f) {
      for (int v : g[u]) {
        if (v != f) {
          depth[v] = depth[u] + 1;
          dfs(v, u);
        }
      }
    };

    dfs(0, 0);

    const int max_depth = *max_element(depth.begin(), depth.end());

    vector<vector<int>> group(max_depth + 1);

    for (int i = 0; i < n; i++) {
      group[depth[i]].push_back(i);
    }
    for (int i = 0; i < max_depth + 1; i++) {
      sort(group[i].begin(), group[i].end(), [&](int x, int y) {
        return a[x] < a[y];
      });
    }

    vector<int64_t> dp(n);

    for (int _ = max_depth; _ >= 0; _--) {
      const vector<int> &vec = group[_];

      vector<int64_t> tdp(vec.size());

      for (int i = 0; i < (int) vec.size(); i++) {
        const int u = vec[i];

        for (int v : g[u]) {
          if (depth[v] > depth[u]) {
            tdp[i] = max(tdp[i], dp[v]);
          }
        }
      }

      {
        const int u = vec[0];

        dp[u] = -(1ll << 60);

        for (int i = 0; i < (int) vec.size(); i++) {
          dp[u] = max(dp[u], tdp[i] + a[vec[i]] - a[u]);
        }

        dp[u] = max(dp[u], tdp[0] - a[u] + a[vec.back()]);
      }

      if ((int) vec.size() == 1) {
        continue;
      }

      int64_t best = tdp[0] - a[vec[0]];

      for (int i = 1; i < (int) vec.size(); i++) {
        const int u = vec[i];

        dp[u] = max(best + a[u], tdp[i] + a[u] - a[vec[0]]);
        best = max(best, tdp[i] - a[u]);
      }

      best = tdp[(int) vec.size() - 1] + a[vec.back()];

      for (int i = (int) vec.size() - 2; i >= 0; i--) {
        const int u = vec[i];

        dp[u] = max({ dp[u], best - a[u], tdp[i] - a[u] + a[vec.back()] });
        best = max(best, tdp[i] + a[u]);
      }
    }

    cout << dp[0] << "\n";
  }
}