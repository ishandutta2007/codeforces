#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
ll fac[N], ifac[N], tpow[N];
const ll MOD = 1e9+7;
ll modpow(ll b, ll p, ll m) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%m) {
    if (p&1) {
      ans = ans*b%m;
    }
  }
  return ans;
}

void setup() {
  fac[0] = ifac[0] = tpow[0]  = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
    ifac[i] = modpow(fac[i], MOD-2, MOD);
    tpow[i] = tpow[i-1]*2%MOD;
  }
}

ll choose(int n, int k) {
  assert(0 <= k && k <= n);
  return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

ll f[N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int TT;
  cin >> TT;
  while (TT--) {
    int n, k;
    cin >> n >> k;
    ll fr = fac[n];
    for (int i=1; i<=n; ++i) {
      ll stars = n-i-(ll) (i-1)*(k-1);
      if (stars < 0) {
        f[i] = 0;
        continue;
      }
      f[i] = (choose(stars+i, i)*fac[i]%MOD)*fac[n-i]%MOD;
      fr += f[i];
    }
    cout << (fr%MOD)*ifac[n]%MOD << "\n";
  }
  return 0;
}