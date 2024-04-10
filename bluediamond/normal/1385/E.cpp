#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, m, t[N], x[N], y[N], tmm[N], cur;
bool vis[N], act[N];
vector<int> g[N];
bool bad;

void dfs(int a) {
  if (bad) {
    return;
  }
  vis[a] = act[a] = 1;
  for (auto &b : g[a]) {
    if (vis[b] == 0) {
      dfs(b);
      continue;
    }
    if (act[b]) {
      bad = 1;
    }
  }
  tmm[a] = ++cur;
  act[a] = 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = 0;
      act[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      cin >> t[i] >> x[i] >> y[i];
      if (t[i] == 1) {
        g[x[i]].push_back(y[i]);
      }
    }
    cur = 0;
    bad = 0;
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        dfs(i);
      }
    }
    if (bad) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i <= m; i++) {
      if (t[i] == 1) {
        cout << x[i] << " " << y[i] << "\n";
      } else {
        if (tmm[x[i]] < tmm[y[i]]) {
          swap(x[i], y[i]);
        }
        cout << x[i] << " " << y[i] << "\n";
      }
    }
  }
  return 0;
}