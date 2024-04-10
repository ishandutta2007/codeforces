#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;

int f[2][100];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n + m - 1; i++) {
      f[0][i] = f[1][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int d = i + j - 1;
        int x;
        cin >> x;
        f[x][d]++;
      }
    }
    int sol = 0;
    for (int i = 1; i < n + m - i; i++) {
      int f0 = f[0][i] + f[0][n + m - i];
      int f1 = f[1][i] + f[1][n + m - i];
      sol += min(f0, f1);
    }
    cout << sol << "\n";
  }
  return 0;
}