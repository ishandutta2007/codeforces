#include <bits/stdc++.h>

using namespace std;


const int N = 100000 + 7;
int n, m, comp[N], y, spre[N];
bool vis[N];
vector<int> g[N], ig[N], ord, rep[N];
set<int> sgn[N];

void dfs1(int a) {
  vis[a] = 1;
  for (auto &b : g[a]) {
    if (!vis[b]) {
      dfs1(b);
    }
  }
  ord.push_back(a);
}

void dfs2(int a) {
  rep[y].push_back(a);
  comp[a] = y;
  for (auto &b : ig[a]) {
    if (!comp[b]) {
      dfs2(b);
    }
  }
}

int este(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int r;
  cin >> r;
  return r;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    ig[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs1(i);
    }
  }
  reverse(ord.begin(), ord.end());
  for (auto &i : ord) {
    if (comp[i] == 0) {
      y++;
      dfs2(i);
    }
  }
  for (int i = 1; i <= n; i++) for (auto &j : g[i]) if (comp[i] != comp[j]) sgn[comp[i]].insert(comp[j]);
  n = y;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    for (auto &j : sgn[i]) {
      g[i].push_back(j);
      spre[j]++;
    }
  }
  vector<int> stk;
  for (int i = 1; i <= n; i++) {
    if (!spre[i]) stk.push_back(i);
  }
  int ret = stk[0];
  while ((int) stk.size() > 1) {
    int now = stk.back();
    while ((int) rep[now].size() > 0 && (int) rep[ret].size() > 0) {
      int x = rep[now].back(), y = rep[ret].back();
      if (este(x, y)) rep[ret].pop_back();
      else rep[now].pop_back();
    }
    if (rep[ret].empty()) {
      swap(stk.back(), stk[0]);
      swap(ret, now);
    }
    stk.pop_back();
    for (auto &j : g[now]) {
      spre[j]--;
      assert(spre[j] >= 0);
      if (!spre[j]) {
        stk.push_back(j);
      }
    }
  }
  cout << "! " << rep[ret].back() << endl;
  return 0;
}