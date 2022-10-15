#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  if (a < 0) {
    a += MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (long long) b % MOD;
}

int n, m;
string s;

const int N = 2000 + 5;

int dp[N][N]; /// dp[len][vf]

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  cin >> s;
  int mi = 0;
  int vf = 0;
  for (auto &it : s) {
    if (it == '(') {
      vf++;
    } else {
      vf--;
    }
    mi = min(mi, vf);
  }
  dp[0][0] = 1;
  for (int len = 1; len <= n - m; len++) {
    for (int cur = 0; cur <= len; cur++) {
      dp[len][cur] = add(dp[len][cur], dp[len - 1][cur + 1]); /// )
      if (cur > 0) {
        dp[len][cur] = add(dp[len][cur], dp[len - 1][cur - 1]); /// (
      }
  //    cout << len << " , " << cur << " : " << dp[len][cur] << "\n";
    }
  }
  int res = 0;
  for (int len = 0; len <= n - m; len++) {
    for (int cur = 0; cur <= len; cur++) {
      if (cur + mi >= 0) {
        int after = cur + vf;
        int ln = n - len - m;
        if (after < N) {
          int val = mul(dp[len][cur], dp[ln][after]);
          res = add(res, val);
        }
      }
    }
  }
  cout << res << "\n";
  return 0;
}