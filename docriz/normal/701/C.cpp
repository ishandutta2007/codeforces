#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s = "#" + s;
  set<char> have;
  for (int i = 1; i <= n; i++) {
    if (have.count(s[i])) {
      continue;
    }
    have.insert(s[i]);
  }
  int total = (int)have.size();
  int r = 0;
  int now = 0;
  int ans = INT_MAX / 2;
  map<char, int> count;
  for (int l = 1; l <= n; l++) {
    while (r + 1 <= n && now < total) {
      r += 1;
      if (count[s[r]] == 0) {
        now += 1;
      }
      count[s[r]] += 1;
    }
    if (now == total) {
      ans = min(ans, r - l + 1);
    }
    count[s[l]] -= 1;
    if (count[s[l]] == 0) {
      now -= 1;
    }
  }
  cout << ans << "\n";
  return 0;
}