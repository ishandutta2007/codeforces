#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int M = 998244353;

int rep(int x) {
  x %= M;
  if (x < 0) x += M;
  return x;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = rep(r * a);
    a = rep(a * a), b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return rep(a * pw(b, M - 2));
}

struct T {
  int n;
  vector<int> force;
  vector<bool> vis;
  bool wrong;
  vector<vector<pair<int, int>>> g;
  T(int nn) {
    wrong = 0;
    n = nn;
    force.clear();
    vis.clear();
    g.clear();
    vis.resize(n, 0);
    force.resize(n, -1);
    g.resize(n);
  }
  void add(int x, int a) {
    assert(1 <= x && x <= n);
    x--;
    if (force[x] != -1 && force[x] != a) {
      wrong = 1;
    }
    force[x] = a;
  }
  void add(int x, int y, int a) {
    assert(1 <= x && x <= n);
    assert(1 <= y && y <= n);
    x--, y--;
    g[x].push_back({y, a});
    g[y].push_back({x, a});
  }
  int ret;
  void dfs(int a) {
    vis[a] = 1;
    for (auto &it : g[a]) {
      int b = it.first, c = it.second ^ force[a];
      if (force[b] != -1 && force[b] != c) {
        ret = 0;
      }
      force[b] = c;
      if (!vis[b]) {
        dfs(b);
      }
    }
  }
  int cnt() {
    if (wrong) return 0;
    ret = 1;
    for (int i = 0; i < n; i++) {
      if (!vis[i] && force[i] != -1) {
        dfs(i);
        if (ret == 0) return 0;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i] && force[i] == -1) {
        force[i] = 0;
        dfs(i);
        ret = rep(ret * 2);
        if (ret == 0) return 0;
      }
    }
    return ret;
  }
};

string s;
int n;
int ret;
bool match0 = 1;
int pre0;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s;
  n = (int) s.size();
  s = " " + s;
  for (int i = 1; i <= n; i++) if (s[i] == '1') match0 = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') break;
    pre0++;
  }
  for (int l1 = 1; l1 < n; l1++) {
    for (int l2 = n; l2 <= n; l2++) {
      int start1 = n - l1 + 1, start2 = n - l2 + 1;
      T f(l1 + l2);
      f.add(1, 1);
      f.add(l1 + 1, 1);
      for (int i = 1; i <= l1; i++) f.add(i, l1 - i + 1, 0);
      for (int i = 1; i <= l2; i++) f.add(l1 + i, l1 + l2 - i + 1, 0);
      bool wrong = 0;
      for (int i = 1; i <= n; i++) {
        bool is1 = (i >= start1);
        bool is2 = (i >= start2);
        if (s[i] != '?') {
          if (is1 && is2) {
            f.add(i - start1 + 1, l1 + i - start2 + 1, s[i] - '0');
          }
          if (is1 && !is2) {
            f.add(i - start1 + 1, s[i] - '0');
          }
          if (!is1 && is2) {
            f.add(l1 + i - start2 + 1, s[i] - '0');
          }
          if (!is1 && !is2) {
            if (s[i] == '1') wrong = 1;
          }
        }
      }
      if (wrong) continue;
      if (f.wrong) continue;
      /// 1 : n - l1 + 1, n
      /// 2 : n - l2 + 1, n
      int nemo = f.cnt();
      if (nemo) {
        ret = rep(ret + nemo);
      }
    }
  }
  cout << ret << "\n";
}