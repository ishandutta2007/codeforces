#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 1;
const int K = 40 + 1;
const int INF = 200;
int n, m, all, a[N][N];
int dp[K][N][N];
bool done[K];

struct T {
  int r;
  int c;
};

vector<T> p[K];

bool inside(int r, int c) {
  return (1 <= r && 1 <= c && r <= n && c <= m);
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void build(int col) {
  for (int caux = 1; caux <= all; caux++) {
    done[caux] = 0;
  }

  queue<T> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == col) {
        dp[col][i][j] = 0;
        q.push({i, j});
      } else {
        dp[col][i][j] = INF;
      }
    }
  }
  while (!q.empty()) {
    T it = q.front();
    int r = it.r;
    int c = it.c;
    q.pop();
    if (!done[a[r][c]]) {
      done[a[r][c]] = 1;
      for (auto &u : p[a[r][c]]) {
        int r2 = u.r;
        int c2 = u.c;
        if (dp[col][r2][c2] == INF) {
          dp[col][r2][c2] = 1 + dp[col][r][c];
          q.push({r2, c2});
        }
      }
    }
    for (int o = 0; o < 4; o++) {
      int r2 = r + dr[o];
      int c2 = c + dc[o];
      if (dp[col][r2][c2] == INF) {
        dp[col][r2][c2] = 1 + dp[col][r][c];
        q.push({r2, c2});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> all;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      p[a[i][j]].push_back({i, j});
    }
  }
  for (int col = 1; col <= all; col++) {
    build(col);
  }

  int q;
  cin >> q;
  while (q--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int aprox = min(abs(r1 - r2) + abs(c1 - c2), dp[a[r1][c1]][r2][c2] + 1), sol = aprox;
    for (int r = max(1, r1 - aprox); r <= min(n, r1 + aprox); r++) {
      for (int c = max(1, c1 - aprox); c <= min(m, c1 + aprox); c++) {
        sol = min(sol, abs(r1 - r) + abs(c1 - c) + dp[a[r][c]][r2][c2] + 1);
      }
    }
    cout << sol << "\n";
  }
}