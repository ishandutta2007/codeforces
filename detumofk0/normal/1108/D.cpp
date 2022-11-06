#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
	
  int n;
  string s;

  cin >> n >> s;

  for(auto &c : s) {
    if(c == 'B') c = 0;
    if(c == 'G') c = 1;
    if(c == 'R') c = 2;
  }

  vector < vector < int > > dp(n, vector < int >(3, n + 1)), trace = dp;

  dp[0][0] = dp[0][1] = dp[0][2] = 1;
  dp[0][s[0]] = 0;

  for(int i = 0; i < n - 1; ++i) {
    for(int c = 0; c < 3; ++c) {
      for(int nxt = 0; nxt < 3; ++nxt) {
        if(c == nxt) continue;
        if(dp[i + 1][nxt] > dp[i][c] + (s[i + 1] != nxt)) {
          trace[i + 1][nxt] = c;
          dp[i + 1][nxt] = dp[i][c] + (s[i + 1] != nxt);
        }
      }
    }
  }

  int x = 0;
  for(int i = 1; i < 3; ++i) if(dp.back().at(i) < dp.back().at(x)) x = i;

  cout << dp.back().at(x) << endl;
  string ans = s;

  for(int i = n - 1; i >= 0; --i) {
    if(x == 0) ans[i] = 'B';
    if(x == 1) ans[i] = 'G';
    if(x == 2) ans[i] = 'R';
    x = trace[i][x];
  }

  cout << ans;

  return 0;
}