#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++i < n; )
#define sz(v) ((int)v.size())

#define rem ((llong)1e9+7)
#define maxn 5010101
//#define maxn 1000
llong t, l, r;

llong dp[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> t >> l >> r;
  for (int i = 1; i < maxn; ++i) dp[i] = (llong)i * (i - 1) / 2;
  for (int i = 2; i < maxn; ++i) {
    //clog << i << ' ' << dp[i] << endl;
    for (llong f = 2, t = i + i; t < maxn; ++f, t += i) {
      dp[t] = min(dp[t], dp[i] + t * (f - 1) / 2);
      assert(dp[t] >= 0);
    }
  }

  llong ans = 0, p = 1;
  for (int i = l; i <= r; ++i) {
    (ans += p * (dp[i] % rem) % rem) %= rem;
    (p *= t) %= rem;
  }
  cout << ans;

  return 0;
}