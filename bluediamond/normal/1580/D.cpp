#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 4000 + 7;
int n, m, v[N];
vector<pair<int, int>> g[N];

int build(int l, int r) {
  if (l > r) return 0;
  if (l == r) return l;
  int i = l;
  for (int j = l + 1; j <= r; j++) {
    if (v[j] < v[i]) {
      i = j;
    }
  }

  int x = build(l, i - 1);
  int y = build(i + 1, r);

  if (x) {
    g[i].push_back({x, v[x] - v[i]});
  }
  if (y) {
    g[i].push_back({y, v[y] - v[i]});
  }
  return i;
}

int dp[N][N], sub[N], aux[N];

void dfs(int a) {
  for (auto &it : g[a]) {
    int b = it.first, c = it.second;
    dfs(b);
    for (int i = 0; i <= min(m, sub[b]); i++) {
      dp[b][i] += c * i * (m - i);
    }

    for (int i = 0; i <= sub[a] + sub[b]; i++) {
      aux[i] = 0;
    }

    for (int i = 0; i <= sub[a]; i++) {
      for (int j = 0; j <= sub[b]; j++) {
        aux[i + j] = max(aux[i + j], dp[a][i] + dp[b][j]);
      }
    }

    for (int i = 0; i <= sub[a] + sub[b]; i++) {
      dp[a][i] = aux[i];
    }

    sub[a] += sub[b];
  }

  sub[a]++;
  for (int i = sub[a] - 1; i >= 1; i--) {
    dp[a][i + 1] = max(dp[a][i + 1], dp[a][i]);
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }

  int root = build(1, n);
  dfs(root);
  cout << dp[root][m] << "\n";

  return 0;
}