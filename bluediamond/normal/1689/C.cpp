#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int n, sub[N];
vector<int> g[N];

void dfs(int a, int p = -1) {
  vector<int> kids;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) {
      continue;
    }
    dfs(b, a);
    sub[a] += sub[b];
    kids.push_back(b);
  }
  g[a] = kids;
}

int save(int a) {
  if (g[a].empty()) {
    return 0;
  }
  int size_a = (int) g[a].size();
  assert(size_a == 1 || size_a == 2);
  if (size_a == 1) {
    return sub[a] - 2;
  }
  assert(size_a == 2);
  int kid_1 = g[a][0], kid_2 = g[a][1];
  int save_1 = save(kid_1), save_2 = save(kid_2);
  return max(save_1 + sub[kid_2] - 1, save_2 + sub[kid_1] - 1);
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    dfs(1);
    int sol = save(1);
    cout << sol << "\n";
  }
}