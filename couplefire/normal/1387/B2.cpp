#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
vector<int> adj[MAXN];

int ans[MAXN];
int identity[MAXN];
long long score = 0;

int dp[MAXN];
int par[MAXN];
int dead[MAXN];

void Calc(int u, int p) {
  dp[u] = 1;
  for (auto v : adj[u]) if (v != p) {
    Calc(v, u);
    dp[u] += dp[v];
    score += min(dp[v], N - dp[v]);
  }
}

void Dfs(int u, int p) {
  par[u] = p;
  dp[u] = 1;
  for (auto v : adj[u]) if (v != p && !dead[v]) {
    Dfs(v, u);
    dp[u] += dp[v];
  }
}

int Centroid(int u) {
  Dfs(u, 0);
  int sz = dp[u];
  while (true) {
    pair<int, int> mx = {-1, -1};
    for (auto v : adj[u]) if (v != par[u] && !dead[v]) {
      mx = max(mx, {dp[v], v});
    }
    if (mx.first * 2 <= sz) {
      return u;
    }
    u = mx.second;
  }
  return -1;
}

vector<int> nodes;

void GetNodes(int u, int p) {
  nodes.emplace_back(u);
  for (auto v : adj[u]) if (v != p && !dead[v]) {
    GetNodes(v, u);
  }
}

void Decomp(int u) {
  u = Centroid(u);
  Dfs(u, 0);
  dead[u] = 1;
  pair<int, int> mx = {1, u};
  nodes = {u};
  for (auto v : adj[u]) if (!dead[v]) {
    mx = max(mx, {dp[v], v});
    GetNodes(v, u);
  }
  vector<int> old_id(nodes.size());
  for (int i = 0; i < (int) nodes.size(); i++) {
    old_id[i] = identity[nodes[i]];
  }
  for (int i = 0; i < (int) nodes.size(); i++) {
    identity[nodes[i]] = old_id[(i - mx.first + (int) nodes.size()) % nodes.size()];
  }
  for (auto v : adj[u]) if (!dead[v]) {
    Decomp(v);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }
  for (int i = 1; i <= N; i++) {
    identity[i] = i;
  }
  Calc(1, 0);
  Decomp(1);
  for (int i = 1; i <= N; i++) {
    ans[identity[i]] = i;
  }
  cout << 2 * score << "\n";
  for (int i = 1; i <= N; i++) {
    assert(ans[i] != i);
    cout << ans[i] << " ";
  }
  cout << "\n";
  return 0;
}