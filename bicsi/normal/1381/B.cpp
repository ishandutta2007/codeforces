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
    vector<int> v(2 * n, 0);
    for (int i = 0; i < 2 * n; ++i) {
      cin >> v[i]; v[i] -= 1;
    }
    int cnt = 0;
    vector<bool> seen(2 * n, false);
    int at = 2 * n - 1;
    vector<int> w;
    for (int i = 2 * n - 1; i >= 0; --i) {
      cnt += 1;
      seen[v[i]] = true;
      if (v[i] == at) {
        w.push_back(cnt);
        cnt = 0;
        if (!i) break;
        while (seen[at]) --at;
      }
      assert(i);
    }
    
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (auto x : w) {
      for (int i = n - x; i >= 0; --i) {
        if (dp[i])
          dp[i + x] = true;
      }
    }

    if (dp[n]) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}