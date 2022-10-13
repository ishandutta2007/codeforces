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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] += i;
      a[i] %= n;
      while (a[i] < 0) 
        a[i] += n;
    }
    sort(a.begin(), a.end());
  //  for (int i = 0; i < n; ++i)
  //    cout << a[i] << " ";
   // cout << endl;
    bool bad = false;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) 
        bad = true;
    }
    if (bad) cout << "NO\n";
    else cout << "YES\n";
  }
 
  return 0;
}