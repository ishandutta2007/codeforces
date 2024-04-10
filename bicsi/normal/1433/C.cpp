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
    vector<int> v(n);
    int best = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      best = max(best, v[i]);
    }

    int choose = -1;
    for (int i = 0; i < n; ++i) {
      if (v[i] == best) {
        if (i > 0 && v[i - 1] < v[i]) {
          choose = i + 1;
          break;
        }
        if (i + 1 < n && v[i + 1] < v[i]) {
          choose = i + 1;
          break;
        }
      }
    }
    cout << choose << '\n';
  }

  return 0;
}