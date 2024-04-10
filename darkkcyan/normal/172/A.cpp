#include <bits/stdc++.h>

using namespace std;

int main() {
  int n; cin >> n; --n;
  string l; cin >> l;
  int ans = l.size();
  while (n--) {
    string cur; cin >> cur;
    for (int i = 0; i < ans; ++i) {
      if (l[i] != cur[i]) {
        ans = i;
        break;
      }
    }
    l = cur;
  }
  cout << ans;
  return 0;
}