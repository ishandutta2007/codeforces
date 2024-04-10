#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    if (n <= 26) {
      for (int i = 1; i <= n; i++) {
        cout << (char)(i - 1 + 'a');
      }
      cout << "\n";
      continue;
    }
    int k = n / 4;
    string ans;
    for (int i = 0; i < 2 * k; i++) {
      ans += "a";
    }
    ans += "b";
    for (int i = 0; i < 2 * k - 1; i++) {
      ans += "a";
    }
    for (int i = 0; i < n % 4; i++) {
      ans += (char)(i + 'c');
    }
    cout << ans << "\n";
  }
  return 0;
}