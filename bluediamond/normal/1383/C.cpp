#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int ttt;
  cin >> ttt;
  while (ttt--) {
    int n;
    cin >> n;
    string s, tt;
    cin >> s >> tt;
    assert((int)s.size() == n);
    assert((int)tt.size() == n);
    vector<int> g(20, 0), t(20);
    for (int i = 0; i < 20; i++) {
      t[i] = i;
    }
    function<int(int)>root = [&](int i) {
      if (t[i] == i) {
        return i;
      }
      else {
        return t[i] = root(t[i]);
      }
    };
    function<void(int, int)>join = [&](int i, int j) {
      t[root(i)] = root(j);
    };
    for (int i = 0; i < n; i++) {
      int a = s[i] - 'a';
      int b = tt[i] - 'a';
      if (a == b) continue;
      assert(0 <= a && a < 20);
      assert(0 <= b && b < 20);
      g[a] |= (1 << b);
      join(a, b);
    }
    int comps = 0;
    for (int i = 0; i < 20; i++) {
      comps += (t[i] == i);
    }

    /// largest dag
    vector<bool> isdag(1 << 20);
    isdag[0] = 1;
    for (int mask = 1; mask < (1 << 20); mask++) {
      isdag[mask] = 0;
      for (int lv = 0; lv < 20; lv++) {
        if (mask & (1 << lv)) {
          if (isdag[mask - (1 << lv)] && !(g[lv] & mask)) {
            isdag[mask] = 1;
            break;
          }
        }
      }
    }
    int bigdag = 0;
    for (int mask = 0; mask < (1 << 20); mask++) {
      if (isdag[mask]) {
        int cur = 0;
        for (int i = 0; i < 20; i++) {
          if (mask & (1 << i)) {
            cur++;
          }
        }
        bigdag = max(bigdag, cur);
      }
    }
    cout << 2 * (20 - bigdag) + bigdag - comps << "\n";

  }
  return 0;
}