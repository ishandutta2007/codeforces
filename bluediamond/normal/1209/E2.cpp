#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 12;
const int M = 2000;
int n, m, b[N][M], a[N][M], mx[M], id[M];
int dp[(1 << N)], ndp[(1 << N)], sum[(1 << N)];

bool cmp(int i, int j) {
  return mx[i] > mx[j];
}

void cop() {
  for (int i = 0; i < (1 << n); i++) {
    dp[i] = ndp[i];
  }
}

int bits[N], top;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int j = 0; j < m; j++) {
      mx[j] = 0;
      id[j] = j;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> b[i][j];
        mx[j] = max(mx[j], b[i][j]);
      }
    }
    sort(id, id + m, cmp);
    m = min(m, n);
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n; i++) {
        a[i][j] = b[i][id[j]];
      }
    }
    for (int i = 0; i < (1 << n); i++) {
      dp[i] = ndp[i] = -(int) 2e9;
    }
    dp[0] = 0;
    for (int j = 0; j < m; j++) {
      for (int mask = 0; mask < (1 << n); mask++) {
        sum[mask] = 0;
        for (int bit = 0; (1 << bit) <= mask; bit++) {
          if (mask & (1 << bit)) {
            sum[mask] += a[bit][j];
          }
        }
      }
      for (int mask = 0; mask < (1 << n); mask++) {
        int submask = mask;
        while (submask) {
          ndp[mask] = max(ndp[mask], dp[mask - submask] + sum[submask]);
          submask = (submask - 1) & mask;
        }
      }
      for (int mask = 0; mask < (1 << n); mask++) {
        for (int shift = 0; shift < n; shift++) {
          int nmask = 0;
          for (int j = 0; j < n; j++) {
            int id = (j + shift) % n;
            if (mask & (1 << id)) {
              nmask += (1 << j);
            }
          }
          ndp[mask] = max(ndp[mask], ndp[nmask]);
        }
      }
      cop();
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
      ans = max(ans, dp[mask]);
    }
    cout << ans << '\n';
  }

  return 0;
}