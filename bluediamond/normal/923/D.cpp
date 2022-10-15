#include <bits/stdc++.h>

using namespace std;

string r(string s) {
  for (auto &c : s) {
    if (c != 'A') {
      c = 'B';
    }
  }
  return s;
}

const int N = (int) 1e5 + 7;
string s, t;
int n, m, sum1[N], sum2[N], same1[N], same2[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> s >> t;
  n = (int) s.size();
  m = (int) t.size();
  s = r(s), t = r(t);
  for (int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + s[i - 1] - 'A';
  for (int i = 1; i <= m; i++) sum2[i] = sum2[i - 1] + t[i - 1] - 'A';
  same1[1] = same2[1] = 1;
  for (int i = 2; i <= n; i++) same1[i] = (s[i - 1] == s[i - 2]) * same1[i - 1] + 1;
  for (int i = 2; i <= m; i++) same2[i] = (t[i - 1] == t[i - 2]) * same2[i - 1] + 1;
  int q;
  cin >> q;
  while (q--) {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int cnt1 = sum1[r1] - sum1[l1 - 1];
    int cnt2 = sum2[r2] - sum2[l2 - 1];
    int b1 = (s[r1 - 1] == 'A') * same1[r1], b2 = (t[r2 - 1] == 'A') * same2[r2];
    b1 = min(b1, r1 - l1 + 1);
    b2 = min(b2, r2 - l2 + 1);
    if (cnt2 < cnt1 || cnt1 % 2 != cnt2 % 2) {
      cout << 0;
      continue;
    }
    if (cnt1 == cnt2) {
      cout << (b1 >= b2 && b1 % 3 == b2 % 3);
      continue;
    }
    if (!cnt1) {
      cout << (b1 > b2);
    } else {
      cout << (b1 >= b2);
    }
  }
  cout << "\n";
}