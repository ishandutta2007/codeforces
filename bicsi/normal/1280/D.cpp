#include <bits/stdc++.h>

using namespace std;
const long long kInf = 2e18;

int n, m;

vector<int> v;
vector<vector<int>> graph;
vector<vector<pair<int, long long>>> dp;
vector<pair<int, long long>> auxx;

int ans = 0;

int DFS(int node, int par) {
  int ret = 1;
  
  dp[node][0] = make_pair(0, 0);
  for (auto vec : graph[node]) {
    if (vec == par) continue;
    int now = DFS(vec, node);
    
    auxx.assign(n + 1, make_pair(0, -kInf));
    for (int i = 0; i <= ret; ++i) {
      for (int j = 0; j <= now; ++j) {
        auto a = dp[node][i], b = dp[vec][j];
        auxx[i + j] = max(auxx[i + j], make_pair(a.first + b.first, 
              a.second + b.second));
      }
    }
    dp[node] = auxx;
    ret += now;
  }
  for (int i = 0; i <= ret; ++i) {
    dp[node][i].second += v[node];
  }

  for (int i = ret - 1; i >= 0; --i) {
    bool wins = dp[node][i].second > 0;
    if (node == 0 && i + 1 == m) {
      ans = dp[node][i].first + wins;
    }
    dp[node][i + 1] = max(dp[node][i + 1], make_pair(
          dp[node][i].first + wins, 0LL));
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    cin >> n >> m;
    v.assign(n, 0);
    graph.assign(n, {});
    dp.resize(n);
    for (int i = 0; i < n; ++i) {
      dp[i].assign(n + 1, make_pair(0, -kInf));
    }

    for (int i = 0; i < n; ++i) {
      int x; cin >> x; v[i] -= x;
    }
    for (int i = 0; i < n; ++i) {
      int x; cin >> x; v[i] += x;
    }

    for (int i = 1; i < n; ++i) {
      int a, b; cin >> a >> b;
      --a; --b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    DFS(0, -1);
    /*
    for (int i = 0; i < n; ++i) cout << v[i] << " "; cout << endl;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        cout << "(" << dp[i][j].first << "," << dp[i][j].second << ") ";
      }
      cout << endl;
    }
    */
    cout << ans << '\n';
  }
  return 0;
}