#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define maxN 2234

int n, m;
int a[maxN][maxN];
char s[maxN];
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= m; j++)
      a[i][j] = s[j] - '0';
  }
  vector<vector<int>> answer;
  auto Doop = [&](int px, int py, int qx, int qy, int rx, int ry) {
    answer.push_back({px, py, qx, qy, rx, ry});
    a[px][py] ^= 1;
    a[qx][qy] ^= 1;
    a[rx][ry] ^= 1;
  };

  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m; j += 2) {
      if (j + 1 <= m) {
        if (a[i][j] == 0 && a[i][j + 1] == 0)
          continue;
        if (a[i][j] == 1 && a[i][j + 1] == 1) {
          Doop(i, j, i, j + 1, i + 1, j);
        } else if (a[i][j] == 1 && a[i][j + 1] == 0) {
          Doop(i, j, i + 1, j, i + 1, j + 1);
        } else if (a[i][j] == 0 && a[i][j + 1] == 1) {
          Doop(i, j + 1, i + 1, j, i + 1, j + 1);
        }
      } else {
        if (a[i][j] == 0)
          continue;
        Doop(i, j, i + 1, j - 1, i + 1, j);
      }
    }
  }

  for (int j = 1; j <= m - 1; j++) {
    if (a[n - 1][j] == 0 && a[n][j] == 0)
      continue;
    if (a[n - 1][j] == 1 && a[n][j] == 1) {
      Doop(n - 1, j, n, j, n - 1, j + 1);
    } else if (a[n - 1][j] == 1 && a[n][j] == 0) {
      Doop(n - 1, j, n - 1, j + 1, n, j + 1);
    } else if (a[n - 1][j] == 0 && a[n][j] == 1) {
      Doop(n, j, n - 1, j + 1, n, j + 1);
    }
  }
  if (a[n - 1][m] == 1 && a[n][m] == 1) {
    Doop(n - 1, m, n - 1, m - 1, n, m - 1);
    Doop(n, m, n - 1, m - 1, n, m - 1);
  } else if (a[n - 1][m] == 1 && a[n][m] == 0) {
    Doop(n - 1, m, n - 1, m - 1, n, m - 1);
    Doop(n - 1, m - 1, n - 1, m, n, m);
    Doop(n, m - 1, n - 1, m, n, m);
  } else if (a[n - 1][m] == 0 && a[n][m] == 1) {
    Doop(n, m, n - 1, m - 1, n, m - 1);
    Doop(n - 1, m - 1, n - 1, m, n, m);
    Doop(n, m - 1, n - 1, m, n, m);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      assert(a[i][j] == 0);
  printf("%d\n", (int)answer.size());
  for (auto op : answer) {
    for (auto pos : op)
      printf("%d ", pos);
    printf("\n");
  }
}

int main() {
  int tc;
  scanf("%d", &tc);
  for (int T = 0; T < tc; T++) {
    solve();
  }
}