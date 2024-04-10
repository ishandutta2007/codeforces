#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 7;
int n, k, a[N][N];
int cnt[3];


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
    cnt[0] = cnt[1] = cnt[2];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cnt[(i + j) % 3] += (a[i][j] == 1);
      }
    }
    int r = 0;
    for (int i = 1; i < 3; i++) {
      if (cnt[i] < cnt[r]) {
        r = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] == 1 && (i + j) % 3 == r) {
          a[i][j] = 2;
        }
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