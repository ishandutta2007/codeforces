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

int a[300005];
vector<pii> elist[300005];
map<int, ll> w2[300005];
int fa[20][300005], faw[300005];
ll dp[300005], dp2[300005];
ll dwt[20][300005];

int dep[300005], clo, lef[300005], rig[300005];

void adopt(int fa, int ch, int w) { dp[fa] += max(0ll, -2 * w + dp[ch]); }
void disown(int fa, int ch, int w) { dp[fa] -= max(0ll, -2 * w + dp[ch]); }

void dfs1(int u, int f) {
  dep[u] = dep[f] + 1;
  lef[u] = clo++;
  fa[0][u] = f;
  dp[u] = a[u];
  for (auto [v, w] : elist[u])
    if (v != f) {
      faw[v] = w;
      dfs1(v, u);
      adopt(u, v, w);
    }
  rig[u] = clo;
  for (auto [v, w] : elist[u])
    if (v != f) {
      disown(u, v, w);
      dwt[0][v] = dp[u] - w;
      adopt(u, v, w);
    }
}
void dfs2(int u, int f) {
  dp2[u] = dp[u];
  for (auto [v, w] : elist[u])
    w2[u][v] = max(0ll, -2 * w + dp[v]);
  for (auto [v, w] : elist[u])
    if (v != f) {
      disown(u, v, w);
      adopt(v, u, w);
      dfs2(v, u);
      disown(v, u, w);
      adopt(u, v, w);
    }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    elist[u].pb({v, w});
    elist[v].pb({u, w});
  }
  rig[0] = 1e9;
  dfs1(1, 0);
  dfs2(1, 0);
  for (int k = 1; k < 20; k++)
    for (int i = 1; i <= n; i++) {
      fa[k][i] = fa[k - 1][fa[k - 1][i]];
      dwt[k][i] = dwt[k - 1][i] + dwt[k - 1][fa[k - 1][i]];
    }
  while (q--) {
    int qu, qv;
    cin >> qu >> qv;
    if (dep[qu] > dep[qv])
      swap(qu, qv);
    int ou = qu, ov = qv;
    ll ans = 0;
    for (int k = 19; k >= 0; k--) {
      int u2 = fa[k][qu];
      if (!(lef[u2] <= lef[qv] && lef[qv] < rig[u2])) {
        ans += dwt[k][qu];
        qu = u2;
      }
    }
    int lca = qu;
    if (!(lef[lca] <= lef[qv] && lef[qv] < rig[lca]))
      lca = fa[0][lca];
    for (int k = 19; k >= 0; k--) {
      int v2 = fa[k][qv];
      if (dep[lca] < dep[v2]) {
        ans += dwt[k][qv];
        qv = v2;
      }
    }
    ans += dp2[lca];
    if (qu != lca)
      ans -= faw[qu] + w2[lca][qu] - dp[ou];
    if (qv != lca)
      ans -= faw[qv] + w2[lca][qv] - dp[ov];
    cout << ans << '\n';
  }
}