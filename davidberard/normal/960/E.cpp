#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const int N = 200100;
int n;
ll ans = 0;
ll x[N];
pair<ll, ll> dp[N][2];

vector<int> adj[N];

void dfs(int u, int p) {
  for (auto& v : adj[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  int evencount = 0, oddcount = 0;
  for (auto& v : adj[u]) {
    if (v == p) continue;
    evencount += dp[v][0].second;
    oddcount  += dp[v][1].second;
  }
  for (auto& v : adj[u]) {
    if (v == p) continue;
    ans += (2*dp[v][0].first + x[u]*dp[v][0].second)*(evencount - dp[v][0].second);
    ans += (2*dp[v][1].first - x[u]*dp[v][1].second)*(oddcount  - dp[v][1].second);

    dp[u][0].first += dp[v][1].first - dp[v][1].second*x[u];
    dp[u][0].second += dp[v][1].second;

    dp[u][1].first += dp[v][0].first + dp[v][0].second*x[u];
    dp[u][1].second += dp[v][0].second;
    ans %= MOD;
    /*
    dp[u][1].first %= MOD;
    dp[u][0].first %= MOD;
    */
  }

  ans += dp[u][1].first*2 + x[u];

  dp[u][1].first += x[u];
  dp[u][1].second += 1;

  //cerr << "  dp[" << u << "][0] = {" << dp[u][0].first << "," << dp[u][0].second << "}\n";
  //cerr << "  dp[" << u << "][1] = {" << dp[u][1].first << "," << dp[u][1].second << "}\n\n";
  
  ans %= MOD;
  dp[u][0].first %= MOD;
  dp[u][1].first %= MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> x[i];
  }
  for (int i=1; i<n; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1, 0);
  cout << (ans + MOD)%MOD << "\n";

  return 0;
}