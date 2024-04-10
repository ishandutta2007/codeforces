#include <bits/stdc++.h>

using namespace std;

bool home = 1;

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

const int N = 14;
const int INF = (int) 1e9;
int n, m;
vector<int> g[N];

/**

Avem o comp biconexa cu nodurile X
atunci ca sa o extind aleg 2 noduri x, y din X si ma plimb pe un drum de la x la y care nu trece prin noduri din X

**/

int bt[1 << N];
bool okay[N][N][1 << N];
int lst[N][N][1 << N];
int dp[1 << N], rl[1 << N];

struct T {
  int x;
  int y;
  int m2;
};

T par[1 << N];
vector<int> ret[N];

void p(int mask) {
  for (int i = 0; i < n; i++) {
    if (mask & (1 << i)) {
      cout << i << "\n";
    }
  }
}

void print(vector<pair<int, int>> v) {
  for (auto &x : v) {
    cout << ": " << x.first << " " << x.second << "\n";
  }
}

signed realMain() {
  for (int i = 1; i < (1 << N); i++) {
    int j = (i & (-i));
    bt[i] = 1 + bt[i - j];
  }
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
   /// cout << x << " " << y << "\n";
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int start = 0; start < n; start++) for (int u = 0; u < n; u++) for (int mask = 0; mask < (1 << n); mask++) lst[start][u][mask] = -1;
  for (int start = 0; start < n; start++) {
    okay[start][start][1 << start] = 1;
    lst[start][start][1 << start] = start;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
        if (!okay[start][u][mask]) continue;
        for (auto &nou : g[u]) {
          if (mask & (1 << nou)) continue;
          lst[start][nou][mask + (1 << nou)] = u;
          okay[start][nou][mask + (1 << nou)] = 1;
        }
      }
    }
  }
  for (int start = 0; start < n; start++) {
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int u = 0; u < n; u++) {
        if (okay[start][u][mask]) {
          for (auto &j : g[u]) {
            if (j == start && mask != (1 << u) + (1 << start)) okay[start][start][mask] = 1, lst[start][start][mask] = u;
          }
        }
      }
    }
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    dp[mask] = INF;
  }
  for (int i = 0; i < n; i++) {
    dp[1 << i] = 0;
  }
  for (int mask = 0; mask < (1 << n); mask++) {
    vector<int> in, out;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        in.push_back(i);
      } else {
        out.push_back(i);
      }
    }
    if (dp[mask] == INF) continue;
    ///cout << mask << " : " << (int) in.size() << "\n";
    int cnt = (int) out.size();
    rl[0] = 0;
    for (int i = 0; i < cnt; i++) {
      rl[1 << i] = 1 << out[i];
    }
    for (auto &x : in) {
      for (auto &y : in) {
        for (int mic = 1; mic < (1 << cnt); mic++) {
          int uu = (mic & (-mic));
          rl[mic] = rl[uu] + rl[mic - uu];
          int m2 = rl[mic] | (1 << x) | (1 << y);
          if (okay[x][y][m2]) {
            int relax = dp[mask] + bt[m2] - (x != y);
            int nmask = mask | m2;
            if (relax < dp[nmask]) {
              dp[nmask] = relax;
              par[nmask] = {x, y, m2};
            }
          }
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << "\n";
  vector<pair<int, int>> ret;
  int mask = (1 << n) - 1;
  while (par[mask].m2) {
    auto it = par[mask];
    mask ^= it.m2;
    int m2 = it.m2;
    int x = it.x, y = it.y;
    mask |= (1 << x);
    mask |= (1 << y);
    if (x == y) {
      ret.push_back({lst[x][y][m2], y});
      y = lst[x][y][m2];
    }
    while (m2 > (1 << x)) {
      ret.push_back({lst[x][y][m2], y});
      int next_y = lst[x][y][m2];
      m2 -= (1 << y);
      y = next_y;
    }
  }
  assert((int) ret.size() == dp[(1 << n) - 1]);
  for (auto &x : ret) {
    cout << x.first + 1 << " " << x.second + 1 << "\n";
  }
  return 0;
}