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
    int n, m, k; cin >> n >> m >> k;
    int maxx = n / k;
    if (m <= maxx) {
      cout << m << '\n';
    } else {
      cout << maxx - (m - maxx + k - 2) / (k - 1) << '\n';
    }
  }

  return 0;
}