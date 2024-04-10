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

int query(int pos) {
  cout << "? " << pos << endl;
  int ans; cin >> ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  int l = 1, r = n;
  while (r - l > 3) {
    int m = (l + r) / 2;
    if (query(m) < query(m + 1)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  while (r - l >= 1) {
    if (query(l + 1) < query(l)) {
      ++l;
    } else {
      cout << "! " << l << endl;
      return 0;
    }
  }
  cout << "! " << l << endl;
  return 0;
}