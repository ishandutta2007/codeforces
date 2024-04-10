#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int mod = 1000000007;
vector<int> what[200002];

vector<pair<int, int>> g[200002];

int sgn(int x) {
  return (x > 0) - (x < 0);
}

bool used[200002];

pair<int, int> merge(const pair<int, int> &a, const pair<int, int> &b) {
  return {(1LL * a.first * b.first + 1LL * a.second * b.second) % mod,
    (1LL * a.first * b.second + 1LL * a.second * b.first) % mod};
}

pair<int, int> to(int par, int from) {
  if (g[from][0].first != par) return g[from][0];
  // if (g[from].size() < 2) for (;;); //return g[from][0];
  return g[from][1];
}

void add(int &r, int a) {
  r += a;
  if (r >= mod) r -= mod;
}

int in[200002], arr[200002][3];

pair<int, int> go(int v) {
  if (g[v].size() == 1) {
    int dp[2][2] = {0};
    // cout << "F: " << arr[v][1] << endl;
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        dp[a || b][b]++;
      }
      if (arr[v][1] == 0) break;
    }
    used[v] = true;
    int par = -1000000;
    while (true) {
      // cout << v << endl;
      auto p = to(par, v);
      int ndp[2][2] = {0};
      for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
          for (int c = 0; c < 2; ++c) {
            if (g[p.first].size() == 1 && arr[p.first][1] == 0 && c == 1) continue;
            add(ndp[a ^ ((b ^ p.second) || c)][c], dp[a][b]);
          }
        }
      }
      memcpy(dp, ndp, sizeof(dp));
      par = v; v = p.first;
      used[v] = true;
      if (g[v].size() == 1) break;
    }
    // cout << (dp[0][0] + dp[0][1]) % mod << "  " << (dp[1][0] + dp[1][1]) % mod << endl;
    return {(dp[0][0] + dp[0][1]) % mod, (dp[1][0] + dp[1][1]) % mod};
  }

  // exit(-1);

  if (g[v][0].first == v) {
    used[v] = true;
    if (g[v][0].second == 0) return {1, 1};
    return {0, 2};
  }

  // return {0, 0};

  int dp[2][2][2] = {0};
  for (int a = 0; a < 2; ++a) {
    for (int b = 0; b < 2; ++b) {
      dp[a][a || b][b]++;
    }
  }
  used[v] = true;
  int par = -1000000;
  while (true) {
    auto p = to(par, v);
    // cout << v << "  " << p.first << endl;
    int ndp[2][2][2] = {0};
    for (int d = 0; d < 2; ++d) {
      for (int a = 0; a < 2; ++a) {
        for (int b = 0; b < 2; ++b) {
          for (int c = 0; c < 2; ++c) {
            if (used[to(v, p.first).first]) {
              c = d ^ to(v, p.first).second;
              add(ndp[d][a ^ ((b ^ p.second) || c)][c], dp[d][a][b]);
              break;
            } else {
              add(ndp[d][a ^ ((b ^ p.second) || c)][c], dp[d][a][b]);
            }
          }
        }
      }
    }
    memcpy(dp, ndp, sizeof(dp));
    // for (int a = 0; a < 2; ++a) {
    //   for (int b = 0; b < 2; ++b) {
    //     for (int c = 0; c < 2; ++c) {
    //       cout << a << "  " << b << " " << c << " " << dp[a][b][c] << endl;
    //     }
    //   }
    // }
    par = v; v = p.first;
    used[v] = true;
    if (used[to(par, v).first]) break;
  }
  int ret[2] = {0};
  for (int a = 0; a < 2; ++a)
    for (int b = 0; b < 2; ++b)
      for (int c = 0; c < 2; ++c)
        add(ret[b], dp[a][b][c]);
  // cout << ret[0] << " " << ret[1] << endl; 
  return {ret[0], ret[1]};
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  // memset(arr, -1, sizeof(arr));
  for (int i = 1; i <= n; ++i) {
    int k, a[2] = {0};
    scanf("%d", &k);
    for (int j = 0; j < k; ++j) {
      scanf("%d", &arr[i][j]);
      what[abs(arr[i][j])].push_back(arr[i][j] > 0 ? i : -i);
      in[abs(arr[i][j])]++;
    } 
  }

  for (int i = 1; i <= m; ++i) {
    if (what[i].size() == 2) {
      int a = abs(what[i][0]), b = abs(what[i][1]), c = sgn(what[i][0]) != sgn(what[i][1]);
      g[a].push_back({b, c});
      g[b].push_back({a, c});
      // cout << "E: " << a << "  " << b << " " << c << endl;
    }
  }

  pair<int, int> ans = {1, 0};

  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    if (g[i].size() == 1) {
      // cout << i << endl;
      ans = merge(ans, go(i));
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (used[i]) continue;
    if (g[i].size() == 2) {
      // cout << i << endl;
      ans = merge(ans, go(i));
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (g[i].size() == 0) {
      // cout << "Shit\n";
      if (arr[i][1] == 0) ans = merge(ans, {1, 1});
      else ans = merge(ans, {1, 3});
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (!in[i]) {
      // cout << "Shit\n";
      add(ans.second, ans.second);
    }
  }
  printf("%d\n", ans.second);

  return 0;
}