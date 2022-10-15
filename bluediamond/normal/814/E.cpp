#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int x) {
  a = add(a, x);
}

const int N = 50 + 7;
int n, d[N];
int dp[N][N][N][N]; /// dp[node][b1][b2][a1][a2]
int dp2[N][N][N][N]; /// dp[node][b1][b2][a1][a2]

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> d[i];
  dp[d[1] == 2][d[1] == 3][d[2] == 2][d[2] == 3] = 1;

  for (int i = 3; i <= n; i++) {
    for (int b1 = 0; b1 <= n; b1++) {
      for (int b2 = 0; b2 <= n; b2++) {
        for (int a1 = 0; a1 <= n; a1++) {
          for (int a2 = 0; a2 <= n; a2++) {
            if (!dp[b1][b2][a1][a2]) continue;
            int init = dp[b1][b2][a1][a2];
            if (b1 == 0 && b2 == 0) {
              addup(dp[a1][a2][0][0], init);
              continue;
            }
            for (int lst = 1; lst <= 2; lst++) {
              int x;
              if (lst == 1) {
                if (b1 == 0) continue;
                x = mul(b1, init);
                b1--;
              } else {
                if (b2 == 0) continue;
                x = mul(b2, init);
                b1++;
                b2--;
              }
              if (d[i] == 2) {
                ///
                addup(dp2[b1][b2][a1 + 1][a2], x);
                /// 1
                if (a1 >= 1) addup(dp2[b1][b2][a1 - 1][a2], mul(a1, x));
                /// 2
                if (a2 >= 1) addup(dp2[b1][b2][a1 + 1][a2 - 1], mul(a2, x));
              } else {
                ///
                addup(dp2[b1][b2][a1][a2 + 1], x);


                /// 1
                if (a1 >= 1) {
                  addup(dp2[b1][b2][a1][a2], mul(a1, x));
                }
                /// 2
                if (a2 >= 1) addup(dp2[b1][b2][a1 + 2][a2 - 1], mul(a2, x));

                /// 1 1
                if (a1 >= 2) addup(dp2[b1][b2][a1 - 2][a2], mul(a1 * (a1 - 1) / 2, x));

                /// 1 2
                if (a1 >= 1 && a2 >= 1) addup(dp2[b1][b2][a1][a2 - 1], mul(a1 * a2, x));

                /// 2 2
                if (a2 >= 2) addup(dp2[b1][b2][a1 + 2][a2 - 2], mul(a2 * (a2 - 1) / 2, x));
              }
              if (lst == 1) b1++; else b1--, b2++;
            }
          }
        }
      }
    }

    for (int b1 = 0; b1 <= n; b1++) {
      for (int b2 = 0; b2 <= n; b2++) {
        for (int a1 = 0; a1 <= n; a1++) {
          for (int a2 = 0; a2 <= n; a2++) {
            dp[b1][b2][a1][a2] = dp2[b1][b2][a1][a2];
            dp2[b1][b2][a1][a2] = 0;
          }
        }
      }
    }
  }

  cout << dp[0][0][0][0] << "\n";
  return 0;
}