#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

const int M = 998244353;

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

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
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

const int N = 500 + 7;
int n, fact[N], ifact[N];
string s[N];
int value[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int dp[N][N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) ifact[i] = mul(ifact[i + 1], i + 1);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == "+") {
      cin >> value[i];
    }
  }
  int sol = 0;
  for (int init = 1; init <= n; init++) {
    if (s[init] == "-") continue;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j] = 0;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i < init) {
        if (s[i] == "+") {
          if (value[i] <= value[init]) {
            /// skip
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
            /// take
            for (int j = 1; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j - 1]);
            }
          } else {
            /// skip
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
            /// take
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
          }
        } else {
          /// skip
          for (int j = 0; j <= n; j++) {
            addup(dp[i][j], dp[i - 1][j]);
          }
          /// take
          for (int j = 0; j <= n; j++) {
            addup(dp[i][j], dp[i - 1][j + 1]);
          }
          addup(dp[i][0], dp[i - 1][0]);
        }
        continue;
      }
      if (i == init) {
        assert(s[i] == "+");
        /// take
        for (int j = 0; j <= n; j++) {
          addup(dp[i][j], dp[i - 1][j]);
        }
        continue;
      }
      if (i > init) {
        if (s[i] == "+") {
          if (value[i] < value[init]) {
            /// skip
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
            /// take
            for (int j = 1; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j - 1]);
            }
          } else {
            /// skip
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
            /// take
            for (int j = 0; j <= n; j++) {
              addup(dp[i][j], dp[i - 1][j]);
            }
          }
        } else {
          /// skip
          for (int j = 0; j <= n; j++) {
            addup(dp[i][j], dp[i - 1][j]);
          }
          /// take
          for (int j = 0; j <= n; j++) {
            addup(dp[i][j], dp[i - 1][j + 1]);
          }
 ///         addup(dp[i][0], dp[i - 1][0]);
        }
        continue;
      }
      assert(0);

    }

    int total = 0;
    for (int j = 0; j <= n; j++) {
      addup(total, dp[n][j]);
    }
    sol = add(sol, mul(value[init], total));
  }
  cout << sol << "\n";


  return 0;
}