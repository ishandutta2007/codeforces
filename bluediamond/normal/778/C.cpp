#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
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
int n, g[N][26], level[N], mx, leaf[N];
vector<int> on[N];

void dfs(int a) {
  leaf[a] = 1;
  on[level[a]].push_back(a);
  for (int j = 0; j < 26; j++) {
    if (g[a][j]) {
      leaf[a] = 0;
      int b = g[a][j];
      level[b] = 1 + level[a];
      dfs(b);
    }
  }
}

int query(vector<int> nodes) {
  if ((int) nodes.size() <= 1) {
    return 0;
  }
  int ret = (int) nodes.size() - 1;
  for (int j = 0; j < 26; j++) {
    vector<int> sc;
    for (auto &i : nodes) {
      if (g[i][j]) {
        sc.push_back(g[i][j]);
      }
    }
    ret += query(sc);
  }
  return ret;
}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y, z;
    string s;
    cin >> x >> y >> s;
    z = s[0] - 'a';
    g[x][z] = y;
  }
  level[1] = 1;
  dfs(1);
  int best = n + 1, who = -1;
  for (int lvl = 1; !on[lvl + 1].empty(); lvl++) {
    int ret = (int) on[lvl].size();
    for (auto &it : on[lvl]) {
      if (leaf[it]) ret--;
    }
    for (auto &i : on[lvl]) {
      vector<int> nodes;
      for (int j = 0; j < 26; j++) {
        if (g[i][j]) {
          nodes.push_back(g[i][j]);
        }
      }
      ret += query(nodes);
    }
    ret = n - ret;
    if (ret < best) {
      who = lvl;
      best = ret;
    }
  }
  cout << best << "\n" << who << "\n";
  return 0;
}