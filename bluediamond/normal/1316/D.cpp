#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n, r[N][N], c[N][N], s[N][N];
bool vis[N][N];
int dr[] = {-1, 0, 1, 0, 0}, dc[] = {0, 1, 0, -1, 0};

bool ok(int i, int j) {
  return (1 <= i && 1 <= j && i <= n && j <= n);
}

void dfs(int i, int j) {
  for (int k = 0; k < 4; k++) {
    int in = i + dr[k];
    int jn = j + dc[k];
    if (ok(in, jn) && s[in][jn] == -1 && r[i][j] == r[in][jn] && c[i][j] == c[in][jn]) {
      s[in][jn] = (k + 2) % 4;
      dfs(in, jn);
    }
  }
}

void print(int x) {
  if (x == 4) cout << "X";
  if (x == 0) cout << "U";
  if (x == 1) cout << "R";
  if (x == 2) cout << "D";
  if (x == 3) cout << "L";
  if (x == -1) cout << "?";
}

bool is[N][N];

void colo(int i, int j, int pi, int pj, int dir) {
  vis[i][j] = 1;
  for (int k = 0; k < 4; k++) {
    int in = i + dr[k];
    int jn = j + dc[k];
    if (in == pi && jn == pj) continue;
    if (ok(in, jn) && is[in][jn]) {
      s[i][j] = k;
      if (!vis[in][jn]) {
        colo(in, jn, i, j, k);
      }
    }
  }
  if (s[i][j] == -1) {
    s[i][j] = (dir + 2) % 4;
  }
}

int rr[N][N], cc[N][N];
bool act[N][N];

void d(int i, int j) {
  act[i][j] = vis[i][j] = 1;
  int in = i + dr[s[i][j]];
  int jn = j + dc[s[i][j]];
  if (!ok(in, jn)) {
    cout << "INVALID\n";
    exit(0);
  }
  if (i == in && j == jn) {
    rr[i][j] = i;
    cc[i][j] = j;
    act[i][j] = 0;
    return;
  }
  if (act[in][jn]) {
    rr[i][j] = -1;
    cc[i][j] = -1;
  } else {
    if (vis[in][jn] == 0) {
      d(in, jn);
    }
    rr[i][j] = rr[in][jn];
    cc[i][j] = cc[in][jn];
  }
  act[i][j] = 0;
}

bool check() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] < 0 || s[i][j] > 4) {
        return 0;
      }
      vis[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (vis[i][j] == 0) {
        d(i, j);
      }
    }
  }
  bool ook = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ook &= (r[i][j] == rr[i][j] && c[i][j] == cc[i][j]);
    }
  }
  return ook;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> r[i][j] >> c[i][j];
      is[i][j] = (r[i][j] == -1 && c[i][j] == -1);
      s[i][j] = -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (r[i][j] == i && c[i][j] == j) {
        s[i][j] = 4;
        dfs(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (is[i][j] && !vis[i][j]) {
        colo(i, j, -1, -1, -1);
      }
    }
  }
  if (!check()) {
    cout << "INVALID\n";
    return 0;
  }
  cout << "VALID\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      print(s[i][j]);
    }
    cout << "\n";
  }
}