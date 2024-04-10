#include <bits/stdc++.h>

using namespace std;

bool match(string s, string t) {
  int n = (int) s.size(), m = (int) t.size();
  vector<int> pre(n), suf(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (cur < m && s[i] == t[cur]) {
      cur++;
    }
    pre[i] = cur;
  }
  reverse(t.begin(), t.end());
  cur = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (cur < m && s[i] == t[cur]) {
      cur++;
    }
    suf[i] = cur;
  }
  for (int i = 0; i + 2 < n; i++) {
    if (pre[i] + suf[i + 2] >= m && pre[i] && suf[i + 2]) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    string s;
    cin >> n >> q >> s;
    while (q--) {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      string want;
      for (int j = l; j <= r; j++) {
        want += s[j];
      }
      if (match(s, want)) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

}