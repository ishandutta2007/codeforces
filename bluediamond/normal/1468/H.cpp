#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

 // freopen ("input", "r", stdin);

  int t;
  cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;
    vector<bool> u(n + 1);
    for (int i = 1; i <= m; i++) {
      int x;
      cin >> x;
      u[x] = 1;
    }
    if ((n - m) % (k - 1)) {
      cout << "NO\n";
      continue;
    }
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      if (u[i] == 0) {
        a.push_back(i);
      }
    }
    n = (int) a.size();
    k /= 2;
    bool ok = 0;
    for (int i = 0; i + 2 * k - 1 < n; i++) {
      ok |= (a[i + k] - 1 != a[i + k - 1]);
      continue;
      cout << " : ";
      for (int j = i; j < i + k; j++) cout << a[j] << " ";
      cout << ", ";
      for (int j = i + k; j < i + 2 * k; j++) cout << a[j] << " ";
      cout << "\n";
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
 ///   cout << "\n";

    continue;

    cout << k << " : ";
    for (auto &x : a) {
      cout << x << " ";
    }
    cout << "\n";
  }

}