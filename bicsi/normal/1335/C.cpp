#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      cnt[v[i]] += 1;
    }

    int ans = 0;
    for (auto p : cnt) {
      // Take whole
      ans = max(ans, min(p.second, (int)cnt.size() - 1));
      // Take whole - 1
      ans = max(ans, min(p.second - 1, (int)cnt.size()));
    }
    
    cout << ans << '\n';
    
  }
  return 0;
}