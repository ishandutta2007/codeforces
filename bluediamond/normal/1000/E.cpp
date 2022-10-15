#include <bits/stdc++.h>

using namespace std;

bool home = 1;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 3e5 + 7;
int n, m, dep[N], mn[N], ct[N], y;
bool vis[N];
vector<int> g[N];
vector<pair<int, int>> edg;
set<pair<int, int>> blo;
set<int> sg[N];

void dfs(int a) {
  mn[a] = dep[a];
  for (auto &b : g[a]) {
    if (dep[b] == -1) {
      dep[b] = 1 + dep[a];
      edg.push_back({a, b});
      dfs(b);
      mn[a] = min(mn[a], mn[b]);
      continue;
    }
    if (dep[b] < dep[a] - 1) {
      mn[a] = min(mn[a], dep[b]);
    }
  }
}

void go(int a) {
  vis[a] = 1;
  ct[a] = y;
  for (auto &b : g[a]) {
    if (blo.count({a, b})) continue;
    if (!vis[b]) go(b);
  }
}

int ret, dw[N];

void fd(int a) {
  dw[a] = 0;
  int m1 = 0, m2 = 0;
  for (auto &b : g[a]) {
    if (dw[b] != -1) continue;
    fd(b);
    int cur = dw[b] + 1;
    if (cur > m1) {
      m2 = m1;
      m1 = cur;
    } else {
      m2 = max(m2, cur);
    }
  }
  ret = max(ret, m1 + m2);
  dw[a] = m1;
}

signed realMain() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) dep[i] = -1;
  dep[1] = 0;
  dfs(1);
  for (auto &it : edg) {
    int a = it.first, b = it.second;
    if (dep[a] < mn[b]) {
      blo.insert({a, b});
      blo.insert({b, a});
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      y++;
      go(i);
    }
  }
  for (int i = 1; i <= n; i++) for (auto &j : g[i]) sg[ct[i]].insert(ct[j]);
  n = y;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    for (auto &j : sg[i]) g[i].push_back(j);
    dw[i] = -1;
  }
  fd(1);
  cout << ret << "\n";
  return 0;
}