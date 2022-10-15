#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

const int N = 2000 + 7;
int n, za, zb, p, dp[N], lost[N][N], pp[N], ip[N], strong[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> za >> zb;
  p = dv(za, zb);

  pp[0] = ip[0] = 1;
  for (int i = 1; i < N; i++) {
    pp[i] = mul(pp[i - 1], p);
    ip[i] = mul(ip[i - 1], add(1, -p));
  }

  for (int sz = 0; sz <= n; sz++) {
    lost[sz][0] = 1;
    for (int i = 1; i <= sz; i++) {
      lost[sz][i] = add(mul(lost[sz - 1][i], ip[i]), mul(lost[sz - 1][i - 1], pp[sz - i]));
    }
  }

  strong[1] = 1;
  for (int i = 2; i <= n; i++) {
    strong[i] = 1;
    for (int j = 1; j < i; j++) {
      strong[i] = add(strong[i], -mul(strong[j], lost[i][j]));
    }
  }


  dp[0] = dp[1] = 0;
  for (int cnt = 2; cnt <= n; cnt++) {
    int sum = 0;
    for (int sz = 1; sz < cnt; sz++) {
      int val = add(sz * (sz - 1) / 2 + sz * (cnt - sz), add(dp[sz], dp[cnt - sz]));
      sum = add(sum, mul(strong[sz], mul(lost[cnt][sz], val)));
    }
    dp[cnt] = dv(add(sum, mul(strong[cnt], cnt * (cnt - 1) / 2)), add(1, -strong[cnt]));
  }
  cout << dp[n] << "\n";

  return 0;
}