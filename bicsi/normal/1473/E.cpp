#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    --a; --b;
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }

  vector<vector<long long>> dp(n, vector<long long>(4, 2e18));
  priority_queue<tuple<long long, int, int>> pq;
  auto push = [&](long long d, int i, int j) {
    if (dp[i][j] <= d) return;
    dp[i][j] = d;
    pq.emplace(-d, i, j);
  };
  push(0, 0, 0);
  while (pq.size()) {
    auto [d, i, j] = pq.top(); pq.pop(); d = -d;
    if (dp[i][j] != d) continue;
    for (auto [ni, c] : graph[i]) {
      for (int chmin : {0, 1}) {
        for (int chmax : {0, 1}) {
          long long nd = d + c * (1 - chmax + chmin);
          int nj = j;
          if (chmin) { if (j & 1) continue; nj |= 1; }
          if (chmax) { if (j & 2) continue; nj |= 2; }
          push(nd, ni, nj);
        }
      }
    }
  }
  for (int i = 1; i < n; ++i)
    cout << dp[i][3] << " ";
  cout << endl;
  return 0;
}