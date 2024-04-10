/// 463 -> 464
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 2e5 + 7;
int n;
int k;
ll a[N];
ll sum_pref[N];

int alone = 0, self = 0;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  if (1) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum_pref[i + 1] = sum_pref[i] + a[i];
    }
    if (n == 1) {
      cout << k + a[0] - 1 << "\n";
      continue;
    }
    if (k > n) {
      ll sum = sum_pref[n];
      for (int i = 0; i < n; i++) {
        sum += k - i - 1;
      }
      cout << sum << "\n";
      continue;
    }
    assert(k <= n);
    ll sol = 0;
    for (int l = 0; l + k - 1 < n; l++) {
      sol = max(sol, sum_pref[l + k] - sum_pref[l]);
    }
    cout << sol + k * (ll) (k - 1) / 2 << "\n";
  }
}