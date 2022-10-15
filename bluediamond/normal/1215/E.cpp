#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
#define int long long

const int N = 400000;
const int K = 20;
const int INF = (int) 1e18;
int n, a[N], before[K], cnt[K][K], dp[1 << K]; /// cnt[i][j] = how many j's are before the i's
/// so if i comes before j, we must pay cnt[i][j]

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> a[i]; a[i]--;}
  for (int i = 0; i < n; i++) {
    before[a[i]]++;
    for (int j = 0; j < K; j++) cnt[a[i]][j] += before[j];
  }
  for (int mask = 1; mask < (1 << K); mask++) dp[mask] = INF;
  for (int mask = 0; mask < (1 << K); mask++) {
    assert(dp[mask] != INF);
    for (int j = 0; j < K; j++) if (!(mask & (1 << j))) {
      int cost = dp[mask];
      for (int bit = 0; bit < K; bit++) if (mask & (1 << bit)) cost += cnt[bit][j];
      dp[mask + (1 << j)] = min(dp[mask + (1 << j)], cost);
    }
  }
  cout << dp[(1 << K) - 1] << "\n";
}