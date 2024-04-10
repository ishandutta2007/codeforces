#include <bits/stdc++.h>
// #define int long long 

using namespace std;
const int INF = 1e9 + 2000;
//int dp[1201][600][600];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m; cin >> n >> m;
  vector<vector<int>> C(n, vector<int>(n, INF));
  for (int i = 0; i < m; ++i) {
    int a, b, c; cin >> a >> b >> c;
    C[a][b] = c;
  }
  /*
  memset(dp, 0x3f, sizeof(dp));
  for (int del = 2 * n - 1; del >= 0; --del) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dp[del][i][j] = 1 + dp[del + 1][i][j];
    for (int i = 0; i < n; ++i)
      dp[del][i][i] = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int jp = (j + 3 * n - del) % n;
        dp[del][i][j] = min(dp[del][i][j], C[i][jp]);
      }
  }
  */
  for (int i = 0; i < n; ++i) {
    vector<int> dist(n, INF), aux(n);
    vector<bool> seen(n, false);
    dist[i] = 0;
    for (int it = 0; it < n; ++it) {
      int node = -1;
      for (int i = 0; i < n; ++i) {
        if (seen[i]) continue;
        if (node == -1 || dist[node] > dist[i])
          node = i;
      }
      assert(node != -1 && !seen[node]);
      seen[node] = true;
        
      int d = dist[node];
      for (int vec = 0; vec < n; ++vec)
        aux[(vec + d) % n] = d + C[node][vec];
      for (int it = 1; it <= 2 * n; ++it) 
        aux[it % n] = min(aux[it % n], aux[(it - 1) % n] + 1);
      for (int vec = 0; vec < n; ++vec)
        dist[vec] = min(dist[vec], aux[vec]);
    }
    for (int j = 0; j < n; ++j)
      cout << dist[j] << " ";
    cout << '\n';
  }

  return 0;
}