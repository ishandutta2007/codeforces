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
    string s; cin >> s;
    string ss = s;
    
    
    bool has0 = false, has1 = false;
    for (int i = 0; i < n; ++i)
      if (s[i] == '<') has0 = true;
      else if (s[i] == '>') has1 = true;
   
    
    if (!has0 || !has1) {
      cout << n << '\n';
    } else {
      int ans = n;
      for (int i = 0; i < n; ++i) {
        char a = s[i], b = s[(i + n - 1) % n];
        if (a != '-' && b != '-') ans -= 1;
      }
      cout << ans << '\n';
    }
  }

  return 0;
}