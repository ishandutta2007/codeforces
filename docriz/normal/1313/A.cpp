#include <bits/stdc++.h>

using namespace std;

const int MAXN = 12;

int dp[MAXN][MAXN][MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(12);
  struct Info {
    int a, b, c;
  };
  vector<Info> kind;
  kind.push_back({0, 0, 0});
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= 1; j++) {
      for (int k = 0; k <= 1; k++) {
        if (i + j + k == 0) continue;
        kind.push_back({i, j, k});
      }
    }
  }
  assert((int)kind.size() == 8);
  for (int i = 1; i <= 7; i++) {
    for (int a = 0; a <= 10; a++) {
      for (int b = 0; b <= 10; b++) {
        for (int c = 0; c <= 10; c++) {
          if (a - kind[i].a >= 0 && b - kind[i].b >= 0 && c - kind[i].c >= 0) {
            dp[i][a][b][c] = max(dp[i][a][b][c], 
              1 + dp[i - 1][a - kind[i].a][b - kind[i].b][c - kind[i].c]);
          }
          dp[i][a][b][c] = max(dp[i][a][b][c], dp[i - 1][a][b][c]);
        }
      }      
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << dp[7][a][b][c] << "\n";
  }
  return 0;
}