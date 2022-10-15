#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int) 1e5 + 7;
int n, v[N][2], dp[N][2], nw[2];
vector<int> g[N];

void dfs(int a, int p = -1) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
    kids.push_back(b);
  }
  for (int i = 0; i < 2; i++) {
    dp[a][i] = 0;
    for (auto &b : kids) {
      dp[a][i] += max(abs(v[a][i] - v[b][0]) + dp[b][0], abs(v[a][i] - v[b][1]) + dp[b][1]);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> v[i][0] >> v[i][1];
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    dfs(1);
    cout << max(dp[1][0], dp[1][1]) << "\n";
  }

  return 0;
}