#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      G[x].push_back(y);
      G[y].push_back(x);
    }
    vector<int> ans(n + 1); 
    vector<int> dp(n + 1);
    const int MOD = 998244353;
    function<void(int, int)> dfs = [&](int cur, int fa) -> void {
      dp[cur] = 1;
      for (auto nx: G[cur]) {
        if (nx == fa) {
          continue;
        }
        dfs(nx, cur);
        dp[cur] = 2LL * dp[cur] * dp[nx] % MOD;
      }
    };
    dfs(1, 0);
    for (int k = 2; k <= n - 1; k++) {
      if ((n - 1) % k != 0) {
        continue;
      }
      function<bool()> check = [&]() -> bool {
        vector<int> f(n + 1);
        bool bad = false;
        function<void(int, int)> dfs = [&](int cur, int fa) -> void {
          if (bad) {
            return;
          }
          int a = 0;
          for (auto nx: G[cur]) {
            if (nx == fa) {
              continue;
            }
            dfs(nx, cur);
            a += 1 - f[nx];
          }
          if (a % k == 0) {
            f[cur] = 0;
          } else if ((a + 1) % k == 0) {
            f[cur] = 1;
          } else {
            bad = true;
          }
        };
        dfs(1, 0);
        return f[1] == 0 && !bad;
      };
      if (check()) {
        ans[k] += 1;
      }
    }
    for (int k = n; k >= 2; k--) {  
      for (int x = k + k; x <= n; x += k) {
        ans[k] -= ans[x];
        assert(ans[k] >= 0);
      }
      ans[1] -= ans[k];
    }
    ans[1] += dp[1];
    if (ans[1] < 0) {
      ans[1] += MOD;
    }
    ans[1] %= MOD;
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << (i == n ? "\n" : " ");
    }
  }
  return 0;
}