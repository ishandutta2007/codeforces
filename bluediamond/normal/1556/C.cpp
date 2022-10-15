#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 1000 + 7;
const int INF = (int) 1e18;
int n;
int cnt[N], sol, sum[N], mn[N][N];

signed main() { /// 552
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> cnt[i];
    sum[i] = sum[i - 1];
    if (i % 2 == 1) {
      sum[i] += cnt[i];
    } else {
      sum[i] -= cnt[i];
    }
  }

  for (int i = 0; i + 1 < N; i++) {
    mn[i + 1][i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      mn[i][j] = min(mn[i][j - 1], sum[j]);
    }
  }


  for (int i = 1; i <= n; i += 2) {
    for (int j = i + 1; j <= n; j += 2) {
      int go = max(sum[i] - mn[i + 1][j - 1], max(1LL, 1 + sum[i] - sum[j - 1]));
      int nd = min(cnt[i], cnt[j] + sum[i] - sum[j - 1]);
      sol += max(0LL, nd - go + 1);
    }
  }
  cout << sol << "\n";

  return 0;
}