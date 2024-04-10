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
    vector<int> v(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      freq[v[i]] += 1;
    }

    bool bad = false;
    for (auto [a, f] : freq) {
      if (f > (n + 1) / 2) {
        cout << -1 << '\n';
        bad = true;
        break;
      }
    }
    if (bad) continue;
    
    vector<pair<int, int>> seq;
    for (int i = 0; i < n; ++i) {
      int now = v[i];
      if (seq.empty() || seq.back().second == now) {
        seq.emplace_back(now, now);
      } else {
        seq.back().second = now;
      }
    }
    
    int cnt = 0;
    map<int, int> mp;
    for (auto [a, b] : seq) {
      mp[a] += 1; mp[b] += 1;
      cnt += 2;
    }
    
    int pula = 0;
    for (auto x : mp) {
      int delta = (x.second - (cnt - x.second)) / 2;
      if (delta <= 1) continue;
      pula = max(pula, delta - 1);
    }

    cout << (int)seq.size() - 1 + pula << '\n';
  }
  return 0;
}