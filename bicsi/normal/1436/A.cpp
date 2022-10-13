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
    int n; long long m; cin >> n >> m;
    vector<int> v(n);
    long long s = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      s += v[i];
    }
    if (s == m) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}