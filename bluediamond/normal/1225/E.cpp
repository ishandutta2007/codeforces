#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % MOD;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, MOD - 2));
}

const int N = 2000 + 7;
int n, m, a[N][N], r[N][N], d[N][N], und[N][N], rgh[N][N], sum_r[N][N], sum_c[N][N];

int get_sum_r(int r, int c1, int c2) {
  return add(sum_r[r][c1], -sum_r[r][c2 + 1]);
}

int get_sum_c(int c, int r1, int r2) {
  return add(sum_c[c][r1], -sum_c[c][r2 + 1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == 'R');
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      rgh[i][j] = a[i][j] + rgh[i][j + 1];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = n; i >= 1; i--) {
      und[i][j] = a[i][j] + und[i + 1][j];
    }
  }
  if (n == 1 && m == 1) {
    cout << "1\n";
    return 0;
  }
  if (a[n][m]) {
    cout << "0\n";
    return 0;
  }
  r[n][m] = d[n][m] = 1;
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      if (i == n && j == m) {
        sum_r[i][j] = sum_c[j][i] = 1;
        continue;
      }
      int k1 = und[i + 1][j];
      int k2 = rgh[i][j + 1];
      int val1 = get_sum_c(j, i + 1, n - k1), val2 = get_sum_r(i, j + 1, m - k2);
      r[i][j] = val1;
      d[i][j] = val2;
      sum_r[i][j] = add(r[i][j], sum_r[i][j + 1]);
      sum_c[j][i] = add(d[i][j], sum_c[j][i + 1]);
    }
  }
  int ans = add(r[1][1], d[1][1]);
  cout << ans << "\n";
}