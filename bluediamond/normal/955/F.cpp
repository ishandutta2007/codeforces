#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 3e5 + 7;
const int M = 20;
int n, dep[N], ret, dp[N][M], down[N];
vector<int> g[N];

void build(int a) {
  down[a] = 1;
  vector<int> kids;
  for (auto &b : g[a]) {
    if (dep[b]) continue;
    kids.push_back(b);
    dep[b] = 1 + dep[a];
    build(b);
    down[a] = max(down[a], 1 + down[b]);
  }
  g[a] = kids;
  for (int j = 0; j < M; j++) dp[a][j] = -1;
}

void dfs(int a) {
  dp[a][1] = n;
  for (auto &b : g[a]) dfs(b);
  for (int h = 2; h < M; h++) {
    vector<int> lol;
    for (auto &b : g[a]) {
      lol.push_back(dp[b][h - 1]);
    }
    sort(lol.rbegin(), lol.rend());
    for (int k = 1; k <= (int) g[a].size(); k++) {
      /// can it be equal to k?
      if (k <= lol[k - 1]) {
        dp[a][h] = k;
      }
    }
  }
}

void dfs2(int a) {
  for (auto &b : g[a]) {
    dfs2(b);
    for (int h = 1; h < M; h++) {
      dp[a][h] = max(dp[a][h], dp[b][h]);
    }
  }
}

signed realMain() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep[1] = 1;
  build(1);
  for (int i = 1; i <= n; i++) {
    ret += down[i];
  }
  dfs(1);
  dfs2(1);
  for (int i = 1; i <= n; i++) {
    int last = 1;
    for (int h = M - 1; h >= 1; h--) {
      if (dp[i][h] != -1) {
        ret += (dp[i][h] - last) * h;
       last = dp[i][h];
      }
    }
  }
  cout << ret << "\n";
  return 0;
}