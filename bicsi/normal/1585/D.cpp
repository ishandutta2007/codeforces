#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n), seen(n, 0);
    int dup = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i]; --v[i];
      if (seen[v[i]]) 
        dup = 1;
      seen[v[i]] = 1;
    }
    if (is_sorted(v.begin(), v.end())) {
      cout << "YES\n";
    } else if (n <= 2) {
      cout << "NO\n";
    } else if (dup) {
      cout << "YES\n";
    } else {
      int ans = n;
      for (int i = 0; i < n; ++i) {
        if (seen[i]) {
          ++ans;
          for (int j = i; seen[j]; j = v[j])
            seen[j] = 0;
        }
      }
      if (ans % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }

  return 0;
}