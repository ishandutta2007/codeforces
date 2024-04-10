#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 1001000;
const ll MOD = 1e9+7;

ll modpow(ll b, ll p) {
  ll ans = 1;
  for (; p; b=b*b%MOD, p/=2) {
    if (p&1) {
      ans = ans*b%MOD;
    }
  }
  return ans;
}

ll fac[N], ifac[N], tpow[N];
void setup() {
  fac[0] = ifac[0] = tpow[0] = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    tpow[i] = tpow[i-1]*2%MOD;
  }
  ifac[N-1] = modpow(fac[N-1], MOD-2);
  for (int i=N-2; i; --i) {
    ifac[i] = ifac[i+1]*(i+1)%MOD;
  }
}

ll choose(int n, int k) {
  assert(0 <= k && k <= n);
  return fac[n]*ifac[k]%MOD*ifac[n-k]%MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n;
  cin >> n;
  ll ans = 0;
  for (int i=n%2; i<=n; i+=2) {
    int buckets = i+1;
    int stars = n-i-buckets;
    if (stars >= 0) {
      ans += choose(buckets+stars-1, stars)*2*fac[n-i]%MOD;
    }
    if (i > 0) {
      int b = i;
      int s = n-i-b;
      if (s >= 0) {
        ans += 4*choose(b+s-1, s)*fac[n-i]%MOD;
      }
    }
  }
  cout << ans%MOD << "\n";
  return 0;
}