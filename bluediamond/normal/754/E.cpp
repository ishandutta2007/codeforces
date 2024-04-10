#include <bits/stdc++.h>

using namespace std;

const int N = 400;
int n, m, a[N][N];
int r, c, b[N][N];
bool ok[N][N];
bitset<2 * N> where[N][26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      a[i][j] = s[j] - 'a';
    }
  }
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      b[i][j] = s[j] - 'a';
    }
  }
  int mx = 2 * max(c, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int p = j; p < mx; p += m) {
        where[i][a[i][j]][p] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    bitset<2 * N> good;
    good.reset();
    good = ~good;
    for (int x = 0; x < r; x++) {
      for (int y = 0; y < c; y++) {
        if (0 <= b[x][y] && b[x][y] < 26) {
          good &= (where[(i + x) % n][b[x][y]] >> y);
        }
      }
    }
    for (int j = 0; j < m; j++) {
      ok[i][j] = good[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ok[i][j];
    }
    cout << "\n";
  }
}