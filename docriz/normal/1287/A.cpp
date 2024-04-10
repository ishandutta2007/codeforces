#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int first_A = -1;
    for (int i = 0; i < k; i++) {
      if (s[i] == 'A') {
        first_A = i;
        break;
      }
    }
    if (first_A == -1) {
      cout << 0 << "\n";
      continue;
    }
    string last = s;
    for (int i = first_A; i < k; i++) {
      last[i] = 'A';
    }
    int ans = 0;
    while (s != last) {
      ++ans;
      for (int i = k - 2; i >= 0; i--) {
        if (s[i] == 'A') s[i + 1] = 'A';
      }
    }
    cout << ans << "\n";
  }
  return 0;
}