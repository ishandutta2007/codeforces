#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll INF = 0x3f3f3f3f3f3f3f3f;
ll tpow[100100];

void solve(ll n, ll k, ll off) {
  if (n == 0) {
    return;
  }
  ll ha = 0;
  for (int i=1; i<=n; ++i) {
    if (ha+tpow[n-i]>= k) {
      for (int j=i; j>=1; --j) {
        cout << off+j << " ";
      }
      solve(n-i, k-ha, off+i);
      return;
    }
    ha += tpow[n-i];
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  tpow[0] = 1;
  tpow[1] = 1;
  for (int i=2; i<100100; ++i) {
    tpow[i] = min(INF, tpow[i-1]*2);
  }
  int TT;
  cin >> TT;
  while (TT--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n+1);
    if (k > tpow[n]) {
      cout << -1 << "\n";
      continue;
    }
    solve(n, k, 0);
    cout << "\n";
  }
  return 0;
}