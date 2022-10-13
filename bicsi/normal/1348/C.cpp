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
    map<char, int> cnt;
    for (auto x : s)
      cnt[x] += 1;
    
    if (cnt.size() == 1) {
      string ans;
      for (int i = 0; i < cnt.begin()->second; i += k)
        ans += cnt.begin()->first;
      cout << ans << '\n';
    } else if (cnt.size() == 2 && cnt.begin()->second == k) {
      string ans = string() + cnt.begin()->first;
      for (int i = 0; i < next(cnt.begin())->second; i += k)
        ans += next(cnt.begin())->first;
      cout << ans << '\n';
    } else if (cnt.begin()->second >= k) {
      cnt.begin()->second -= k - 1;
      string ans;
      for (auto p : cnt)
        for (int i = 0; i < p.second; ++i)
          ans += p.first;
      cout << ans << '\n';
    } else {
      auto it = cnt.begin();
      while (it->second < k) {
        k -= it->second;
        ++it;
      }
      cout << it->first << '\n';
    }
  }


  return 0;
}