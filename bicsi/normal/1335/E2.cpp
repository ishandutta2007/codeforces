#include <bits/stdc++.h>

using namespace std;

struct Penis {
  vector<int> cnt;
  int best = 0;

  Penis() : cnt(200, 0) {}

  void Add(int x) {
    cnt[x] += 1;
    best = max(best, cnt[x]);
  }
  int Get() { return best; }
};

int main() {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    vector<int> v(n);

    vector<int> lft(200, 0), rgt(200, 0);
    int ans = 0;
    vector<vector<int>> pos(200);

    for (int i = 0; i < n; ++i) {
      cin >> v[i]; --v[i];
      rgt[v[i]] += 1;
      pos[v[i]].push_back(i);
      ans = max(ans, rgt[v[i]]);
    }

    for (int i = 0; i < 200; ++i) {
      if (pos[i].size() <= 1) continue;
      int lp = pos[i].size() - 1, rp = 0;
      while (pos[i][lp] >= pos[i][rp]) 
        --lp, ++rp;

      Penis st;
      for (int j = pos[i][lp] + 1; j < pos[i][rp]; ++j) {
        st.Add(v[j]);
      }
      
      ans = max(ans, 2 * (lp + 1) + st.Get());
      while (lp > 0) {
        for (int j = pos[i][lp - 1] + 1; j <= pos[i][lp]; ++j)
          st.Add(v[j]);
        for (int j = pos[i][rp]; j < pos[i][rp + 1]; ++j)
          st.Add(v[j]);
        --lp; ++rp;
        ans = max(ans, 2 * (lp + 1) + st.Get());
      }
    }
    
    cout << ans << '\n';
    continue;

    // SOLVING A DIFFERENT PROBLEM BELOW...

    vector<vector<int>> dp(200, vector<int>(200, 0));

    for (int i = 0; i < n; ++i) {
      int a = v[i];
      lft[a] += 1; rgt[a] -= 1;
      for (int b = 0; b < 200; ++b) {
        if (b == a) continue;
        ans = max(ans, lft[a] + rgt[b] + dp[a][b]);
        dp[b][a] = max(dp[b][a], lft[a] - lft[b]);
      }
    }

    cout << ans << '\n';
  }
  return 0;
}