#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ans = a[0];
    for (int i = 1; i < n; ++i) {
      int need = a[i] * i;
      need = min(need, d);
      need = need / i * i;
      
      ans += need / i;
      d -= need;
    }

    cout << ans << '\n';
  }

  return 0;
}