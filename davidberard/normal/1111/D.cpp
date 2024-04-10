#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e9+7;
const int N = 200200;

ll fac[N], ifac[N];

ll modpow(ll b, ll p) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%MOD) {
    if (p&1) {
      ans = ans*b%MOD;
    }
  }
  return ans;
}
void setup() {
  fac[0] = ifac[0] = 1;
  for (int i=1; i<N; ++i) {
    fac[i] = fac[i-1]*i%MOD;
  }
  ifac[N-1] = modpow(fac[N-1], MOD-2);
  for (int i=N-2; i>0; --i) {
    ifac[i] = ifac[i+1]*(i+1)%MOD;
  }
}
ll choose(int n, int k) {
  return (fac[n]*ifac[n-k]%MOD)*ifac[k]%MOD;
}

int n;
string s;

int a[256];
ll dp[N];
ll cp[N];
ll W = 1;

map<pair<int, int>, ll> mp;
ll solve(int x, int y) {
  if (mp.count({x, y})) {
    return mp[pair<int, int>(x, y)];
  }
  for (int i=0; i<=n/2; ++i) {
    cp[i] = dp[i];
  }
  for (int i=a[x]; i<=n/2; ++i) {
    cp[i] -= cp[i-a[x]];
    cp[i] += MOD;
    cp[i] %= MOD;
  }
  if (x != y) {
    for (int i=a[y]; i<=n/2; ++i) {
      cp[i] -= cp[i-a[y]];
      cp[i] += MOD;
      cp[i] %= MOD;
    }
  }
  ll ans = 2 * cp[n/2] * W %MOD;
  return mp[pair<int, int>(x, y)] = ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> s;
  n = s.size();
  for (auto& c : s) {
    ++a[(int)c];
  }
  dp[0] = 1;
  W = fac[n/2]*fac[n/2]%MOD;
  for (int i='A'; i<='z'; ++i) {
    if (!a[i]) {
      continue;
    }
    W = W*ifac[a[i]]%MOD;
    for (int j=n-a[i]; j>=0; --j) {
      dp[j+a[i]] += dp[j];
      dp[j+a[i]] %= MOD;
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int i, j;
    cin >> i >> j;
    --i; 
    --j;
    cout << solve(min(s[i], s[j]), max(s[i], s[j]))<< "\n";
  }

  return 0;
}