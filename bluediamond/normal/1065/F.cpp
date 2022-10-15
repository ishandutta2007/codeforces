#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 7;
int n, k, dep[N], mn[N], intorc[N], perm[N];
vector<int> g[N];

void dfs1(int a) {
  if (g[a].empty()) {
    mn[a] = dep[a];
    return;
  }
  mn[a] = N;
  for (auto &b : g[a]) {
    dep[b] = 1 + dep[a];
    dfs1(b);
    mn[a] = min(mn[a], mn[b]);
  }
}

void dfs2(int a) {
  if (g[a].empty()) {
    intorc[a] = 1;
    return;
  }
  for (auto &b : g[a]) {
    dfs2(b);
    if (intorc[b] && dep[a] >= mn[b] - k) {
      intorc[a] += intorc[b];
    }
  }
}

void dfs3(int a) {
  perm[a] = intorc[a];
  if (g[a].empty()) {
    return;
  }
  for (auto &b : g[a]) {
    dfs3(b);
  }
  for (auto &b : g[a]) {
    int upd = intorc[a] - (intorc[b]) * (intorc[b] && dep[a] >= mn[b] - k) + perm[b];
    perm[a] = max(perm[a], upd);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  dfs1(1);
  dfs2(1);
  dfs3(1);
  cout << perm[1] << "\n";
}