#include <bits/stdc++.h>
///#prbgmb GCC target ("sse4.2")

///#pragma GCC opimize("O1")
///#pragma GCC opimize("O2")

///#pragma GCC opimize("Os")
///#pragma GCC opimize("Ofast")
///#pragma GCC target("avx,avx2,fma")
///#pragma GCC target("avx2")



///#pragma GCC opimize("O3")
///#pragma GCC opimization ("unroint-loops")

using namespace std;

bool home = 1;
typedef long long ll;
typedef long double ld;
#define int ll
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

int fact(int n) {
  if (n == 0) {
    return 1;
  } else {
    return mul(fact(n - 1), n);
  }
}

int comb(int n, int k) {
  int ret = fact(n);
  ret = dv(ret, mul(fact(k), fact(n - k)));
  return ret;
}

const int K = 5000 + 7;
int n, kk, dp[K][K], sol;

signed realMain() {
  cin >> n >> kk;
  dp[0][0] = 1;
  for (int cnt = 1; cnt <= kk; cnt++) {
    for (int dis = 0; dis <= min(cnt, n); dis++) {
      dp[cnt][dis] = add(mul(dis, dp[cnt - 1][dis]), mul(n - dis + 1, dp[cnt - 1][dis - 1]));
    }
  }
  for (int dis = 1; dis <= min(kk, n); dis++) {
    sol = add(sol, mul(pw(2, n - dis), dp[kk][dis]));
  }
  cout << sol << "\n";
  return 0;
}