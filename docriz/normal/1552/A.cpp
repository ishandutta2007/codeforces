#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] != s2[i]) {
        ans += 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}