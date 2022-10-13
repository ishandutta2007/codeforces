#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
const int BS = 256;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<vector<int>> go(n), og(n);
  for (int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r; --l; --r;
    go[l].push_back(r);
    og[r].push_back(l);
  }

  for (int i = 0; i < n; ++i)
    sort(go[i].begin(), go[i].end());
 
  int q; cin >> q;
  vector<tuple<int, int, int, int>> qrs;
  for (int i = 0; i < q; ++i) {
    int l, r; cin >> l >> r; --l; --r;
    qrs.emplace_back(l / BS + 1, r, l, i);
  }
  sort(qrs.begin(), qrs.end());

  vector<int> ans(q);
  int pbi = -1, pr = -1;
  vector<int> stk;
  vector<int> one_step(n);

  for (auto [bi, r, l, i] : qrs) {
    int split = bi * BS;
    if (bi != pbi) {
      stk.clear();
      pr = max(0, split - BS) - 1;
      iota(one_step.begin(), one_step.end(), 0);
      pbi = bi;
    }

    while (pr < r) {
      ++pr;

      for (auto x : og[pr])
        one_step[x] = pr;

      if (pr >= split) {
        int lowest = pr;
        for (auto lp : og[pr])
          if (lp >= split)
            lowest = min(lowest, lp);
        while (stk.size() && stk.back() >= lowest)
          stk.pop_back();
        stk.push_back(pr);
      }
    } 


    if (r - l <= BS) {
      // cerr << "SMALL" << endl;
      int at = l;
      for (int j = l; j <= at; ++j)
        at = max(at, one_step[j]);
      ans[i] = at;
    } else {
      int at = l;
      for (int j = l; j <= at && j < split; ++j)
        at = max(at, one_step[j]);
      if (at < split) {
        ans[i] = at;
      } else {
        auto it = lower_bound(stk.begin(), stk.end(), at);
        ans[i] = *it;
      }
    }
  } 
  
  for (int i = 0; i < q; ++i)
    cout << ans[i] + 1 << '\n';

  return 0;
}