#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;
const int N = 1000 + 7;
const ld PI = (ld) 2 * acos((ld) 0);
const int INF = (int) 1e18;
int n, x[N], y[N], r[N], par[N], dp[N][2][2];
vector<int> g[N];

void dfs(int a) {
 /** mn[a] = mx[a] = r[a] * r[a];
  for (auto &b : g[a]) {
    dfs(b);
    mn[a] = mn[a] + min(mn[b], -mx[b]);
    mx[a] = mx[a] + max(mx[b], -mn[b]);
  }
  cout << "\t\t\t\t\t" << a << " : " << mx[a] << "\n"; **/
  for (auto &b : g[a]) {
    dfs(b);
  }
  for (int l1 = 0; l1 < 2; l1++) {
    for (int l2 = 0; l2 < 2; l2++) {
      /// now I make l1, it doesn't matter because it's symmetric
      if (l1 & 1) {
        dp[a][l1][l2] = r[a] * r[a];
      } else {
        dp[a][l1][l2] = -r[a] * r[a];
      }
      for (auto &b : g[a]) {
        dp[a][l1][l2] += max(dp[b][l1 ^ 1][l2], dp[b][l2][l1 ^ 1]);
      }
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n;
  vector<vector<int>> v;
  v.push_back({0, 0, (int) 1e9});
  for (int i = 1; i <= n; i++) {
    v.push_back({0, 0, 0});
    for (auto &x : v[i]) {
      cin >> x;
    }
  }
  for (auto &vec : v) {
    reverse(vec.begin(), vec.end());
  }
  sort(v.rbegin(), v.rend());
  /// ordine descrescatoare
  for (int i = 0; i <= n; i++) {
    r[i] = v[i][0];
    x[i] = v[i][2];
    y[i] = v[i][1];
   /// cout << " : " << r[i] << " and " << x[i] << " " << y[i] << "\n";
  }
  for (int i = 1; i <= n; i++) {
    par[i] = -1;
    for (int j = i - 1; j >= 0; j--) {
      int dist_sq = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      ld dist = sqrt((ld) dist_sq);
      if (dist + (ld) r[i] <= (ld) r[j]) {
        par[i] = j;
        break;
      }
    }
    g[par[i]].push_back(i);
    ///cout << i << "  : " << par[i] << "\n";
  }
  /**for (int i = 1; i <= n; i++ ){
    cout << i << " : " << par[i] << ", " << r[i] << "\n";
  }**/
  dfs(0);
  int sol = 0;
  for (auto &i : g[0]) {
    sol += dp[i][1][1];
  }
  cout << fixed << setprecision(9) << (ld) sol * PI << "\n";
}