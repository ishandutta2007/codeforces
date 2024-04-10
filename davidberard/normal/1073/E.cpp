#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

//   dig bitset following? ending in zero
ll dp[20][1<<10][2][2];
ll fp[20][1<<10][2][2];
const ll MOD = 998244353;

void add(ll& x, const ll& y) {
  x = (x+y)%MOD;
}

ll calc(ll x, int k) {
  memset(dp, 0, sizeof dp);
  memset(fp, 0, sizeof fp);
  for (int i=0; i<10; ++i) {
    dp[0][1<<i][0][i==0] = 1;
    fp[0][1<<i][0][i==0] = i;
    if (i<=x%10) {
      dp[0][1<<i][1][i==0] = 1;
      fp[0][1<<i][1][i==0] = i;
    }
  }
  ll y = x/10;
  ll tpow = 10;
  for (int i=0; i<18 && y; ++i, y/=10, tpow = tpow*10%MOD) {
    for (int j=0; j<(1<<10); ++j) {
      for (int q=0; q<2; ++q) {
        for (int k=0; k<10; ++k) {
          int z = j|(1<<k);
          add(dp[i+1][z][0][k==0], dp[i][j][0][q]);
          add(fp[i+1][z][0][k==0], fp[i][j][0][q] + dp[i][j][0][q]*k*tpow);
          if (k < y%10) {
            add(dp[i+1][z][1][k==0], dp[i][j][0][q]);
            add(fp[i+1][z][1][k==0], fp[i][j][0][q] + dp[i][j][0][q]*k*tpow);
          } else if (k == y%10) {
            add(dp[i+1][z][1][k==0], dp[i][j][1][q]);
            add(fp[i+1][z][1][k==0], fp[i][j][1][q] + dp[i][j][1][q]*k*tpow);
          }
        }
      }
    }
  }
  y = x;
  ll ans = 0;
  for (int i=0; y; ++i, y/=10) {
    for (int j=0; j<(1<<10); ++j) {
      if (__builtin_popcount(j) > k) continue;
      if (y<10) {
        add(ans, fp[i][j][1][0]);
      } else {
        add(ans, fp[i][j][0][0]);
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll l, r, k;
  cin >> l >> r >> k;
  ll x = (calc(r, k)-calc(l-1, k)+MOD)%MOD;
  cout << x << "\n";
  return 0;
}