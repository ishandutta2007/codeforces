#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using ll = long long;
using pii = pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int S[200005];
int ans[200005];
vector<pii> elist[200005];
bool vis[200005];

int dfs(int u) {
  vis[u] = 1;
  int sum = S[u];
  for (auto [v, x] : elist[u])
    if (!vis[v]) {
      int sv = dfs(v);
      sum += sv;
      ans[abs(x)] = ((x > 0) - (x < 0)) * sv;
    }
  return sum;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> S[i];
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    elist[u].pb({v, i});
    elist[v].pb({u, -i});
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i] && dfs(i)) {
      cout << "Impossible" << endl;
      return 0;
    }
  cout << "Possible" << endl;
  for (int i = 1; i <= m; i++)
    cout << ans[i] << '\n';
}