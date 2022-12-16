#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll modpow(ll b, ll p, ll m) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%m) {
    if (p&1) {
      ans = ans*b%m;
    }
  }
  return ans;
}

const int N = 450;

ll fac[N], ifac[N], tpow[N];
ll n, m;

void setup() {
  fac[0] = ifac[0] = tpow[0]  = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%m;
    ifac[i] = modpow(fac[i], m-2, m);
    tpow[i] = tpow[i-1]*2%m;
  }
}

ll choose(int n, int k) {
  assert(k >= 0 && k <= n);
  return (fac[n]*ifac[k]%m)*ifac[n-k]%m;
}

ll dp[N][N];

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  setup();
  for (int i=1; i<=n; ++i) {
    dp[0][i] = tpow[i-1];
  }
  for (int h=1; h<=n; ++h) {
    for (int i=3; i<=n; ++i) {
      for (int j=2; j<i; ++j) {
        int ones = j-1-(h-1);
        if (ones < 1) {
          continue;
        }
        dp[h][i] += (dp[h-1][j-1]*tpow[i-j-1]%m)*choose(ones+i-j, i-j)%m;
      }
      dp[h][i]%=m;
    }
  }
  ll ans = 0;
  for (int i=0; i<=n; ++i) {
    ans += dp[i][n];
  }
  cout << ans%m << "\n";
  return 0;
}