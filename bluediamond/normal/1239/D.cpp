#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n, m, tp[N];
bool vis[N];
vector<int> g[N], ginv[N], ord, now;
vector<vector<int>> ret;

void dfs(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) if (!vis[b]) dfs(b);
  ord.push_back(a);
}

void dfs2(int a) {
  now.push_back(a);
  vis[a] = 1;
  for (auto &b : ginv[a]) if (!vis[b]) dfs2(b);
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) g[i].clear(), ginv[i].clear(), tp[i] = 1, vis[i] = 0;
  ord.clear();
  ret.clear();
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    if (x == y) continue;
    g[x].push_back(y);
    ginv[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; i++) vis[i] = 0;
  reverse(ord.begin(), ord.end());
  for (auto &x : ord) if (!vis[x]) now.clear(), dfs2(x), ret.push_back(now);
  if ((int) ret.size() == 1) {
    cout << "No\n";
    return;
  }
  int id = (int) ret.size() - 1;
  for (auto &x : ret[id]) tp[x] = 2;
  int cnt1 = 0;
  for (int i = 1; i <= n; i++) cnt1 += (tp[i] == 1);
  cout << "Yes\n";
  cout << n - cnt1 << " " << cnt1 << "\n";
  for (int i = 1; i <= n; i++) if (tp[i] == 2) cout << i << " "; cout << "\n";
  for (int i = 1; i <= n; i++) if (tp[i] == 1) cout << i << " "; cout << "\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) solve();
}