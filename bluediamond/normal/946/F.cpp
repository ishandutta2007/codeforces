#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100 + 7;
const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

void addup(int &a, int x) {
  a = add(a, x);
}

int len, want;
string s;
int tot[N];
int dp[N][N][N][2][2];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> len >> want >> s;
  for (int x = 0; x <= 1; x++) {
    for (int i = 0; i < len; i++) {
      if (s[i] - '0' == x) {
        dp[x][i][i][1][1] = 1;
      }
    }
  }
  tot[0] = tot[1] = 2;
  for (int i = 2; i <= want; i++) {
    tot[i] = mul(tot[i - 1], tot[i - 2]);
    for (int l = 0; l < len; l++) {
      for (int r = l; r < len; r++) {
        for (int a = 0; a <= 1; a++) {
          for (int b = 0; b <= 1; b++) {
            int sol = 0;

            if (b) {
              addup(sol, dp[i - 1][l][r][a][1]);
            } else {
              addup(sol, mul(dp[i - 1][l][r][a][0], tot[i - 2]));
              addup(sol, mul(dp[i - 1][l][r][a][1], add(tot[i - 2], -1)));
            }

            if (a) {
              addup(sol, dp[i - 2][l][r][1][b]);
            } else {
              addup(sol, mul(dp[i - 2][l][r][0][b], tot[i - 1]));
              addup(sol, mul(dp[i - 2][l][r][1][b], add(tot[i - 1], -1)));
            }

            for (int k = l; k < r; k++) {
              int val = mul(dp[i - 1][l][k][a][1], dp[i - 2][k + 1][r][1][b]);
              addup(sol, val);
            }


            dp[i][l][r][a][b] = sol;
          }
        }
      }
    }
  }

  int sol = 0;
  for (int a = 0; a <= 1; a++) {
    for (int b = 0; b <= 1; b++) {
      addup(sol, dp[want][0][len - 1][a][b]);
    }
  }
  cout << sol << "\n";
  return 0;
}