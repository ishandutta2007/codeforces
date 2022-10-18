#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 7010;

int n;
vector<int> g[2];
int deg[2][MAX_N], dp[2][MAX_N];

void dfs(int id, int pos, int state) {
  if (dp[id][pos] != -1) return;
  
  dp[id][pos] = state;
  
  if (state == 0) {
    for (int i = 0; i < g[id ^ 1].size(); ++i) {
      int pre = (pos - g[id ^ 1][i] + n) % n;
      if (pre == 0) continue;
      
      dfs(id ^ 1, pre, 1);
    }
  } else {
    for (int i = 0; i < g[id ^ 1].size(); ++i) {
      int pre = (pos - g[id ^ 1][i] + n) % n;
      if (pre == 0) continue;
      
      if (--deg[id ^ 1][pre] == 0) {
        dfs(id ^ 1, pre, 0);
      }
    }
    
  }
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < 2; ++i) {
      int cnt;
      cin >> cnt;
      g[i].clear();
      for (int j = 0; j < cnt; ++j) {
        int x;
        cin >> x;
        g[i].push_back(x);
      }
      
      for (int j = 1; j < n; ++j) deg[i][j] = g[i].size();
    }
    
    memset(dp, -1, sizeof (dp));
    dfs(0, 0, 0);
    dfs(1, 0, 0);
    
    string s[3] = {"Loop", "Lose", "Win"};
    for (int i = 0; i < 2; ++i) {
      for (int j = 1; j < n; ++j) {
        cout << s[dp[i][j] + 1] << (j + 1 == n ? '\n' : ' ');
      }
    }
  }
  return 0;
}