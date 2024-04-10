#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int kMod = 998244353;



int32_t main() {
  int n, k; cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }

  auto lgpow = [&](int b, int e) {
    int r = 1;
    while (e) {
      if (e % 2) r = r * b % kMod;
      b = b * b % kMod;
      e /= 2;
    }
    return r;
  };
  
  vector<int> fact(n + 1, 1), ifact(n + 1, 1);
  for (int i = 1; i <= n; ++i) {
    fact[i] = fact[i - 1] * i % kMod;
  }
  ifact[n] = lgpow(fact[n], kMod - 2);
  for (int i = n - 1; i >= 0; --i) {
    ifact[i] = ifact[i + 1] * (i + 1) % kMod;
    assert(ifact[i] * fact[i] % kMod == 1);
  }

  auto choose = [&](int n, int k) {
    if (k < 0 || k > n) return 0LL;
    return fact[n] * ifact[k] % kMod * ifact[n - k] % kMod;
  };

  int to_mul = 1;
  int unm = 0;

  for (int j = n - 1, i = 0; i < n; j = i++) {
    if (h[i] == h[j]) {
      to_mul = to_mul * k % kMod; 
    } else {
      unm += 1;
    }
  }

  int ans = 0;
  for (int i = 0; i <= unm / 2; ++i) {
    int now = choose(unm, i) * choose(unm - i, i) % kMod;
    now = now * lgpow(k - 2, unm - 2 * i) % kMod;
    ans += now;
  }

  ans = ans % kMod * to_mul % kMod;
  int all = lgpow(k, n);
  ans = (all + kMod - ans) % kMod;
  ans = ans * ((kMod + 1) / 2) % kMod;
  cout << ans << endl;

  return 0;
}