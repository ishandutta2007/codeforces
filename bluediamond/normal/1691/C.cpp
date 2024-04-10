/// 462 -> 463
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    int n, k, last = -1, cnt = 0, first = 0;
    string s;
    cin >> n >> k >> s;
    assert((int) s.size() == n);
    for (int i = 0; i < n; i++) {
      assert(s[i] == '0' || s[i] == '1');
      if (s[i] == '1') {
        last = i;
        cnt++;
        if (cnt == 1) {
          first = i;
        }
      }
    }
    if (last == -1) {
      cout << "0\n";
      continue;
    }
    int Sol = 11 * cnt;
    if (n - 1 - last <= k) {
      Sol -= 10;
      k -= (n - 1 - last);
    } else {
      if (cnt == 1 && first <= k) {
        Sol -= 1;
        k -= first;
      }
    }
    if (cnt >= 2 && first <= k) {
      Sol -= 1;
      k -= first;
    }
    cout << Sol << "\n";
  }

}