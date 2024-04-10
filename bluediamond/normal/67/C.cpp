#include <bits/stdc++.h>

using namespace std;

const int N = 4000 + 7;
string s;
string t;
int n;
int m;
int c_ins;
int c_del;
int c_rep;
int c_exc;
int ant1[26];
int ant2[26];
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c_ins >> c_del >> c_rep >> c_exc >> s >> t;
  n = (int) s.size();
  m = (int) t.size();
  s = "." + s;
  t = "." + t;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = c_del * i;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = c_ins * i;
  }
  for (int i = 1; i <= n; i++) {
    for (int c = 0; c < 26; c++) {
      ant2[c] = 0;
    }
    int x = s[i] - 'a';
    for (int j = 1; j <= m; j++) {
      int y = t[j] - 'a';
      if (x == y) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min({dp[i - 1][j - 1] + c_rep, dp[i - 1][j] + c_del, dp[i][j - 1] + c_ins});
        if (ant1[y] && ant2[x]) {
          int p1 = ant1[y];
          int p2 = ant2[x];
          dp[i][j] = min(dp[i][j], dp[p1 - 1][p2 - 1] + c_del * (i - p1 - 1) + c_ins * (j - p2 - 1) + c_exc);
        }
      }
      ant2[y] = j;
    }
    ant1[x] = i;
  }
  cout << dp[n][m] << "\n";
}