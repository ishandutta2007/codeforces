#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
int fac[200005], ifac[200005], inv[200005];
int dp[5005];

int main() {
  int a, b, n;
  cin >> a >> b >> n;
  fac[0] = ifac[0] = inv[0] = fac[1] = ifac[1] = inv[1] = 1;
  for (int i = 2; i <= a + b + 2; i++) {
    inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
    fac[i] = 1ll * i * fac[i - 1] % MOD;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % MOD;
  }
  vector<pair<int, int>> r(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> r[i].first >> r[i].second;
    r[i].first--, r[i].second--;
  }
  r[n] = {a - 1, b - 1};
  n++;
  sort(r.begin(), r.end());
  auto c = [&](int n, int k) {
    return 1ll * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
  };
  for (int i = 0; i < n; i++) {
    dp[i] = c(r[i].first + r[i].second, r[i].first);
    for (int j = 0; j < i; j++)
      if (r[j].second <= r[i].second)
        dp[i] =
            (dp[i] + 1ll * (MOD - dp[j]) *
                         c(r[i].first - r[j].first + r[i].second - r[j].second,
                           r[i].first - r[j].first)) %
            MOD;
  }
  cout << dp[n - 1] << endl;
}