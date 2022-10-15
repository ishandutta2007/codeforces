#include <bits/stdc++.h>
///#pragma GCC target ("sse4.2")

///#pragma GCC optimize("O1")
///#pragma GCC optimize("O2")

///#pragma GCC optimize("O3")
///#pragma GCC optimize("Os")
///#pragma GCC optimize("Ofast")
///#pragma GCC target("avx,avx2,fma")

///#pragma GCC target("avx2")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
///#define int ll
signed realMain();


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
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

void baga(int &a, int x) {
  a = add(a, x);
}

const int N = 500 + 7;
int n, can[N][N], dp[N][N][2];

signed realMain() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> can[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    baga(dp[i][(i + 1) % n][0], 1);
    baga(dp[i][(i + 1) % n][1], 1);
  }
  for (int l = 2; l <= n; l++) {
    for (int i = 0; i < n; i++) {
      int j = (i + l) % n;
      for (int pot = 0; pot <= 1; pot++) {
        for (int k = 1; k < l; k++) {
          int vrt = (i + k) % n;
          if (pot && can[i][vrt]) baga(dp[i][j][1], mul(dp[i][vrt][1], dp[vrt][j][1]));
          if (can[j][vrt]) baga(dp[i][j][pot], mul(dp[i][vrt][0], dp[vrt][j][1]));
        }
      }
    }
  }
  cout << dp[0][0][0] << "\n";
  return 0;
}