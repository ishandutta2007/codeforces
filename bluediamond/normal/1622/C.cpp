#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 2e5 + 7;
const int INF = (int) 1e18;
int n;
int k;
int a[N];
int sum[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + a[i];
    }
    int sol = INF;
    for (int suf = n + 1; suf >= 2; suf--) {
      int cost = n - suf + 1;
      if (a[1] * (n - suf + 2) + sum[suf - 1] - sum[1] <= k) {
        sol = min(sol, cost);
        continue;
      }
      int lft = a[1] * (n - suf + 2) - k - sum[1] + sum[suf - 1];
      int rgh = n - suf + 2;
      int s = (lft + rgh - 1) / rgh;
      sol = min(sol, s + cost);
    }
    cout << sol << "\n";
  }
  return 0;
}