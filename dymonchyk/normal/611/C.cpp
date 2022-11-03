#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[505][505];

int s[505][505];

int get(int r1, int c1, int r2, int c2) {
  int ret = s[r2][c2];
  if (r1) ret -= s[r1 - 1][c2];
  if (c1) ret -= s[r2][c1 - 1];
  if (r1 && c1) ret += s[r1 - 1][c1 - 1];
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < n; ++i)
    gets(f[i]);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      s[i][j] += f[i][j] == '.' && f[i + 1][j] == '.';
      s[i][j] += f[i][j] == '.' && f[i][j + 1] == '.';

      if (i) s[i][j] += s[i - 1][j];
      if (j) s[i][j] += s[i][j - 1];
      if (i && j) s[i][j] -= s[i - 1][j - 1];
    }
  }

  int q;
  scanf("%d", &q);
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2); --r1; --c1; --r2; --c2;
    int ans = get(r1, c1, r2, c2);
    for (int r = r1; r <= r2; ++r) {
      if (f[r][c2] == '.' && f[r][c2 + 1] == '.') --ans;
    }
    for (int c = c1; c <= c2; ++c) {
      if (f[r2][c] == '.' && f[r2 + 1][c] == '.') --ans;
    }
    printf("%d\n", ans);
  }
  return 0;
}