#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
const ll MOD = 998244353;

ll mpow(ll b, ll p) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%MOD) {
    if (p&1) {
      ans = ans*b%MOD;
    }
  }
  return ans;
}

ll fac[N];
ll ifac[N];

void setup() {
  ifac[0] = fac[0] = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
  }
  ifac[N-1] = mpow(fac[N-1], MOD-2);
  for (int i=N-2; i; --i) {
    ifac[i] = ifac[i+1]*(i+1)%MOD;
  }
}

ll choose(int n, int k) {
  return (fac[n]*ifac[k]%MOD)*ifac[n-k]%MOD;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << fac[n] << endl;
    return 0;
  }
  if (k >= n) {
    cout << 0 << endl;
    return 0;
  }

  k = n-k;

  ll ans = 0;
  ll dir = 1;
  for (int i=k; i>=1; --i) {
    ans += (dir*choose(k, i)%MOD)*mpow(i, n)%MOD+MOD;
    dir *= -1;
  }
  ans = (2*ans%MOD)*choose(n, k)%MOD;
  cout << ans << endl;

  return 0;
}