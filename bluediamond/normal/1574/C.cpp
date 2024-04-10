#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
const int N = (int) 2e5 + 7;
int n, a[N], q, x[N], y[N], sum = 0;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i];

    int send;

    if (a[n] < x[i]) {
      send = n;
    } else {
      /// send = min >= i

      send = -1;
      int l = 1, r = n;
      while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] >= x[i]) {
          send = m;
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      assert(send != -1);
    }

    int cost_send = max(0LL, x[i] - a[send]);
    int others = sum - a[send];
    int sol = max(0LL, y[i] - others) + cost_send;

    send--;
    if (send >= 1) {
      cost_send = max(0LL, x[i] - a[send]);
      others = sum - a[send];
      sol = min(sol, max(0LL, y[i] - others) + cost_send);
    }

    cout << sol << "\n";

  }




  return 0;
}