#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MOD = 998'244'353;

ll modpow(ll b, ll p) {
  ll ans = 1;
  for (; p; p/=2, b=b*b%MOD) {
    if (p&1) {
      ans = ans*b%MOD;
    }
  }
  return ans;
}

const int N = 300300;
string grid[N];
int n, m;

ll pre[N];

void setup() {
  ll i2 = modpow(2, MOD-2);
  pre[0] = i2*i2%MOD;
  pre[1] = pre[0]*i2%MOD;
  for (int i=2; i<N; ++i) {
    if (i%2 == 0) {
      pre[i] = (pre[i-1] + modpow(i2, i+2))%MOD;
    } else {
      pre[i] = (pre[i-2] + modpow(i2, i+2))%MOD;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  setup();
  cin >> n >> m;
  ll zc = 0;
  for (int i=0; i<n; ++i) {
    cin >> grid[i];
  }

  ll ans = 0;
  for (int i=0; i<n; ++i) {
    int streak = 0;
    for (int j=0; j<m; ++j) {
      if (grid[i][j] == 'o') {
        ++zc;
        ++streak;
      } else {
        streak = 0;
      }
      if (streak >= 2) {
        ans += pre[streak-2];
      }
    }
  }
  for (int j=0; j<m; ++j) {
    int streak = 0;
    for (int i=0; i<n; ++i) {
      if (grid[i][j] == 'o') {
        ++streak;
      } else {
        streak = 0;
      }
      if (streak >= 2) {
        ans += pre[streak-2];
      }
    }
  }

  ans = ans%MOD;
  ans = ans*modpow(2, zc)%MOD;
  cout<< ans << "\n";
  
  return 0;
}