#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    if (k == 1) {
      if (a[n - 1] != a[0]) {
        cout << -1 << '\n';
      } else {
        cout << 1 << '\n';
      }
      continue;
    }

    vector<int> aa;
    aa.push_back(a[0]);
    for (int i = 1; i < n; ++i)
      if (a[i] > aa.back())
        aa.push_back(a[i]);
    n = aa.size();


    for (int m = 1; m <= 100; ++m) {
      int req = 1 + (n - 1 + m - 1) / m;
      if (req <= k) {
        cout << m << '\n';
        break;
      }
    }
  }

  return 0;
}