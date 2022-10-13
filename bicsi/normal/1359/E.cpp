#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int kMod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k; cin >> n >> k;

  vector<int> fact(n + 1, 1), ifact(n + 1, 1);
  auto lgpow = [&](int b, int e) {
    int r = 1;
    while (e) {
      if (e % 2) r = 1LL * r * b % kMod;
      b = 1LL * b * b % kMod;
      e /= 2;
    }
    return r;
  };
  for (int i = 2; i <= n; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % kMod;
  }
  ifact[n] = lgpow(fact[n], kMod - 2);
  assert(1LL * ifact[n] * fact[n] % kMod == 1);
  for (int i = n - 1; i >= 1; --i) {
    ifact[i] = 1LL * ifact[i + 1] * (i + 1) % kMod;
    assert(1LL * ifact[i] * fact[i] % kMod == 1);
  }
  
  auto choose = [&](int n, int k) -> int {
    if (k < 0 || k > n) return 0;
    return 1LL * fact[n] * ifact[k] % kMod * ifact[n - k] % kMod;
  };

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt = n / i;
    ans = (ans + choose(cnt - 1, k - 1)) % kMod;
  }
  cout << ans << endl;

  return 0;
}