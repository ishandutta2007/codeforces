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
    vector<int> nxt(n), prv(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      nxt[i] = (i + 1) % n;
      prv[i] = (i + n - 1) % n;
    }
    
    priority_queue<tuple<long long, int, int>> pq;
    for (int i = 0; i < n; ++i) {
      if (__gcd(v[i], v[nxt[i]]) == 1) {
        pq.emplace(-i, nxt[i], i);
      }
    }

    long long last_t = -1;
    vector<int> ans;
    while (pq.size()) {
      auto [t, pos, ppos] = pq.top(); pq.pop(); t = -t;
      if (t <= last_t) continue;
      if (ppos != prv[pos]) continue;
      last_t = t;

      ans.push_back(pos);
      int pr = prv[pos], nx = nxt[pos];
      nxt[pr] = nx; prv[nx] = pr;
      nxt[pos] = prv[pos] = -1;
      if (__gcd(v[pr], v[nx]) == 1) {
        pq.emplace(-(t + n), nx, pr);
      }
    }

    cout << ans.size() << " ";
    for (auto x : ans) 
      cout << x + 1 << " "; 
    cout << '\n';
  }
  return 0;
}