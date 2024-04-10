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
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') continue;
      if (i >= k) {
        if (s[i % k] == '?')
          s[i % k] = s[i];
        else if (s[i % k] != s[i]) {
          bad = true;
        }
      }
    }
    if (bad) {
      cout << "NO\n";
      continue;
    }
    
    int c0 = 0, c1 = 0;
    for (int i = 0; i < k; ++i)
      if (s[i] == '0') c0 += 1;
      else if (s[i] == '1') c1 += 1;

    if (c0 <= k/2 && c1 <= k/2) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}