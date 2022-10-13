#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    cout << 3 * n << '\n';
    for (int i = 0; i < n; i += 2) {
      cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
      cout << 2 << " " << i + 1 << " " << i + 2 << '\n';
      cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
      cout << 2 << " " << i + 1 << " " << i + 2 << '\n';
      cout << 1 << " " << i + 1 << " " << i + 2 << '\n';
      cout << 2 << " " << i + 1 << " " << i + 2 << '\n';
    }
  }
  return 0;
}