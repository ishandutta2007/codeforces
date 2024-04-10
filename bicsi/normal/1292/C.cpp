#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  
  vector<vector<int>> graph(n);
  for (int i = 1; i < n; ++i) {
    int a, b; cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  vector<vector<int>> dist(n, vector<int>(n, -1));
  vector<vector<int>> parent(n, vector<int>(n, -1));
  vector<vector<pair<int, int>>> pairs(n);
  vector<vector<int>> order(n);
  for (int i = 0; i < n; ++i) {
    order[i].push_back(i);
    dist[i][i] = 0;
    
    for (int j = 0; j < n; ++j) {
      int node = order[i][j];
      for (auto vec : graph[node]) {
        if (dist[i][vec] == -1) {
          dist[i][vec] = dist[i][node] + 1;
          pairs[dist[i][vec]].emplace_back(i, vec);
          parent[vec][i] = node;
          order[i].push_back(vec);
        }
      }
    }
  }

  vector<vector<int>> sz(n, vector<int>(n, 0));
  for (int node = 0; node < n; ++node) {
    for (auto par : graph[node]) {
      for (int oth = 0; oth < n; ++oth) {
        if (dist[oth][node] < dist[oth][par])
          sz[node][par] += 1;
      }
    }
  }
  
  long long best = 0;
  vector<vector<long long>> dp(n, vector<long long>(n, 0));
  for (int dist = 1; dist < n; ++dist) {
    for (auto p : pairs[dist]) {
      int a, b; tie(a, b) = p;
      if (dist == 1) {
        dp[a][b] = 1LL * sz[a][b] * sz[b][a];
      } else {
        int pa = parent[a][b], pb = parent[b][a];
        dp[a][b] = max(dp[pa][b], dp[a][pb]) + 1LL * sz[a][pa] * sz[b][pb];
      }
      best = max(best, dp[a][b]);
    }
  }

  cout << best << endl;
  return 0;
}