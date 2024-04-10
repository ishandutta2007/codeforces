#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll

signed realMain();

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int undef = 12345;
int spre[11][11], dp[11], nw[11], ret;

signed realMain() {
  for (int i = 0; i < 11; i++) for (int j = 0; j < 11; j++) spre[i][j] = undef;
  int bef = 9;
  for (int i = 1; i <= 11; i++) {
    for (int j = 0; j < i % 11; j++) {
      spre[i % 11][j] = (++bef) % 11;
    }
  }
  string s;
  cin >> s;
  for (auto &ch : s) {
    int dig = ch - '0';
    for (int j = 0; j < 11; j++) nw[j] = 0;
    for (int j = 0; j < 11; j++) {
      if (spre[j][dig] != undef) nw[spre[j][dig]] += dp[j];
    }
    if (dig > 0) nw[dig]++;
    for (int j = 0; j < 11; j++) {
      dp[j] = nw[j];
      ret += dp[j];
    }
  }
  cout << ret << "\n";
  return 0;
}