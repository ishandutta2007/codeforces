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

vector<int> elist[1000006], relist[1000006];
stack<int> post;
bool vis[1000006];
int SCC[1000006], sccs;

void karatsuba1(int u) {
  if (vis[u])
    return;
  vis[u] = 1;
  for (int v : elist[u])
    karatsuba1(v);
  post.push(u);
}

void karatsuba2(int u, int x) {
  if (SCC[u])
    return;
  SCC[u] = x;
  for (int v : relist[u])
    karatsuba2(v, x);
}

int u[1000006], v[1000006], w[1000006];

ll val[1000006];
ll dp[1000006];
vector<pii> dag[1000006];

ll dfs(int u) {
  if (dp[u] != -1)
    return dp[u];
  dp[u] = val[u];
  for (auto [v, w] : dag[u])
    dp[u] = max(dp[u], val[u] + dfs(v) + w);
  return dp[u];
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> w[i];
    elist[u[i]].push_back(v[i]);
    relist[v[i]].push_back(u[i]);
  }
  for (int i = 1; i <= n; i++)
    karatsuba1(i);
  while (post.size()) {
    karatsuba2(post.top(), ++sccs);
    post.pop();
  }
  for (int i = 0; i < m; i++) {
    if (SCC[u[i]] == SCC[v[i]]) {
      int lo = 0, hi = w[i], ans = 0;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (w[i] > 1ll * mid * (mid + 1) / 2)
          ans = mid, lo = mid + 1;
        else
          hi = mid - 1;
      }
      val[SCC[u[i]]] +=
          1ll * w[i] * (ans + 1) - 1ll * ans * (ans + 1) * (ans + 2) / 6;
    } else
      dag[SCC[u[i]]].push_back({SCC[v[i]], w[i]});
  }
  memset(dp, -1, sizeof dp);
  int r;
  cin >> r;
  cout << dfs(SCC[r]) << endl;
}