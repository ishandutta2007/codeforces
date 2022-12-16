#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;

ll dp[N][2];
int n;
int l[N], r[N];
vector<int> adj[N];

void dfs(int u, int p) {
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  dp[u][0] = 0;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dp[u][0] += max(abs(l[u] - l[v]) + dp[v][0], abs(l[u] - r[v]) + dp[v][1]);
    dp[u][1] += max(abs(r[u] - l[v]) + dp[v][0], abs(r[u] - r[v]) + dp[v][1]);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    cin >> n;
    for (int i=1; i<=n; ++i) {
      adj[i].clear();
      dp[i][0] = dp[i][1] = 0;
      cin >> l[i] >> r[i];
    }
    for (int i=1; i<=n-1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << max(dp[1][0], dp[1][1]) << "\n";
  }
  return 0;
}