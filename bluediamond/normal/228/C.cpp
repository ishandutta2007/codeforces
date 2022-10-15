#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 500 + 7;
const int K = 10;
int n;
int m;
int a[N][N];
int sum[N][N];
bool b[K][N][N];

int get(int r1, int c1, int r2, int c2) {
  return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

bool black(int r, int c, int k) {
  int r2 = r + (1 << k) - 1;
  int c2 = c + (1 << k) - 1;
  return get(r, c, r2, c2) == (r2 - r + 1) * (c2 - c + 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int pre = 0;
    for (int j = 1; j <= m; j++) {
      a[i][j] = (s[j - 1] == '*');
      pre += a[i][j];
      sum[i][j] = sum[i - 1][j] + pre;
    }
  }
  int sol = 0;
  for (int mask = 0; mask < (1 << 4); mask++) {
    for (int k = 0; k < K; k++) {
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          b[k][i][j] = 0;
        }
      }
    }
    int x = !!(mask & (1 << 0));
    int y = !!(mask & (1 << 1));
    int z = !!(mask & (1 << 2));
    int t = !!(mask & (1 << 3));
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        b[1][i][j] = (a[i][j] == x && a[i][j + 1] == y && a[i + 1][j] == z && a[i + 1][j + 1] == t);
      }
    }
    for (int k = 2; k < K; k++) {
      for (int i = 1; i + (1 << k) - 1 <= n; i++) {
        for (int j = 1; j + (1 << k) - 1 <= m; j++) {
          bool ok = 1;
          if (x) ok &= black(i, j, k - 1); else ok &= b[k - 1][i][j];
          if (y) ok &= black(i, j + (1 << (k - 1)), k - 1); else ok &= b[k - 1][i][j + (1 << (k - 1))];
          if (z) ok &= black(i + (1 << (k - 1)), j, k - 1); else ok &= b[k - 1][i + (1 << (k - 1))][j];
          if (t) ok &= black(i + (1 << (k - 1)), j + (1 << (k - 1)), k - 1); else ok &= b[k - 1][i + (1 << (k - 1))][j + (1 << (k - 1))];
          b[k][i][j] = ok;
          sol += ok;
        }
      }
    }
  }
  cout << sol << "\n";
}