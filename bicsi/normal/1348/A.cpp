#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
      sum += (1LL << i);
    }
    long long a = 0;
    for (int i = 1; i < n/2; ++i)
      a += (1LL << i);
    a += (1 << n);
    long long b = sum - a;
    cout << abs(a - b) << endl;
  }
 
  return 0;
}