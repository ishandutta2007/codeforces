#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
const int K = 18;
int n;
int m;
int q;
int lastk;
int dep[N];
int par[N];
int mn[K][N];
int who[N];
int first[N];
int last[N];
int lg[2 * N];
int top;
int ret[K][2 * N];
vector<int> g[N];
vector<int> rg[N];
set<pair<int, int>> s[N];

void dfs(int a) {
  ret[0][++top] = dep[a];
  first[a] = last[a] = top;
  for (auto &b : g[a]) {
    if (dep[b] == -1) {
      dep[b] = 1 + dep[a];
      par[b] = a;
      rg[a].push_back(b);
      dfs(b);
      s[b].insert({dep[a], a});
      ret[0][++top] = dep[a];
      last[a] = top;
      continue;
    }
    if (dep[b] < dep[a] - 1) {
      s[a].insert({dep[b], b});
    }
  }
}

void dfs2(int a) {
  if (g[a].empty()) {
    who[a] = a;
    mn[0][a] = s[who[a]].begin()->second;
    return;
  }
  int c;
  for (auto &b : g[a]) {
    dfs2(b);
    c = who[b];
  }
  for (auto &b : g[a]) {
    if ((int) s[who[b]].size() > (int) s[c].size()) {
      c = who[b];
    }
  }
  who[a] = c;
  for (auto &b : g[a]) {
    if (c != who[b]) {
      for (auto &it : s[who[b]]) {
        s[c].insert(it);
      }
    }
  }
  for (auto &it : s[a]) {
    s[c].insert(it);
  }
  mn[0][a] = s[c].begin()->second;
  while (!s[c].empty()) {
    auto it = s[c].end();
    it--;
    if (it->second == a) {
      s[c].erase(it);
    } else {
      break;
    }
  }
}

int lca(int a, int b) {
  if (first[a] > last[b]) {
    swap(a, b);
  }
  a = first[a];
  b = last[b];
  int k = lg[b - a + 1];
  return min(ret[k][a], ret[k][b - (1 << k) + 1]);
}

int solve(int c, int a) {
  if (dep[a] == c) {
    return 0;
  }
  int sol = 1;
  for (int k = lastk; k >= 0; k--) {
    if (dep[mn[k][a]] > c) {
      sol += (1 << k);
      a = mn[k][a];
    }
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    dep[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 0;
  dfs(1);
  for (int i = 2; i <= top; i++) {
    lg[i] = 1 + lg[i / 2];
  }
  for (int k = 1; (1 << k) <= top; k++) {
    for (int i = 1; i + (1 << k) - 1 <= top; i++) {
      ret[k][i] = min(ret[k - 1][i], ret[k - 1][i + (1 << (k - 1))]);
    }
  }
  for (int i = 1; i <= n; i++) {
    g[i] = rg[i];
  }
  dfs2(1);
  for (int k = 1; (1 << k) <= n; k++) {
    lastk = k;
    for (int i = 1; i <= n; i++) {
      mn[k][i] = mn[k - 1][mn[k - 1][i]];
    }
  }
  while (q--) {
    int a, b;
    cin >> a >> b;
    int c = lca(a, b);
    int sol = solve(c, a) + solve(c, b);
    cout << sol << "\n";
  }
}