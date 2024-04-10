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
    vector<int> stk;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      if (x == 1) {
        stk.push_back(x);
      } else {
        while (x != stk.back() + 1) 
          stk.pop_back();
        stk.back() += 1;
      }
      for (int j = 0; j < (int)stk.size(); ++j) {
        if (j > 0) cout << ".";
        cout << stk[j];
      }
      cout << '\n';
    }
  }
  return 0;
}