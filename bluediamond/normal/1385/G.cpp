#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n, a[N], b[N], col[N];
vector<int> re[2];
bool bad;
vector<pair<int, int>> ps[N];
vector<pair<int, int>> g[N];

void dfs(int a) {
  re[col[a]].push_back(a);
  if (bad) {
    return;
  }
  for (auto &it : g[a]) {
    int b = it.first, c = it.second;
    if (col[b] == -1) {
      col[b] = col[a] ^ c;
      dfs(b);
      continue;
    }
    if (col[b] != col[a] ^ c) {
      bad = 1;
      return;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    ps[i].clear();
    g[i].clear();
    col[i] = -1;
  }
  for (int i = 1; i <= n; i++) {
    ps[a[i]].push_back({1, i});
    ps[b[i]].push_back({2, i});
  }
  for (int i = 1; i <= n; i++) {
    if ((int) ps[i].size() != 2) {
      cout << "-1\n";
      return;
    }
  }
  bad = 0;
  for (int i = 1; i <= n; i++) {
    pair<int, int> p1 = ps[i][0], p2 = ps[i][1];
    int r1 = p1.first, c1 = p1.second;
    int r2 = p2.first, c2 = p2.second;
    if (c1 == c2) {
      continue;
    }
    if (r1 == r2) {
      g[c1].push_back({c2, 1});
      g[c2].push_back({c1, 1});
    } else {
      g[c1].push_back({c2, 0});
      g[c2].push_back({c1, 0});
    }
  }
  vector<int> sol;
  for (int i = 1; i <= n; i++) {
    if (col[i] == -1) {
      col[i] = 0;
      re[0].clear();
      re[1].clear();
      dfs(i);
      if ((int) re[0].size() < (int) re[1].size()) {
        for (auto &j : re[0]) {
          sol.push_back(j);
        }
      } else {
        for (auto &j : re[1]) {
          sol.push_back(j);
        }
      }
    }
  }
  if (bad) {
    cout << "-1\n";
    return;
  }
  cout << (int) sol.size() << "\n";
  for (auto &i : sol) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      cin >> b[i];
    }
    solve();
  }
  return 0;
}