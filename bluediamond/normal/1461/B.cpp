#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int N = 500 + 7;
int n;
int m;
int s[N][N];

bool full(int r, int c1, int c2) {
  if (c1 < 0 || c2 > m || r > n) return 0;
  return s[r][c2] - s[r][c1 - 1] == c2 - c1 + 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      string str;
      cin >> str;
      for (int j = 1; j <= m; j++) {
        s[i][j] = s[i][j - 1] + (str[j - 1] == '*');
      }
    }
    int sol = 0;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= m; y++) {
        for (int i = 1; i <= N; i++) {
          bool ok = full(x + i - 1, y - i + 1, y + i - 1);
          if (ok == 0) break;
          sol++;
        }
      }
    }
    cout << sol << "\n";
  }

}