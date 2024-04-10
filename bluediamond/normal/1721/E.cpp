#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  string s, t;
  cin >> s;
  int q, n = (int) s.size(), m = 0;
  cin >> q;
  vector<int> ps(n, 0);
  vector<vector<int>> shortcut(26, vector<int> (n, -1));
  function<int(int)> get = [&] (int i) {
    assert(0 <= i && i < n + m);
    int x = -1;
    if (i < n) {
      x = s[i] - 'a';
    } else {
      i -= n;
      assert(0 <= i && i < m);
      x = t[i] - 'a';
    }
    assert(0 <= x && x < 26);
    return x;
  };
  function<int(int, int)> fnd = [&] (int i, int x) {
    if (i >= n) {
      if (x == get(ps[i - 1])) {
        return ps[i - 1] + 1;
      }
      if (ps[i - 1] == 0) {
        return 0;
      }
      return fnd(ps[i - 1], x);
    }
    assert(0 <= i && i < n);
    assert(0 <= x && x < 26);
    if (shortcut[x][i] != -1) {
      return shortcut[x][i];
    }
    if (x == get(ps[i - 1])) {
      return shortcut[x][i] = ps[i - 1] + 1;
    }
    if (ps[i - 1] == 0) {
      return shortcut[x][i] = 0;
    }
    return shortcut[x][i] = fnd(ps[i - 1], x);
  };
  {
    ps[0] = 0;
    for (int i = 1; i < n; i++) {
      ps[i] = fnd(i, get(i));
    }
  }
  for (int iq = 1; iq <= q; iq++) {
    cin >> t;
    m = (int) t.size();
    ps.resize(n);
    ps.resize(n + m, 0);
    for (int i = n; i < n + m; i++) {
      ps[i] = fnd(i, get(i));
    }
    for (int i = n; i < n + m; i++) {
      cout << ps[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}