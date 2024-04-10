#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 /// freopen ("input", "r", stdin);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<bool> ok(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      int s = a[i];
      for (int j = i + 1; j < n; j++) {
        s += a[j];
        if (s > n) {
          break;
        }
        ok[s] = 1;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += ok[a[i]];
    }
    cout << ans << "\n";
  }
  return 0;
}