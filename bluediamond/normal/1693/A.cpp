/// 481 -> 482
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, a[N];

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE


  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    bool ok = 1;
    bool deja = 0;
    ll sum_of_all = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum_of_all += a[i];
      if (deja) {
        ok &= (sum_of_all == 0);
      } else {
        if (sum_of_all == 0) {
          deja = 1;
        } else {
          ok &= (sum_of_all > 0);
        }
      }
    }
    ok &= deja;
    cout << ((ok) ? ("Yes") : ("No")) << "\n";
  }


}


/**

**/