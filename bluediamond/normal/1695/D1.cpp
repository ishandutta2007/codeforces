#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//#define int long long

const int N = 2000 + 7;
int n, dp[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  dp[a] = 0;
  bool hs = 0;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
    if (dp[b] == 0) {
      dp[a] += 1;
      hs = 1;
    } else {
      dp[a] += dp[b];
    }
  }
  dp[a] -= hs;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int Test;
  cin >> Test;
  for (int tc = 1; tc <= Test; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
      mx = max(mx, (int) g[i].size());
    }
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (mx <= 2) {
      cout << "1\n";
      continue;
    }
    assert(mx >= 3);
    int root = 0;
    while ((int) g[root].size() < 3) {
      root++;
    }
    dfs(root);
    cout << dp[root] << "\n";
  }

}