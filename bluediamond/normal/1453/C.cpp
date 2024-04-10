#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2000 + 7;
int n;
int a[N][N];

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      string s;
      cin >> s;
      for (int j = 1; j <= n; j++) {
        a[i][j] = s[j - 1] - '0';
      }
    }
    for (int d = 0; d <= 9; d++) {
      int sol = 0, rmin = -1, cmin = -1, rmax = -1, cmax = -1;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (a[i][j] == d) {
            if (rmin == -1) rmin = i, rmax = i, cmin = j, cmax = j;
            else {
              rmax = i;
              cmin = min(cmin, j);
              cmax = max(cmax, j);
            }
          }
        }
      }
      if (rmin == -1) {
        cout << "0 ";
        continue;
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          if (a[i][j] == d) {
            sol = max(sol, max(n - i, i - 1) * max(j - cmin, cmax - j));
            sol = max(sol, max(n - j, j - 1) * max(i - rmin, rmax - i));
          }
        }
      }
      cout << sol << " ";
    }
    cout << "\n";
  }


}