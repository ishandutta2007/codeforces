#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 5050;
const ll MOD = 998244353;

ll dp[N][N];
int hh[N];
ll plc[N];
vector<int> adj[N];
int n, k;

void dfs(int u, int p) 
{
  dp[u][0] = 1;
  hh[u] = 0;
  for (auto& v: adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u);
    memset(plc, 0, (sizeof(plc[0]))*min(k+1, max(hh[u]+1, hh[v]+2)));
    for (int i=hh[u]; i>=0; --i) {
      for (int j=hh[v]; j>=0; --j) {
        if (i+j+1 <= k) {
          plc[max(i, j+1)] += dp[u][i]*dp[v][j]%MOD;
        }
        plc[i] += dp[u][i]*dp[v][j]%MOD;
      }
    }
    for (int i=0; i<=min(k, max(hh[u], hh[v]+1)); ++i) {
      dp[u][i] = (plc[i])%MOD;
    }
    hh[u] = min(k, max(hh[u], hh[v]+1));
  }
}

int main() {
  cin >> n >> k;
  for (int i=1; i<n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  ll ans = 0;
  cerr << " HH " << hh[1] << endl;
  for (int i=0; i<=k; ++i) {
    ans += dp[1][i];
  }
  cout << ans %MOD << "\n";
  return 0;
}