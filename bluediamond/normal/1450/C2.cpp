#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 7;
int n, k, a[N][N];
int cnt_x[3], cnt_o[3];


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
        char c = s[j - 1];
        if (c == '.') a[i][j] = 0;
        if (c == 'X') a[i][j] = 1;
        if (c == 'O') a[i][j] = 2;
      }
    }
    int k = 0;
    cnt_x[0] = cnt_x[1] = cnt_x[2] = cnt_o[0] = cnt_o[1] = cnt_o[2] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        k += (a[i][j] > 0);
        cnt_x[(i + j) % 3] += (a[i][j] == 1);
        cnt_o[(i + j) % 3] += (a[i][j] == 2);
      }
    }
    k /= 3;
    bool done = 0;
    for (int rx = 0; rx < 3; rx++) {
      for (int ry = 0; ry < 3; ry++) {
        if (!done && rx != ry && cnt_o[rx] + cnt_x[ry] <= k) {
          done = 1;
          for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
              if ((i + j) % 3 == rx && a[i][j]) a[i][j] = 1;
              if ((i + j) % 3 == ry && a[i][j]) a[i][j] = 2;
            }
          }
          for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
              if (a[i][j] == 0) cout << ".";
              if (a[i][j] == 1) cout << "X";
              if (a[i][j] == 2) cout << "O";
            }
            cout << "\n";
          }
        }
      }
    }
  }
}