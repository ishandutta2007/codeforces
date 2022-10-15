#include <bits/stdc++.h>

using namespace std;

const int N = 6000 + 7;
int n, m, e[N][2], pos[N], ans[N], sz;
bool vis[N];
vector<int> g[N];

int other(int edge, int v) {
  return e[edge][0] ^ e[edge][1] ^ v;
}

void reset() {
  sz = 0;
  for (int i = 1; i <= m; i++) {
    vis[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    pos[i] = 0;
  }
}

void dfs(int a) {
  while (pos[a] < (int) g[a].size()) {
    int id = g[a][pos[a]++];
    if (vis[id]) continue;
    vis[id] = 1;
    int b = other(id, a);
    dfs(b);
    ans[++sz] = id;
  }
}

void check(int v) {
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == v) {
      continue;
    }
    int sum = 0;
    for (auto &id : g[i]) {
      sum += (vis[id] == 0);
    }
    cnt += sum % 2;
  }
  if (cnt >= 2) {
    return;
  }
  dfs(v);
}

void print(int v, vector<int> del) {
  for (int i = sz; i >= 1; i--) {
    v = other(ans[i], v);
  }
  cout << 1 + sz + 1 + 2 * (int) del.size() << "\n";
  cout << v << " ";
  for (int i = 1; i <= sz; i++) {
    v = other(ans[i], v);
    cout << v << " ";
  }
  cout << "-1 ";
  for (auto &id : del) {
    cout << other(id, v) << " " << v << " ";
  }
  cout << "\n";
  exit(0);
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> e[i][j];
      g[e[i][j]].push_back(i);
    }
  }
  for (int pm = 1; pm <= n; pm++) {
    vector<int> odd;
    for (auto &id : g[pm]) {
      int j = other(id, pm);
      if ((int) g[j].size() & 1) {
        odd.push_back(id);
      }
    }
    reset();
    for (auto &id : odd) {
      vis[id] = 1;
    }
    check(pm);
    if (sz + (int) odd.size() == m) {
      print(pm, odd);
    }
    for (auto &who : odd) {
      reset();
      for (auto &id : odd) {
        if (id != who) {
          vis[id] = 1;
        }
      }
      check(pm);
      if (sz + (int) odd.size() - 1 == m) {
        vector<int> odd2;
        for (auto &id : odd) {
          if (id != who) {
            odd2.push_back(id);
          }
        }
        print(pm, odd2);
      }
    }
  }
  cout << "0\n";
}