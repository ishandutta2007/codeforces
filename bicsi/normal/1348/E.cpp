#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  long long total = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    total += a[i] + b[i];
  }
  
  vector<vector<bool>> dp(k, vector<bool>(k, 0));
  auto ndp = dp;
  dp[0][0] = 1;
  
  for (int i = 0; i < n; ++i) {
    int total = (a[i] + b[i]) % k;
    for (int i = 0; i < k; ++i)
      fill(ndp[i].begin(), ndp[i].end(), 0);
 
    for (int ha = 0; ha < k; ++ha) {
      for (int hb = 0; hb < k; ++hb) {
        if (!dp[ha][hb]) continue;
        ndp[(ha + a[i]) % k][(hb + b[i]) % k] = true;
        for (int na = 0, nb = total; na <= total; ++na, --nb) {
          if (na > a[i] || nb > b[i]) continue;
          ndp[(ha + na) % k][(hb + nb) % k] = true;
        }
        for (int na = 0, nb = total + k; na <= total + k; ++na, --nb) {
          if (na > a[i] || nb > b[i]) continue;
          ndp[(ha + na) % k][(hb + nb) % k] = true;
        }
      }
    }
    swap(dp, ndp);
  }
 
  long long ans = 0;
  for (int ha = 0; ha < k; ++ha) {
    for (int hb = 0; hb < k; ++hb) {
      if (!dp[ha][hb]) continue;
      ans = max(ans, (total - ha - hb) / k);
    }
  }
  cout << ans << endl;
 
  return 0;
}