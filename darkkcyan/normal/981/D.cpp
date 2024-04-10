#include<bits/stdc++.h>
using namespace std;

#define llong long long 
#define ii pair<int, int>
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )
#define xx first
#define yy second

#define maxn 60
int n, k;
llong a[maxn];

bool can(llong mask) {
  bool dp[maxn][maxn] = {0};
  dp[0][0] = 1;

  rep1(i, k) {
    rep(f, n + 1) {
      llong s = 0;
      if (!dp[i - 1][f]) continue;
      for (int g = f + 1; g <= n; ++g) {
        s += a[g];
        //clog << s << endl;
        if ((s & mask) == mask) dp[i][g] = 1;
      }
    }
  }
  return dp[k][n];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep1(i, n) cin >> a[i];
  llong ans = 0;
  for (int i = 55; i >= 0; --i) {
    if (can(ans | (1LL << i))) {
      ans |= 1LL << i;
      //clog << i << endl;
    }
  }
  cout << ans;

  return 0;
}