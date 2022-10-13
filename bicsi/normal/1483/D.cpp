#include <bits/stdc++.h>
#define int long long 

using namespace std;
const int INF = 2e14;

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
    
  int n, m; cin >> n >> m;
  vector<vector<int>> W(n, vector<int>(n, INF));
  for (int i = 0; i < n; ++i)
    W[i][i] = 0;
  
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    W[a][b] = W[b][a] = c;
  }

  vector<vector<int>> D(W);
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

  vector<vector<int>> R(n, vector<int>(n, 0));
  int q; cin >> q;
  for (int i = 0; i < q; ++i) {
    int a, b, c; cin >> a >> b >> c; --a; --b;
    R[a][b] = R[b][a] = c;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        R[i][k] = max(R[i][k], R[i][j] - D[j][k]);
        R[k][j] = max(R[k][j], R[i][j] - D[i][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (W[i][j] <= R[i][j]) {
        ans += 1;
      }
    }
  }
  cout << ans << endl;

  return 0;
}