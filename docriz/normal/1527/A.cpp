#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int ans = 1;
    while (n) {
      ans <<= 1;
      n /= 2;
    }
    ans >>= 1;
    ans -= 1;
    cout << ans << "\n";
  }
  return 0;
}