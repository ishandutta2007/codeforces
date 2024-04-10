#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int kMod = 1000000007;
 
void Mod(int& a) {
  if (a >= kMod) a -= kMod;
  if (a < 0) a += kMod;
}
 
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
 
  string s; cin >> s;
  vector<int> v;
  int cnt = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '1') {
      v.push_back(cnt);
      cnt = 0;
    } else ++cnt;
  }
  v.push_back(cnt);
 
  int n = v.size();
  vector<int> dp(n, 0), ps(n, 0);
  dp[0] = v[0] + 1;
  map<int, int> mp;
  mp[1e9] = 0;
 
  for (int i = 1; i < n; ++i) {
    Mod(ps[i] = dp[i - 1] + ps[i - 1]);
    for (int choose = 0; choose <= v[i]; ++choose) {
      auto it = mp.lower_bound(choose);
      Mod(dp[i] += ps[i]);
      if (i != n - 1) {
        Mod(dp[i] -= ps[it->second]);
      }
    }
    while (mp.size() && mp.begin()->first <= v[i]) 
      mp.erase(mp.begin());
    mp[v[i]] = i;
  }
  
  int ans = dp[n - 1];
  if (n == 1) Mod(ans -= 1);
  cout << ans << endl;
  
 
  return 0;
}