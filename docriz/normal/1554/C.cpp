#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    unsigned int n, m;
    cin >> n >> m;
    unsigned int ans = ~n;
    for (int i = 31; i >= 0; i--) {
      unsigned int t = ans & (~(1U << i));
      if ((t ^ n) > m) {
        ans = t;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}