#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = LLONG_MIN / 2;
    for (int i = 1; i <= n - 1; i++) {
      ans = max(ans, 1LL * max(a[i], a[i + 1]) * min(a[i], a[i + 1]));
    }
    cout << ans << "\n";
  }
  return 0;
}