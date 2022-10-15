#include <bits/stdc++.h>

using namespace std;

const int N = 3000 + 7;
const int K = 13;
const int Q = (int) 4e5 + 7;
int n, m, q, Answer[Q];
int nxt[K][N];
bool ajung[N][N];
vector<int> g[N];
vector<vector<int>> query[N];

signed main(){
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
  }

  for (int go = 1; go <= n; go++) {
    ajung[go][go] = 1;
    queue<int> q;
    q.push(go);
    while (!q.empty()) {
      int a = q.front();
      q.pop();
      for (auto &b : g[a]) {
        if (!ajung[go][b]) {
          ajung[go][b] = 1;
          q.push(b);
        }
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    int s, t, x;
    cin >> s >> t >> x;
    query[t].push_back({s, x, i});
  }

  for (int t = 1; t <= n; t++) {
    if (query[t].empty()) continue;
    for (int x = 1; x <= n; x++) {
      nxt[0][x] = -1;
      for (auto &y : g[x]) {
        if (ajung[y][t]) {
          if (nxt[0][x] == -1 || y < nxt[0][x]) {
            nxt[0][x] = y;
          }
        }
      }
      if (nxt[0][x] == -1) {
        nxt[0][x] = x;
      }
    }
    nxt[0][t] = -1;
    for (int k = 1; k < K; k++) {
      for (int x = 1; x <= n; x++) {
        if (nxt[k - 1][x] == -1) {
          nxt[k][x] = -1;
        } else {
          nxt[k][x] = nxt[k - 1][nxt[k - 1][x]];
        }
      }
    }
    for (auto &it : query[t]) {
      int s = it[0], Jumps = it[1] - 1, Index = it[2];
      if (nxt[K - 1][s] != -1) { /// Infinite cycle
        Answer[Index] = -1;
        continue;
      }
      int Position = s;
      for (int k = 0; k < K && Position != -1; k++) {
        if (Jumps & (1 << k)) {
          Position = nxt[k][Position];
        }
      }
      Answer[Index] = Position;
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << Answer[i] << "\n";
  }





  return 0;
}