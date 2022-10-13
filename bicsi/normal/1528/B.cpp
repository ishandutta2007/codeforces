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
const int MOD = 998244353;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n; 
  // n *= 2;

  vector<int> dp(n + 1), sp(n + 1, 0);
  dp[1] = 1; sp[1] = 1;
  
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i] + sp[i - 1] + 1) % MOD;
    for (int j = i; j <= n; j += i)
      dp[j] += 1;
    sp[i] = (dp[i] + sp[i - 1]) % MOD;
  }
  cout << dp[n] << endl;
  /*
  int ans1 = 1; // all included
  
  // exterior + alternating
  int ans2 = 0;
  for (int div = 2; div < n; div += 2) {
    for (int mul = div + div; mul <= n; mul += div) {
      ans2 += 1;
    }
  }
  // exterior + alternating + interior
  int ans3 = 0;
  for (int i = 6; i <= n; i += 2)
    ans3 += i / 2 - 2; 
  
  cerr << ans1 << " " << ans2 << " " << ans3 << endl;
  cout << ans1 + ans2 + ans3 << endl;
  */
  return 0;
}