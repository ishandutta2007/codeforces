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

long long Pow(int e) {
  e = min(e, 62);
  return (1LL << e);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--) {
    int n; long long k; cin >> n >> k; k -= 1;
    if (k >= Pow(n - 1)) {
      cout << -1 << '\n';
      continue;
    }

    vector<int> ans;
    while (ans.size() < n) {
      int pos = ans.size();
      for (int len = 1; len <= n - pos; ++len) {
        long long cnt = (pos + len == n ? 1 : Pow((n - pos) - len - 1));
        if (cnt > k) {
          for (int i = len; i > 0; --i)
            ans.push_back(pos + i);
          break;
        } else {
          k -= cnt;
        }
      }
    }
    assert(k == 0);
    assert(ans.size() == n);
    for (int i = 0; i < n; ++i)
      cout << ans[i] << " ";
    cout << '\n';
  }

  return 0;
}