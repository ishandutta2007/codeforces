#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2000 + 7;
int n, m, v[N][N], a[N][N], b[N][N], c[N][N], d[N][N], up[N][N], down[N][N], lft[N][N], rgh[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      v[i][j] = s[j - 1] + 10000;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      lft[i][j] = up[i][j] = 1;
      if (v[i][j] == v[i - 1][j]) {
        up[i][j] += up[i - 1][j];
      }
      if (v[i][j] == v[i][j - 1]) {
        lft[i][j] += lft[i][j - 1];
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      a[i][j] = b[i][j] = c[i][j] = d[i][j] = 1;
      if (v[i][j] == v[i - 1][j] && v[i][j] == v[i][j - 1]) a[i][j] = 2;
      if (v[i][j] == v[i - 1][j] && v[i][j] == v[i][j + 1]) b[i][j] = 2;
      if (v[i][j] == v[i + 1][j] && v[i][j] == v[i][j - 1]) c[i][j] = 2;
      if (v[i][j] == v[i + 1][j] && v[i][j] == v[i][j + 1]) d[i][j] = 2;
      rgh[i][j] = down[i][j] = 1;
      if (v[i][j] == v[i + 1][j]) {
        down[i][j] += down[i + 1][j];
      }
      if (v[i][j] == v[i][j + 1]) {
        rgh[i][j] += rgh[i][j + 1];
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == v[i - 1][j - 1]) {
        a[i][j] = min(a[i - 1][j - 1] + 2, min(up[i][j], lft[i][j]));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      if (v[i][j] == v[i - 1][j + 1]) {
        b[i][j] = min(b[i - 1][j + 1] + 2, min(up[i][j], rgh[i][j]));
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      if (v[i][j] == v[i + 1][j - 1]) {
        c[i][j] = min(c[i + 1][j - 1] + 2, min(down[i][j], lft[i][j]));
      }
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (v[i][j] == v[i + 1][j + 1]) {
        d[i][j] = min(d[i + 1][j + 1] + 2, min(down[i][j], rgh[i][j]));
      }
    }
  }
  ll sol = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int cur = (int) 1e9;
      cur = min(cur, a[i][j]);
      cur = min(cur, b[i][j]);
      cur = min(cur, c[i][j]);
      cur = min(cur, d[i][j]);
      sol += cur;
    }
  }
  cout << sol << "\n";
  return 0;
}