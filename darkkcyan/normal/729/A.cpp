#include <bits/stdc++.h>

using namespace std;

string s;

string ogo(int time) {
  string s = "o";
  while (time--) s += "go";
  return s;
}

int main() {
  int n; cin >> n;
  cin >> s;
  string ans = "";
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] != 'o') {
      ans += s[i];
      continue;
    }
    int l = 0, r = (s.size() - i) / 2;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (s.substr(i, mid * 2 + 1) == ogo(mid)) l = mid;
      else r = mid - 1;
    }
    if (l == 0) {
      ans += 'o';
      continue;
    }
    ans += "***";
    i += l * 2;
  }
  cout << ans;
  return 0;
}