#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 50 + 7;
int n[2];
int m[2];
int a[2][N][N];
int sol;

int f(int x, int y) {
  int sol = 0;
  for (int i = 0; i < n[0]; i++) {
    for (int j = 0; j < m[0]; j++) {
      if (0 <= i + x && i + x < n[1] && 0 <= j + y && j + y < m[1]) {
        sol += a[0][i][j] * a[1][i + x][j + y];
      }
    }
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int it = 0; it < 2; it++) {
    cin >> n[it] >> m[it];
    for (int i = 0; i < n[it]; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m[it]; j++) {
        a[it][i][j] = s[j] - '0';
      }
    }
  }
  for (int i = -50; i <= 50; i++) {
    for (int j = -50; j <= 50; j++) {
      sol = max(sol, f(i, j));
    }
  }
  for (int i = -50; i <= 50; i++) {
    for (int j = -50; j <= 50; j++) {
      if (sol == f(i, j)) {
        cout << i << " " << j << "\n";
        return 0;
      }
    }
  }
}