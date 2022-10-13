#include <bits/stdc++.h>

using namespace std;

tuple<int, int, int> dp[500000][4];

int main() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> sp(n);
   
  auto check = [&](string s) {
    int cnt = 0, mincnt = 0, minfrq = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '(') cnt += 1;
      else cnt -= 1;
      if (mincnt > cnt) {
        mincnt = cnt;
        minfrq = 0;
      }
      if (mincnt == cnt) ++minfrq;
      sp[i] = cnt;
    }
    if (cnt != 0) {
      cout << 0 << endl << 1 << " " << 1 << endl;
      exit(0);
    }
    return minfrq;
  };
  
  tuple<int, int, int> best = {check(s), 0, 0};

  // cerr << best << endl;
  int minsp = *min_element(sp.begin(), sp.end());
  minsp -= 2;
  for (int it = 0; it < 5; ++it) {
    for (int i = 0; i <= n; ++i) 
      dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = {-1e9, -1e9, -1e9};
    dp[0][0] = {0, -1, -1};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 4; ++j) {
        if (get<0>(dp[i][j]) < 0) continue;
        int nowsp = sp[i];
        if (j == 1) nowsp -= 2;
        if (j == 2) nowsp += 2;
        if (nowsp < minsp) continue;
        auto now = dp[i][j];
        get<0>(now) += (nowsp == minsp);
        dp[i + 1][j] = max(dp[i + 1][j], now);
      }
      // continue;
      for (int j = 0; j < 3; ++j) {
        if (get<0>(dp[i][j]) < 0) continue;
        int nj = -1;
        if (s[i] == '(') {
          if (j == 1) continue;
          nj = (j == 0 ? 1 : 3);
        }
        if (s[i] == ')') {
          if (j == 2) continue;
          nj = (j == 0 ? 2 : 3);
        }
        int nowsp = sp[i];
        if (nj == 1) nowsp -= 2;
        if (nj == 2) nowsp += 2;
        if (nowsp < minsp) continue;
        auto now = dp[i][j];
        get<0>(now) += (nowsp == minsp);
        if (s[i] == '(') {
          // cerr << get<1>(now) << endl;
          assert(get<1>(now) == -1);
          get<1>(now) = i;
        }
        else {
          // cerr << get<2>(now) << endl;
          assert(get<2>(now) == -1);
          get<2>(now) = i;
        }
        dp[i + 1][nj] = max(dp[i + 1][nj], now);
      }
    }
    // cerr << minsp << ": " << get<0>(dp[n][3]) << " " << get<1>(dp[n][3]) << " " << get<2>(dp[n][3]) << endl;
    best = max(best, dp[n][3]);
    minsp += 1;
  }

  cout << get<0>(best) << "\n" << get<1>(best) + 1 << " " << get<2>(best) + 1 << endl;
  
  return 0;
}