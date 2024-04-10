#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long ans = LLONG_MIN / 2;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= min(n, i + 2 * k + 5); j++) {
        ans = max(ans, 1LL * i * j - 1LL * k * (a[i] | a[j]));
      }
    }
    cout << ans << "\n";
  }
  return 0;
}