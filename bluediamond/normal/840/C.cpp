#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  if (a < 0) {
    return a + MOD;
  }
  return a;
}

int mul(int a, int b) {
  return a * (long long) b % MOD;
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
  return mul(a, pw(b, MOD - 2));
}

const int N = 300 + 7;
int n, fact[N], ifact[N], dp[N], dp2[N], num[N];
map<int, int> mp;

int c(int n, int k) {
  return mul(fact[n], mul(ifact[k], ifact[n - k]));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    for (int j = 2; j * j <= num[i]; j++) {
      int x = j * j;
      while (num[i] % x == 0) {
        num[i] /= x;
      }
    }
    mp[num[i]]++;
  }
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
  }
  ifact[N - 1] = dv(1, fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = mul(ifact[i + 1], i + 1);
  }
  dp[0] = 1;
  int total = 0, mlt = 1;
  for (auto &it : mp) {
    int x = it.second;
    mlt = mul(mlt, fact[x]);
    for (int j = 0; j <= total; j++) {
      for (int k = 1; k <= total + 1 && k <= x; k++) {
        for (int l = 0; l <= k && l <= j; l++) {
          int j_new = j - l + x - k, val = 1;
          val = mul(val, c(j, l));
          val = mul(val, c(total + 1 - j, k - l));
          val = mul(val, c(x - 1, k - 1));
          dp2[j_new] = add(dp2[j_new], mul(dp[j], val));
        }
      }
    }
    total += x;
    for (int j = 0; j <= total; j++) {
      dp[j] = dp2[j];
      dp2[j] = 0;
    }
  }
  cout << mul(dp[0], mlt) << "\n";
  return 0;
}