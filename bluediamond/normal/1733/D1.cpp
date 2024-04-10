#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int te;
  cin >> te;
  for (int tc = 1; tc <= te; tc++) {
    int n;
    ll x, y, cost = 0;
    string s, t;
    cin >> n >> x >> y >> s >> t;
    /// x >= y



    x = min(x, 2 * y);
    assert((int) s.size() == n);
    assert((int) t.size() == n);
    int balance = 0;
    for (int i = 0; i < n; i++) {
      balance += s[i] - '0';
      balance += t[i] - '0';
    }
    if (balance & 1) {
      cout << "-1\n";
      continue;
    }
    vector<bool> need(n, 0);
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        need[i] = 1;
      }
    }
    for (int i = 0; i + 2 < n; i++) {
      if (need[i] && need[i + 1] && need[i + 2]) {
        need[i] = need[i + 2] = 0;
        cost += y;
      }
    }

    for (int i = 0; i + 1 < n; i++) {
      if (need[i] && need[i + 1]) {
        for (int j = 0; j < n; j++) {
          if (need[j] && j != i && j != i + 1) {
            assert(abs(i - j) > 1);
            assert(abs(i + 1 - j) > 1);
            need[i] = need[j] = 0;
            cost += y;
            break;
          }
        }
      }
    }
    int prs = 0, sg = 0;
    for (int i = 0; i + 1 < n; i++) {
      if (need[i] && need[i + 1]) {
        prs++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (need[i]) {
        sg++;
      }
    }

    cost += prs * x;
    cost += (sg - 2 * prs) / 2 * y;

    cout << cost << "\n";

  }
}