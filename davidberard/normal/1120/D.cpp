#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
ll w[N];
ll dp[N][2];
unordered_set<int> deny[N];
bool take[N];
bool not_take[N];
vector<int> adj[N];
int n;
int leaves = 0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

void dfs(int u, int p) {
  int ch = 0;
  ll zsum = 0;
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    ++ch;
    dfs(v, u);
    zsum += dp[v][0];
  }
  if (ch == 0) {
    ++leaves;
    take[u] = 1;
    dp[u][0] = w[u];
    dp[u][1] = 0;
  //cerr << " DP[" << u << "][0] = " << dp[u][0] << " ; dp[" << u << "][1] = " << dp[u][1] << endl;
    return;
  }
  dp[u][1] = INFLL;
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    ll nv = zsum + dp[v][1] - dp[v][0];
    if (nv < dp[u][1]) {
      deny[u].clear();
    }
    if (nv <= dp[u][1]) {
      deny[u].insert(v);
      dp[u][1] = nv;
    }
  }
  dp[u][0] = zsum;
  if (dp[u][1] + w[u] <= zsum) {
    take[u] = 1;
    dp[u][0] = dp[u][1] + w[u];
  }
  if (dp[u][1] + w[u] >= zsum) {
    not_take[u] = 1;
    dp[u][0] = zsum;
  }
}

vector<int> members;
void dfs2(int u, int p, bool has_zero, bool has_one) {
  if (take[u] && has_zero) {
    members.push_back(u);
  }
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    bool hz = (has_zero && not_take[u]) || !deny[u].count(v) || deny[u].size() > 1;
    bool ho = (has_one || (has_zero && take[u])) && deny[u].count(v);
    dfs2(v, u, hz, ho);
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> w[i];
  }
  for (int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0, 1, 0);
  sort(members.begin(), members.end());
  cout << dp[1][0] << " " << members.size() << "\n";
  for (auto& x : members) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}