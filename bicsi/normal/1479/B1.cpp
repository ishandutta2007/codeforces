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
  
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  map<int, vector<int>> pos;
  for (int i = n - 1; i >= 0; --i)
    pos[v[i]].push_back(i);
  int a = -1, b = -1, ans = 0;
  for (int i = 0; i < n; ++i) {
    auto get = [&](int c) {
      while (pos[c].size() && pos[c].back() <= i) 
        pos[c].pop_back();
      if (pos[c].empty()) return n + 1;
      return pos[c].back();
    };
    if (get(a) > get(b)) swap(a, b);
    // cerr << a << " " << b << endl;
    int now = v[i];
    if (now != a) { a = now; ans += 1; }
    else if (now != b) { b = now; ans += 1; }
    else {}
  }
  cout << ans << endl;
  return 0;
}