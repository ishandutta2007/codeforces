#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), s(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
      a[i] -= b[(i - 1 + n) % n];
    }
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i - 1];
    }

    if (s[n] > 0) {
      cout << "NO\n";
      continue;
    }

    vector<ll> fin(n, -2);
    {
      vector<int> stk2, stk1;
      for (int i = n - 1; i >= 0; i--) {
        int c = 0;
        int nxt1 = -1, nxt2 = -1;
        int low = 0, high = (int)stk2.size() - 1;
        while (low <= high) {
          int id = (low + high) / 2;
          int j = stk2[id];
          if (s[j + 1] - b[j] - 1 >= s[i + 1]) {
            nxt2 = j;
            low = id + 1;
          }
          else {
            high = id - 1;
          }
        }
        while (!stk1.empty() && s[stk1.back() + 1] > s[i + 1]) {
          stk1.pop_back();
        }
        if (!stk1.empty()) {
          nxt1 = stk1.back();
        }
        stk1.push_back(i);
        while (!stk2.empty() && s[stk2.back() + 1] - b[stk2.back()] - 1 <= s[i + 1] - b[i] - 1) {
          stk2.pop_back();
        }
        stk2.push_back(i);
        if (nxt1 == -1 && nxt2 == -1) {
          fin[i] = s[n] - s[i + 1];
          continue;
        }
        if (nxt1 == -1) {
          fin[i] = -1;
          continue;
        }
        if (nxt2 == -1) {
          fin[i] = fin[nxt1];
          continue;
        }
        if (nxt1 <= nxt2) {
          fin[i] = fin[nxt1];
        }
        else {
          fin[i] = -1;
        }
      }
    }
    ll low = 0, high = b[0];
    bool ok = 0;

    for (int i = 1; i < n && !ok; i++) {
      if (low > high) {
        break;
      }
      if (low <= s[1] - s[i + 1] - 1) {
        if (fin[i] != -1 && min(high, s[1] - s[i + 1] - 1) >= fin[i] + a[0]) {
          ok = 1;
        }
        low = s[1] - s[i + 1] - 1 + 1;
        if (low > high) {
          break;
        }
      }
      high = min(high, s[1] + b[i] + 1 - s[i + 1] - 1);
    }

    if (low <= high) {
      ok = 1;
    }

    cout << ((ok) ? ("YES") : ("NO")) << "\n";
  }
  return 0;
}