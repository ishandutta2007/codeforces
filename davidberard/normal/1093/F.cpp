#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 100100;
const int K = 105;
const ll MOD = 998244353;

int mp(int x) {
  if (x == -1) return 104;
  return x;
}

int a[N];
ll dp[N][K];
ll sp[N][K];
int asum[N][K];
ll pre[N];
int n, k, len;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> len;
  for (int i=1; i<=n; ++i) {
    cin >> a[i];
    for (int j=0; j<K; ++j) {
      asum[i][j] = asum[i-1][j];
    }
    asum[i][mp(a[i])]++;
  }
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=k; ++j) {
      int lo = max(0, i-len+1), hi = i;
      while (lo < hi) {
        int mid = (lo+hi)/2;
        if (asum[i][mp(-1)] - asum[mid][mp(-1)] + asum[i][j] - asum[mid][j] < (i-mid)) {
          lo = mid+1;
        } else {
          hi = mid;
        }
      }
      dp[i][j] = pre[i-1] - pre[max(0, lo-1)] - sp[i-1][j] + sp[max(0, lo-1)][j];
      if (lo-1 == -1) {
        dp[i][j] ++;
      }
      dp[i][j] = (dp[i][j]%MOD + MOD)%MOD;
      sp[i][j] = (sp[i-1][j] + dp[i][j])%MOD;
      pre[i] += dp[i][j];
    }
    pre[i] = (pre[i-1] + pre[i])%MOD;
  }
  ll ans = 0;
  for (int i=1; i<=k; ++i) {
    ans += dp[n][i];
  }
  cout << ans %MOD << "\n";
  return 0;
}