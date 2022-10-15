#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = 998244353;
const int N = 3000 + 7;
string s;
string t;
int n;
int m;
int sol;
int dp[N][N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> t;
  n = (int) s.size();
  m = (int) t.size();
  s = " " + s;
  t = " " + t;
  for (int i = m; i <= n; i++) {
    dp[i][1] = (s[i] == t[1]);
    dp[i][0] = (i > m || s[i] == t[m]);
  }
  for (int i = n; i > 1; i--) {
    for (int j = 0; j <= n - i + 1; j++) {
      dp[i - 1][j + 1] = (dp[i - 1][j + 1] + dp[i][j] * (j + 1 > m || s[i - 1] == t[j + 1])) % M;
      dp[i - 1][j] = (dp[i - 1][j] + dp[i][j] * (j + i - 1 > m || s[i - 1] == t[j + i - 1])) % M;
    }
  }
  int sol = 0;
  for (int i = 0; i <= n; i++) {
    sol = (sol + dp[1][i]) % M;
  }
  cout << sol << "\n";
}