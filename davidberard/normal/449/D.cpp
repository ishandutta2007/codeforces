#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int K = 20;
const int N = 1<<K;
const ll MOD = 1e9+7;

int a[N];
int f[N];

ll tpow[N];

void setup() {
  tpow[0] = 1;
  for (int i=1; i<N; ++i) {
    tpow[i] = tpow[i-1]*2%MOD;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  int n;
  cin >> n;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    ++f[a[i]^(N-1)];
  }
  for (int i=0; i<K; ++i) {
    for (int mask=0; mask<N; ++mask) {
      if (mask&(1<<i)) {
        f[mask] += f[mask^(1<<i)];
      }
    }
  }
  ll ans = 0;
  for (int i=0; i<N; ++i) {
    ans += (__builtin_popcount((N-1)^i)%2 ? -1 : 1) * tpow[f[i]];
  }
  ans = (ans%MOD + MOD)%MOD;
  cout << ans << "\n";
  return 0;
}