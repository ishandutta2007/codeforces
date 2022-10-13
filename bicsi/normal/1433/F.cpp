#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  }

  vector<int> dp(k, -1e9);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    int maxx = m / 2;
    
    vector<vector<int>> knap(maxx + 1, vector<int>(k, -1e9));
    knap[0][0] = 0;
    
    for (int j = 0; j < m; ++j) 
    for (int take = maxx - 1; take >= 0; --take) 
    for (int rem = 0; rem < k; ++rem) { 
      int nrem = (rem + a[i][j]) % k;
      int ntake = take + 1;
      knap[ntake][nrem] = max(knap[ntake][nrem], knap[take][rem] + a[i][j]);
    }
      
    
    vector<int> ndp(k, -1e9);
    for (int rem1 = 0; rem1 < k; ++rem1)
    for (int rem2 = 0; rem2 < k; ++rem2) 
    for (int take = 0; take <= maxx; ++take) {
      int nrem = (rem1 + rem2) % k;
      ndp[nrem] = max(ndp[nrem], dp[rem1] + knap[take][rem2]);
    }
    swap(dp, ndp);
  }
  cout << dp[0] << '\n';

  return 0;
}