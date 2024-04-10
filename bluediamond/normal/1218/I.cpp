#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2000 + 7;
bool vis[2 * N];
int n, a[N][N], b[N], need[2 * N];
vector<pair<int, int>> g[2 * N];

void force(int i, int val) {
  if (need[i] == -1) {
    need[i] = val;
  }
  if (need[i] != val) {
    cout << "-1\n";
    exit(0);
  }
}

void force(int i, int j, int val) {
  g[i].push_back({j, val});
  g[j].push_back({i, val});
}

void dfs(int a) {
  vis[a] = 1;
  for (auto &it : g[a]) {
    int b = it.first, val = it.second ^ need[a];
    if (need[b] != -1 && need[b] != val) {
      cout << "-1\n";
      exit(0);
    }
    need[b] = val;
    if (!vis[b]) {
      dfs(b);
    }
  }
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    need[i] = -1;
  }
  for (int it = 1; it <= 2; it++) {
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= n; j++) {
        a[i][j] ^= (s[j - 1] - '0');
      }
    }
  }
  string s;
  cin >> s;
  for (int j = 1; j <= n; j++) {
    b[j] = s[j - 1] - '0';
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      /// if we apply on the i-th row then a[i][j] changes by b[j]
      /// if we apply on the j-th column then a[i][j] changes by b[i]
      /// if we do nothing => a[i][j] = 0
      /// if we do row i => a[i][j] ^ b[j] = 0
      /// if we do col j => a[i][j] ^ b[i] = 0
      /// if we do row i and col j => a[i][j] ^ b[j] ^ b[i] = 0
      if (b[i] == 0 && b[j] == 0) {
        if (a[i][j] != 0) {
          cout << "-1\n";
          return 0;
        }
        continue;
      }
      if (b[i] == 1 && b[j] == 0) {
        force(j, a[i][j]);
        continue;
      }
      if (b[i] == 0 && b[j] == 1) {
        force(i + n, a[i][j]);
        continue;
      }
      if (b[i] == 1 && b[j] == 1) {
        force(j, i + n, a[i][j]);
        continue;
      }
      assert(0);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (need[i] != -1 && !vis[i]) {
      dfs(i);
    }
  }
  for (int i = 1; i <= 2 * n; i++) {
    if (!vis[i]) {
      need[i] = 0;
      dfs(i);
    }
  }
  int cnt = 0;
  for (int i = 1; i <= 2 * n; i++) {
    cnt += need[i];
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    if (need[i]) cout << "col " << i - 1 << "\n";
    if (need[i + n]) cout << "row " << i - 1 << "\n";
  }
}