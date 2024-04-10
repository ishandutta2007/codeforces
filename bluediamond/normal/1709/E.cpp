#include <bits/stdc++.h>


using namespace std;

const int N = (int) 2e5 + 7;
int n, v[N], pref[N], sol = 0, sub[N], mx[N];
vector<int> g[N];
set<int> s[N];

void build(int a, int p = -1) {
  pref[a] ^= v[a];
  sub[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) {
      kids.push_back(b);
      pref[b] ^= pref[a];
      build(b, a);
      sub[a] += sub[b];
      if (sub[b] > sub[mx[a]]) {
        mx[a] = b;
      }
    }
  }
  g[a] = kids;
}



void dfs(int a) {
  bool dest = 0;

  if (mx[a]) {
    int b = mx[a];
    dfs(b);
    if (s[b].count(v[a] ^ pref[a])) {
      dest = 1;
    }
    s[a] = move(s[b]);
  }

  s[a].insert(pref[a]);

  for (auto &b : g[a]) {
    if (b == mx[a]) continue;
    dfs(b);
    for (auto &y : s[b]) {
      if (s[a].count(y ^ v[a])) {
        dest = 1;
      }
    }
    for (auto &y : s[b]) {
      s[a].insert(y);
    }
  }
  sol += dest;
  if (dest) {
    s[a].clear();
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  /// in momentul in care e 0 ii distrug toata familia
  build(1);
  dfs(1);
  cout << sol << "\n";
  return 0;
}