#include <bits/stdc++.h>

using namespace std;

bool home = 1;

const int N = 3333;
const int INF = 1 << 30;
int n, b[N], dp[N][N];

void minop(int &a, int b) {
  a = min(a, b);
}

vector<int> w[N];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("iron_man.txt","r",stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      w[i].clear();
    }
    int y = 0;
    for (int i = 1; i <= n; i++) {
      int c;
      cin >> c;
      if (y && c == b[y]) continue;
      b[++y] = c;
      w[c].push_back(y);
    }
    n = y;
    for (int l = n; l >= 1; l--) {
      dp[l][l] = 0;
      for (int r = l + 1; r <= n; r++) {
        dp[l][r] = INF;
        minop(dp[l][r], 1 + dp[l + 1][r]);
        for (auto &k : w[b[l]]) {
          if (l + 1 <= k && k <= r && b[l] == b[k]) {
            dp[l][r] = min(dp[l][r], 1 + dp[l + 1][k - 1] + dp[k][r]);
          }
        }
      }
    }
    cout << dp[1][n] << "\n";
  }


  return 0;
}