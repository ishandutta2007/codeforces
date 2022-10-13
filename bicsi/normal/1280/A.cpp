#include <bits/stdc++.h>

using namespace std;
const int kMod = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int x; cin >> x;
    string s; cin >> s;
    int at = 0;
    while (s.size() < x) {
      string t = s.substr(at + 1);
      for (int i = 1; i < s[at] - '0'; ++i) {
        s += t;
      }
      ++at;
    }
    int len = s.size();
    while (at < x) {
      int now = (len - at - 1) % kMod;
      len = (len + 1LL * (s[at] - '1') * now) % kMod;
      ++at;
    }
    if (len < 0) len += kMod;
    cout << len << '\n';
  }
  return 0;
}