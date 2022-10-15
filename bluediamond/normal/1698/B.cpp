/// 486 -> 487
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, k, print;
int a[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (k > 1) {
      int sol = 0;
      for (int i = 2; i < n; i++) {
        sol += (a[i] > a[i - 1] + a[i + 1]);
      }
      cout << sol << "\n";
    } else {
      int sol = 0;
      for (int i = 2; i < n; i += 2) {
        sol++;
      }
      cout << sol << "\n";
    }
  }
}