#include <bits/stdc++.h>
using namespace std;
#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define len(x) ((int)x.size())
#define rem ((llong)1e9 + 7)

#define maxn 101010
#define maxnp 19
#define maxa 71
int p[maxnp] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37, 41,43,47,53,59,61,67};
int n;
int fac[maxa] = {0}, cnt[maxa] = {0};

llong dp[2][1 << maxnp] = {0};

llong p2[maxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  p2[0] = 1;
  rep1(i, maxn - 1) p2[i] = (p2[i - 1] * 2) % rem;
  rep1(i, maxa - 1) {
    int mask = 0;
    int t = i;
    rep(f, maxnp) {
      while (t % p[f] == 0) {
        mask ^= 1 << f;
        t /= p[f];
      }
    }
    fac[i] = mask;
  }
  cin >> n;
  rep(i, n) {
    int u; cin >> u;
    cnt[u] ++;
  }

  dp[0][0] = 1;
  bool s;
  rep1(i, maxa - 1) {
    s = i & 1;
    memset(dp[s], 0, sizeof(dp[s]));
    rep(f, (1 << maxnp)) {
      if (cnt[i] == 0) dp[s][f] = dp[!s][f];
      else {
        llong pp = p2[cnt[i] - 1];
        (dp[s][f] += pp * dp[!s][f] % rem) %= rem;
        (dp[s][f ^ fac[i]] += pp * dp[!s][f] % rem) %= rem;
      }
    }
  }
  cout << (dp[s][0] -1 + rem) % rem;

  return 0;
}