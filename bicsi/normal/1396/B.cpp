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
    int n; cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      s += a[i];
    }
    sort(a.begin(), a.end());
    if (2 * a[n - 1] > s) {
      cout << "T" << '\n';
    } else {
      if (s % 2 == 1) {
        cout << "T" << '\n';
      } else {
        cout << "HL" << '\n';
      }
    }
  }
  return 0;
}