#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroll-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
signed realMain();

/**
bool eprim(int x) {
  if (x <= 1) {
    return 0;
  }
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      return 0;
    }
  }
  return 1;
}**/

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

void baga(int &a, int x) {
  a = add(a, x);
}

const int N = 50 + 7;
int n, want;
int dp[N][N][N][2];

signed realMain() {
  cin >> n >> want;
  dp[0][0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x == 0 || x == -1) { /// white
      for (int p = 0; p <= 1; p++) {
        for (int w = 0; w <= n; w++) {
          for (int b = 0; b <= n; b++) {
            if (!dp[i][w][b][p]) {
              continue;
            }
            /// will it be odd or even?
            /// I care about the number of active bits in x
            int x = b;
            if (x == 0) {
              /// It will always be odd
              int coef = (1LL << i) % M;
              baga(dp[i + 1][w + 1][b][p ^ 1], mul(coef, dp[i][w][b][p]));
            } else {
              assert(i);
              int half = (1LL << (i - 1)) % M;
              baga(dp[i + 1][w][b][p], mul(half, dp[i][w][b][p]));
              baga(dp[i + 1][w + 1][b][p ^ 1], mul(half, dp[i][w][b][p]));
            }
          }
        }
      }
    }

    if (x == 1 || x == -1) { /// black
      for (int p = 0; p <= 1; p++) {
        for (int w = 0; w <= n; w++) {
          for (int b = 0; b <= n; b++) {
            if (!dp[i][w][b][p]) {
              continue;
            }
            /// will it be odd or even?
            /// I care about the number of active bits in x
            int x = w;
            if (x == 0) {
              /// It will always be odd
              int coef = (1LL << i) % M;
              baga(dp[i + 1][w][b + 1][p ^ 1], mul(coef, dp[i][w][b][p]));
            } else {
              assert(i);
              int half = (1LL << (i - 1)) % M;
              baga(dp[i + 1][w][b][p], mul(half, dp[i][w][b][p]));
              baga(dp[i + 1][w][b + 1][p ^ 1], mul(half, dp[i][w][b][p]));
            }
          }
        }
      }
    }
  }
  int sol = 0;
  for (int w = 0; w <= n; w++) {
    for (int b = 0; b <= n; b++) {
      sol = add(sol, dp[n][w][b][want]);
    }
  }
  cout << sol << "\n";
  return 0;
}