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
    vector<int> a(n * k + 1);
    for (int i = 1; i <= n * k; i++) {
      cin >> a[i];
    }
    int bigger = n / 2;
    int pos = n * k;
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < bigger; j++) {
        pos -= 1;
      }
      ans += a[pos--];
    }
    cout << ans << "\n";
  }
  return 0;
}