#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

#define maxn 201010
int n, k;
llong a[maxn];
int dp[maxn];

llong sum(int p) {
  return a[p] - a[p - k];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;
  rep1(i, n) cin >> a[i], a[i] += a[i - 1];
  dp[k] = k;
  for (int i = k + 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (sum(i) > sum(dp[i - 1])) dp[i] = i;
    // clog << i << ' ' << dp[i] << endl;
  }
  
  int ans1 = k, ans2 = 2 * k;
  for (int i = 2 * k + 1; i <= n; ++i) {
    if (sum(ans1) + sum(ans2) < sum(dp[i - k]) + sum(i)) {
      ans1 = dp[i - k];
      ans2 = i;
    }
    // clog << ans1 << ' ' << ans2 << endl;
  }
  cout << ans1 - k + 1 << ' ' << ans2 - k + 1;
  
  return 0;
}