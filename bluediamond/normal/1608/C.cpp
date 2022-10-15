#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
int n, m;
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

int x[2][N];
int ordd[N];
bool ok[N];

int itrr;

bool cmp(int i, int j) {
  return x[itrr][i] < x[itrr][j];
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> x[0][i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> x[1][i];
    }

    int guy;

    for (int s = 0; s < 2; s++) {
      itrr = s;
      for (int i = 1; i <= n; i++) {
        ordd[i] = i;
      }
      sort(ordd + 1, ordd + n + 1, cmp);
      for (int i = 1; i < n; i++) {
        int f = ordd[i], s = ordd[i + 1];
        g[f].push_back(s);
        ginv[s].push_back(f);
      }
      guy = ordd[n];
    }

    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    for (int i = 1; i <= n; i++) vis[i] = 0;
    reverse(ord.begin(), ord.end());
    for (auto &x : ord) if (!vis[x]) now.clear(), dfs2(x), ret.push_back(now);

    for (auto &v : ret) {
      bool has_guy = false;
      for (auto &x : v) {
        has_guy |= (x == guy);
      }
      if (has_guy) {
        for (auto &x : v) {
          ok[x] = 1;
        }
      }
    }

    for (int i = 1; i <= n; i++) {
      cout << ok[i];
    }
    cout << "\n";

    for (int i = 1; i <= n; i++) g[i].clear(), ginv[i].clear(), vis[i] = 0, ok[i] = 0;
    ret.clear();
    ord.clear();
    now.clear();
  }
}