#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int n, m;
vector<int> adj[N], rev[N];

int vis[N], bck[N], mrk[N];
char fin[N];

bool dfs(int u) {
  if (bck[u]) {
    return true;
  }
  if (vis[u]) {
    return false;
  }
  vis[u] = 1;
  bck[u] = 1;
  for (auto& v : adj[u]) {
    bool res = dfs(v);
    if (res) {
      return true;
    }
  }

  bck[u] = 0;
  return false;
}

int dp[N], rdp[N];

void min_seen(vector<int> dj[N], int dp[N]) {
  vector<int> in(N);
  for (int i=1; i<=n; ++i) {
    dp[i] = i;
    for (auto& v : dj[i]) {
      ++in[v];
    }
  }
  queue<int> q;
  for (int i=1; i<=n; ++i) {
    if (in[i] == 0) {
      dp[i] = i;
      q.push(i);
    }
  }

  while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto& v : dj[u]) {
      dp[v] = min(dp[v], dp[u]);
      if (--in[v] == 0) {
        q.push(v);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i=0; i<m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    rev[v].push_back(u);
  }

  bool has_cycle = 0;
  for (int i=1; i<=n; ++i) {
    if (!vis[i]) {
      has_cycle |= dfs(i);
    }
  }
  if (has_cycle) {
    cout << -1 << "\n";
    return 0;
  }

  min_seen(adj, dp);
  min_seen(rev, rdp);

  int amt = 0;
  for (int i=1; i<=n; ++i) {
    fin[i] = 'E';
    if (min(dp[i], rdp[i]) == i) {
      ++amt;
      fin[i] = 'A';
    }
  }

  cout << amt << "\n" << (fin+1) << "\n";

  return 0;
}