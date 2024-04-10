#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int long long
const int N = (int) 2e5 + 7;
int n, m, pref[N];

bool ok(int limit) {
  int nerez = m, spatiu = 0;
  for (int i = 1; i <= n; i++) {
    int iau = min(limit, pref[i]);
    nerez -= iau;
    spatiu += (limit - iau) / 2;
  }
  return spatiu >= nerez;
}

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
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      pref[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      assert(1 <= x && x <= n);
      pref[x]++;
    }
    int low = 0, high = (int) 1e9, sol = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (ok(mid)) {
        sol = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    assert(sol != -1);
    cout << sol << "\n";
  }
}