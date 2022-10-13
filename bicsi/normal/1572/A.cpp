#include <bits/stdc++.h>

using namespace std;

vector<int> dp;
vector<vector<int>> graph;
vector<int> color;

int DFS(int node) {
  if (color[node] == 2) return dp[node];
  if (color[node] == 1) return -2;

  color[node] = 1;
  dp[node] = 1;
  for (auto vec : graph[node]) {
    int dp_vec = DFS(vec);
    if (dp_vec == -2) { dp[node] = -2; break; }
    if (vec > node) dp[node] = max(dp[node], dp_vec + 1);
    else dp[node] = max(dp[node], dp_vec);
  }
  color[node] = 2;
  return dp[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    graph.assign(n, {});
    dp.assign(n, -1);
    color.assign(n, 0);
    for (int i = 0; i < n; ++i) {
      int k; cin >> k;
      while (k--) {
        int j; cin >> j;
        graph[i].push_back(j - 1);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int now = DFS(i);
      if (now == -2) {
        ans = -1; 
        break;
      }
      ans = max(ans, now);
    }
    cout << ans << '\n';
  }

  return 0;
}