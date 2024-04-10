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
  return a * (ll) b % M;
}

const int N = 5000 + 7;
int n;
int a[N];
int p[N];
int dp[N][N];
int pre[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[1][i] = 1;
    pre[1][i] = i;
  }
  sort(a + 1, a + n + 1);
  int j = 0;
  for (int i = 1; i <= n; i++) {
    while (2 * a[j + 1] <= a[i]) {
      j++;
    }
    p[i] = j;
  }
  for (int cnt = 2; cnt <= n; cnt++) {
    for (int i = 1; i <= n; i++) {
      dp[cnt][i] = 0;
      int rem = p[i] - (cnt - 2);
      if (rem > 0) {
        dp[cnt][i] = mul(dp[cnt - 1][i], rem);
      }
      dp[cnt][i] = add(dp[cnt][i], pre[cnt - 1][p[i]]);
      pre[cnt][i] = add(pre[cnt][i - 1], dp[cnt][i]);
    }
  }
  cout << dp[n][n] << "\n";
}