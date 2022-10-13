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
const int INF = 2e17;

struct SegTree {
  vector<int> T; int n;
  SegTree(int n) : T(2 * n, -INF), n(n) {}
  
  void Update(int pos, int val) {
    for (T[pos += n] = val; pos > 1; pos /= 2)
      T[pos / 2] = max(T[pos], T[pos ^ 1]);
  }
  int Query(int b, int e) {
    int res = -INF;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) res = max(res, T[b++]);
      if (e % 2) res = max(res, T[--e]);
    }
    return res;
  }
};


int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  SegTree st(n);
  vector<int> p(n), b(n);
  for (int i = 0; i < n; ++i)
    cin >> p[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];

  vector<int> stk;
  vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    while (stk.size() && p[stk.back()] > p[i]) {
      stk.pop_back();
    }
    if (stk.empty()) {
      // cerr << "query0: " << 0 << " " << i << endl;
      dp[i] = b[i] + max(0LL, st.Query(0, i));
    } else {
      // cerr << "query1: " << stk.back() << " " << i << endl;
      dp[i] = max(b[i] + st.Query(stk.back(), i), dp[stk.back()]);
    }
    st.Update(i, dp[i]);
    stk.push_back(i);
    // cerr << "dp[" << i + 1 << "] = " << dp[i] << endl;

    // if (stk.empty()) best = max(best, 0);
    // else {
    //   best = max(best, )
    // }
    // best = max(best, stk.empty() ? 0LL : get<2>(stk.back()));
    // stk.emplace_back(p[i], best, best + b[i]);
    // cerr << "dp(" << i << ") = {" << best << " " << best + b[i] << "}" << endl;
    // stk.emplace_back(p[i], best);
  }
  int ans = -INF;
  for (auto x : stk)
    ans = max(ans, dp[x]);
  cout << ans << endl;

  return 0;
}