#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ///freopen ("input", "r", stdin);
  int t = 1;
  while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > k) {
        a.push_back(x);
      } else {
        b.push_back(x);
      }
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    vector<int> sb((int) b.size() + 1);
    sb[0] = 0;
    for (int i = 1; i <= (int) b.size(); i++) {
      sb[i] = sb[i - 1] + b[i - 1];
    }
    int sol = 0, s1 = 0;
    for (int cnt = 0; cnt <= (int) a.size(); cnt++) {
      if (cnt > 0) {
        s1 += a[cnt - 1];
      }
      int use;
      if (cnt == 0) {
        use = 0;
      } else {
        use = 1 + (d + 1) * (cnt - 1);
      }
      if (use > n) {
        break;
      }
      int rem = min((int) b.size(), n - use);
      sol = max(sol, s1 + sb[rem]);
    }
    cout << sol << "\n";
  }
  return 0;
}