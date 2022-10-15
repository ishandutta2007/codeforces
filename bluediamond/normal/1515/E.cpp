#include <bits/stdc++.h>
///#pragma GCC target("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")


/**
#pragma GCC opimize("O3")
#pragma GCC opimization ("unroll-loops")

**/
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

int mod;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    return a - mod;
  }
  if (a < 0) {
    return a + mod;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % mod;
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
  return mul(a, pw(b, mod - 2));
}


const int N = 400 + 7;
int n, dp[N][N], p2[N], fact[N], ifact[N];

int comb(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

signed realMain() {
  cin >> n >> mod;
  p2[0] = 1;
  for (int i = 1; i < N; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  for (int l = 1; l <= n; l++) {
    dp[l][l] = p2[l - 1];
    for (int last = 1; last <= n; last++) {
      int rem = l - last - 1;
      if (rem >= 1) {
        for (int cnt = 1; cnt <= rem; cnt++) {
          dp[l][cnt + last] = add(dp[l][cnt + last], mul(dp[rem][cnt], mul(p2[last - 1], comb(cnt + last, cnt))));
        }
      }
    }
  }
  int sol = 0;
  for (int i = 1; i <= n; i++) {
    sol = add(sol, dp[n][i]);
  }
  cout << sol << "\n";
  return 0;
}