#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const int N = 200 + 7;
const int K = 1000 + 7;

int n, k, a[N], dp[N][N][K];

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a + 1, a + n + 1);


  dp[0][0][0] = 1;

  for (int i = 0; i < n; i++) {
    int dif = a[i + 1] - a[i];
    for (int act = 0; act <= n; act++) {
      for (int sum = 0; sum <= k; sum++) {
        if (!dp[i][act][sum]) continue;
        int x = dp[i][act][sum];
        /// 4 cazuri:
        /// 1. e doar trecator
        /// 2. e minim
        /// 3. e maxim
        /// 4. e minim si maxim

        /// 1
        if (sum + act * dif <= k) addup(dp[i + 1][act][sum + act * dif], mul(x, act));

        /// 2
        if (sum + act * dif <= k) addup(dp[i + 1][act + 1][sum + act * dif], x);

        /// 3
        if (sum + act * dif <= k && act >= 1) addup(dp[i + 1][act - 1][sum + act * dif], mul(x, act));


        /// e minim si maxim

        if (sum + act * dif <= k) addup(dp[i + 1][act][sum + act * dif], x);
      }
    }
  }

  int sol = 0;

  for (int tot = 0; tot <= k; tot++) {
    sol = add(sol, dp[n][0][tot]);
  }
  cout << sol << "\n";

  return 0;
}