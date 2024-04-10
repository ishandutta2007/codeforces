#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxk 1010
#define rem ((llong)1e9+7)
llong mpow(llong b, llong m) {
  llong ans = 1;
  for (; m > 0; m >>= 1, (b *= b) %= rem) 
    if (m & 1) (ans *= b) %= rem;
  return ans;
}

llong k, pa, pb;
llong ans = 0;
llong dp[maxk][maxk];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> k >> pa >> pb;
  memset(dp, 0, sizeof(0));
  dp[0][1] = 1;
  llong r = mpow(pa + pb, rem - 2);
  llong ra = pa * r % rem;
  llong rb = pb * r % rem;
  for (int i = 0; i < k; ++i) {
    for (int f = 0; f <= k; ++f) {
      llong nxt = dp[i][f] * rb % rem;
      if (i + f >= k) {
        llong plus = i + f + ra - (i + f) * ra;
        plus %= rem;
        if (plus < 0) plus += rem;
        (plus *= mpow((1 - ra) * (1 - ra) % rem, rem - 2)) %= rem;
        // clog << i << ' ' << f << ' ' << dp[i][f] << ' ' << nxt << ' ' << plus << endl;
        (ans += nxt * plus % rem) %= rem;
        continue;
      }
      else (dp[i + f][f] += nxt) %= rem;
      (dp[i][f + 1] += dp[i][f] * pa % rem * r % rem) %= rem;
    }
  }
  cout << ans;
  
  return 0;
}