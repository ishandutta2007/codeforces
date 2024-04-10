#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using cd = complex<ld>;

int gen_cnt(const string& s, int x, int lvl = 0, int cur = 0) {
  if (s.size() == lvl) {
    return cur % 25 == 0;
  }
  if (s[lvl] == 'X') {
    return gen_cnt(s, x, lvl + 1, cur * 10 + x);
  } else if (s[lvl] == '_') {
    int ans = 0;
    for (int i = (lvl == 0); i < 10; i++) {
      ans += gen_cnt(s, x, lvl + 1, cur * 10 + i);
    }
    return ans;
  } else {
    return gen_cnt(s, x, lvl + 1, cur * 10 + s[lvl] - '0');
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  if (s.size() == 1) {
    cout << (s[0] == '0' || s[0] == '_' || s[0] == 'X');
    return 0;
  } else if (s[0] == '0') {
    cout << 0;
    return 0;
  }
  if (count(s.begin(), s.end(), 'X')) {
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      if (s[0] != 'X' || i) {
        ans += gen_cnt(s, i);
      }
    }
    cout << ans;
  } else {
    cout << gen_cnt(s, 0);
  }
  return 0;
}