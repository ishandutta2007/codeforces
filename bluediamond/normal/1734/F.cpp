#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int pa(ll x) {
  if (x == 0) {
    return 0;
  }
  return (x % 2 + pa(x / 2)) % 2;
}

ll dumb(ll x, ll l) {
  ll sol = 0;
  for (ll i = 0; i < l; i++) {
    sol += pa(i ^ (i + x));
  }
  return sol;
}

ll dp[62][2][2]; /// dp[cnt_proc][carry][p]
ll ways[62][2][2];

ll smart(ll x, ll l) {
  for (int i = 0; i <= 61; i++) {
    dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 0;
  }
  for (int i = 0; i <= 61; i++) {
    ways[i][0][0] = ways[i][0][1] = ways[i][1][0] = ways[i][1][1] = 0;
  }

  dp[0][0][0] = 1;
  for (int cnt_proc = 1; cnt_proc <= 61; cnt_proc++) {
    int x_here = !!(x & (1LL << (cnt_proc - 1)));
    for (int i_here = 0; i_here <= 1; i_here++) {
      for (int carry = 0; carry <= 1; carry++) {
        for (int p = 0; p <= 1; p++) {
          int sum_here = (i_here + x_here + carry);
          int np = (p + sum_here + i_here) % 2;
          dp[cnt_proc][sum_here / 2][np] += dp[cnt_proc - 1][carry][p];
        }
      }
    }
  }

  ll sol = 0;
  ll bits = 0;
  for (int fdif = 60; fdif >= 0; fdif--) {
    if (!(l & (1LL << fdif))) {
      bits += (1LL << fdif);
      continue;
    }
    ll com = l & bits;
    bits += (1LL << fdif);
    /// [0, fdif - 1] whatever I want
    /// fdif => 0
    /// [fdif + 1, 60] whatever l has

    /// process the first fdif bits


    int i_here = !!(com & (1LL << fdif));
    int x_here = !!(x & (1LL << fdif));
    for (int carry = 0; carry <= 1; carry++) {
      for (int p = 0; p <= 1; p++) {
        int sum_here = (i_here + x_here + carry);
        int np = (p + sum_here + i_here) % 2;
        ways[fdif + 1][sum_here / 2][np] += dp[fdif][carry][p];
      }
    }
  }
  for (int cnt_proc = 1; cnt_proc <= 61; cnt_proc++) {
    int i_here = !!(l & (1LL << (cnt_proc - 1)));
    int x_here = !!(x & (1LL << (cnt_proc - 1)));
    for (int carry = 0; carry <= 1; carry++) {
      for (int p = 0; p <= 1; p++) {
        int sum_here = (i_here + x_here + carry);
        int np = (p + sum_here + i_here) % 2;
        ways[cnt_proc][sum_here / 2][np] += ways[cnt_proc - 1][carry][p];
      }
    }
  }
  sol += ways[61][0][1];

  return sol;
}

int main() {
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  ///ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    ll x, l;
    cin >> x >> l;
    cout << smart(x, l) << "\n";
  }

  return 0;

}