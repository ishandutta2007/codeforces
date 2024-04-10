#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
long long dp[N][N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    while (n--) {
      int h, w;
      cin >> h >> w;
      dp[h][w] += h*w;
    }
    for (int i = 0; i < N; i++) {
      for (int j = 1; j < N; j++) {
        dp[i][j] += dp[i][j-1];
      }
    }
    for (int i = 0; i < N; i++) {
      for (int j = 1; j < N; j++) {
        dp[j][i] += dp[j-1][i];
      }
    }

    while (q--) {
      int h1, w1, h2, w2;
      cin >> h1 >> w1 >> h2 >> w2;
      cout << dp[h2-1][w2-1]-dp[h1][w2-1]-dp[h2-1][w1]+dp[h1][w1] << '\n';
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        dp[i][j] = 0;
      }
    }
  }
}