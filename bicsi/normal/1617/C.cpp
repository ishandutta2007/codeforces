#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> w, seen(n, 0);
    for (int i = 0; i < n; ++i) {
      if (v[i] <= n && !seen[v[i] - 1]) {
        seen[v[i] - 1] = 1;
      } else {
        w.push_back(v[i]);
      }
    }
    v.clear();
    for (int i = 0; i < n; ++i)
      if (!seen[i])
        v.push_back(i + 1);

    assert(v.size() == w.size());
    int ans = v.size();
    for (int i = 0; i < ans; ++i) {
      if (v[i] > (w[i] - 1) / 2) {
        ans = -1;
      }
    }
    cout << ans << '\n';
  }
}