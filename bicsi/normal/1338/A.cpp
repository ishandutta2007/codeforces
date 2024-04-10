#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }

    int ans = 0;
    int max_diff = 0;
    int max_elem = -2e9;
    int add = 0;

    for (int i = 0; i < n; ++i) {
      if (max_elem > v[i]) {
        while (add + v[i] < max_elem) {
          add += (1 << ans);
          ans += 1;
        }
      } else max_elem = v[i];
    }
    cout << ans << '\n';
  }

  return 0;
}