#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5;
const ll INF = (ll) 1e18;
const int P = 7;
int n, p, k, a[N], b[N][P], ord[N], cnt_bits[1 << P];
ll dp[N][1 << P];

bool cmp(int i, int j) {
  return a[i] > a[j];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    ord[i] = i;
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < p; j++) {
      cin >> b[i][j];
    }
  }
  sort(ord, ord + n, cmp);
  for (int mask = 0; mask < (1 << p); mask++) {
    for (int i = 0; i < p; i++) {
      if (mask & (1 << i)) {
        cnt_bits[mask]++;
      }
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < (1 << P); j++) {
      dp[i][j] = -INF;
    }
  }
  dp[0][0] = a[ord[0]];
  for (int j = 0; j < p; j++) {
    dp[0][1 << j] = b[ord[0]][j];
  }
  for (int i = 1; i < n; i++) {
    for (int mask = 0; mask < (1 << p); mask++) {
      int total = i - cnt_bits[mask];
      dp[i][mask] = max(dp[i][mask], dp[i - 1][mask] + (total < k) * a[ord[i]]);
      for (int j = 0; j < p; j++) {
        if (!(mask & (1 << j))) {
          dp[i][mask + (1 << j)] = max(dp[i][mask + (1 << j)], dp[i - 1][mask] + b[ord[i]][j]);
        }
      }
    }
  }
  cout << dp[n - 1][(1 << p) - 1] << "\n";
}