#ifdef LOCAL
#include <debug.hpp>
#else
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#define debug(...)
#endif 
 
#include <bits/stdc++.h>
#define int long long 
 
using namespace std;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int bla; cin >> bla;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int k = v[1] - v[0];
    int r = (2 * v[1] - v[0]) % k;
    while (r < 0) r += k;
 
    for (int i = 2; i < n; ++i) {
      int d = (2 * v[i] - r) % k;
      int d2 = (v[i] - r) % k;
      while (d2 < 0) d2 += k;
      while (d < 0) d += k;
      k = __gcd(k, d2);
      r = d % k;
    }
    
    //cerr << "k: " << k << "r: " << r << endl;
    bla %= k; while (bla < 0) bla += k;
 
    if (bla == r) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
 
  return 0;
}