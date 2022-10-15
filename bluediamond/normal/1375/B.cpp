#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 7;
int n, m, a[N][N], b[N][N], dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

bool inside(int i, int j) {
  return 1 <= i && 1 <= j && i <= n && j <= m;
}

int vec(int i, int j) {
  int sol = 0;
  for (int k = 0; k < 4; k++) {
    sol += inside(i + dr[k], j + dc[k]);
  }
  return sol;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
        b[i][j] = vec(i, j);
        if (b[i][j] < a[i][j]) {
          ok = 0;
        }
      }
    }
    if (ok == 0) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << b[i][j] << " ";
      }
      cout << "\n";
    }
  }
}