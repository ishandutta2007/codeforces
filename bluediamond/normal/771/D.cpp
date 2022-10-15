#include <bits/stdc++.h>
#pragma GCC target ("sse4.2")

using namespace std;

bool home = 1;
typedef long long ll;
///#define int ll
signed realMain();


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("tony_stark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

/// X = 0
/// V = 1
/// K = 2

const int N = 75 + 7;
const int INF = (int) 1e9;
int n, a[N], dp[N][N][N][3], sz[3];
string s;
vector<int> p[3];

signed realMain() {
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < N; k++) for (int t = 0; t < 3; t++) dp[i][j][k][t] = INF;
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == 'V') {
      a[i] = 1;
    }
    if (s[i - 1] == 'K') {
      a[i] = 2;
    }
    p[a[i]].push_back(i);
    sz[a[i]]++;
  }
  dp[0][0][0][0] = 0;
  for (int x = 0; x <= sz[0]; x++) {
    for (int v = 0; v <= sz[1]; v++) {
      for (int k = 0; k <= sz[2]; k++) {
        for (int t = 0; t < 3; t++) {
          if (dp[x][v][k][t] == INF) continue;
          int depe = dp[x][v][k][t];
          if (x + 1 <= sz[0]) { /// next is X
            int relax = depe, posi = p[0][x], adi = 0;
            for (int i = 0; i < x; i++) adi += (p[0][i] > posi);
            for (int i = 0; i < v; i++) adi += (p[1][i] > posi);
            for (int i = 0; i < k; i++) adi += (p[2][i] > posi);
            posi += adi;
            relax += posi - (x + v + k + 1);
            dp[x + 1][v][k][0] = min(dp[x + 1][v][k][0], relax);
          }
          if (v + 1 <= sz[1]) { /// next is V
            int relax = depe, posi = p[1][v], adi = 0;
            for (int i = 0; i < x; i++) adi += (p[0][i] > posi);
            for (int i = 0; i < v; i++) adi += (p[1][i] > posi);
            for (int i = 0; i < k; i++) adi += (p[2][i] > posi);
            posi += adi;
            relax += posi - (x + v + k + 1);
            dp[x][v + 1][k][1] = min(dp[x][v + 1][k][1], relax);
          }
          if (k + 1 <= sz[2] && t != 1) { /// next is K
            int relax = depe, posi = p[2][k], adi = 0;
            for (int i = 0; i < x; i++) adi += (p[0][i] > posi);
            for (int i = 0; i < v; i++) adi += (p[1][i] > posi);
            for (int i = 0; i < k; i++) adi += (p[2][i] > posi);
            posi += adi;
            relax += posi - (x + v + k + 1);
            dp[x][v][k + 1][2] = min(dp[x][v][k + 1][2], relax);
          }
        }
      }
    }
  }
  int ret = INF;
  for (int t = 0; t < 3; t++) {
    ret = min(ret, dp[sz[0]][sz[1]][sz[2]][t]);
  }
  cout << ret << "\n";
  return 0;
}