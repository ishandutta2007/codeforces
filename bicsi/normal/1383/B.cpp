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
    int all = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      all ^= v[i];
    }

    if (all == 0) {
      cout << "DRAW\n";
      continue;
    }

    int bit = 30;
    while (!(all & (1 << bit)))
      bit -= 1;

    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      v[i] = ((v[i] >> bit) & 1);
      if (v[i]) a += 1;
      else b += 1;
    }
    if (a % 4 == 3 && b % 2 == 0) {
      cout << "LOSE\n";
    } else {
      cout << "WIN\n";
    }
  }

  return 0;
}