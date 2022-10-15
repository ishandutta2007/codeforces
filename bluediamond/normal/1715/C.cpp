#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = (int) 1e5 + 7;
int n, m, a[N], coef[N];

signed main() {

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE


  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int p = 1; p < n; p++) {
    coef[p] = p * (n - p);
  }
  int sol = 0;
  for (int p = 1; p < n; p++) {
    sol += (a[p] != a[p + 1]) * coef[p];
  }
  for (int iq = 1; iq <= m; iq++) {
    int i, x;
    cin >> i >> x;
    for (int p = i - 3; p <= i + 3; p++) {
      if (1 <= p && p < n) {
        sol -= (a[p] != a[p + 1]) * coef[p];
      }
    }
    a[i] = x;
    for (int p = i - 3; p <= i + 3; p++) {
      if (1 <= p && p < n) {
        sol += (a[p] != a[p + 1]) * coef[p];
      }
    }
    cout << sol + n * (n + 1) / 2 << "\n";

  }
  return 0;
}
/**
**/