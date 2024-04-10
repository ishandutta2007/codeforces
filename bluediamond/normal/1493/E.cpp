#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string add(string s) {
  int p = (int) s.size() - 1;
  while (s[p] == '1') s[p--] = '0';
  s[p] = '1';
  return s;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s, t;
  cin >> n >> s >> t;
  if (s == t) {
    cout << t << "\n";
    return 0;
  }
  if (s[0] != t[0]) {
    for (auto &c : s) c = '1';
    cout << s << "\n";
    return 0;
  }
  if (add(s) == t || t.back() == '1') {
    cout << t << "\n";
  } else {
    cout << add(t) << "\n";
  }
}