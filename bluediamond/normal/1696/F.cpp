/// 483 -> 484
#include <bits/stdc++.h>

using namespace std;

mt19937 rng((long long) (new char));

const int N = 100 + 7;
int n;
bool eq[N][N][N];
int ls[N][N], tt;
vector<int> g[N];
int d[N][N];
vector<int> guys[N][N];

vector<pair<int, int>> edges;

void addEdge(int a, int b) {
  assert(ls[a][b] == ls[b][a]);
  if (ls[a][b] != tt) {
    edges.push_back({a, b});
    ls[a][b] = ls[b][a] = tt;
  }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int Tests;
  cin >> Tests;
  for (int tc = 1; tc <= Tests; tc++) {
    cin >> n;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= n + 1; j++) {
        for (int k = 0; k <= n + 1; k++) {
          eq[i][j][k] = 0;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        string s;
        cin >> s;
        assert((int) s.size() == n);
        for (int k = 1; k <= n; k++) {
          char ch = s[k - 1];
          assert(ch == '0' || ch == '1');
          eq[i][j][k] = eq[j][i][k] = (ch == '1');
        }
      }
    }

    tt++;
    bool found = 0;
    for (int some_edge_a = 1; some_edge_a <= n && !found; some_edge_a++) {
      for (int some_edge_b = some_edge_a + 1; some_edge_b <= n && !found; some_edge_b++) {

        edges.clear();
        addEdge(some_edge_a, some_edge_b);
        if (edges.empty()) {
          continue;
        }
        for (int i = 0; i < (int) edges.size() && (int) edges.size() <= n; i++) {
          int a = edges[i].first, b = edges[i].second;
          for (int c = 1; c <= n; c++) {
            if (eq[a][c][b]) addEdge(c, b);
            if (eq[b][c][a]) addEdge(c, a);
          }
        }
        if ((int) edges.size() != n - 1) {
          continue;
        }
        for (int i = 1; i <= n; i++) {
          g[i].clear();
        }
        for (auto &it : edges) {
          g[it.first].push_back(it.second);
          g[it.second].push_back(it.first);
        }
        bool ok = 1;
        for (int r = 1; r <= n && ok; r++) {
          for (int i = 1; i <= n; i++) {
            d[r][i] = -1;
          }
          d[r][r] = 0;
          queue<int> q;
          q.push(r);
          while (!q.empty()) {
            int a = q.front();
            q.pop();
            for (auto &b : g[a]) {
              if (d[r][b] == -1) {
                d[r][b] = 1 + d[r][a];
                q.push(b);
              }
            }
          }
          for (int i = 1; i <= n; i++) {

            ok &= (d[r][i] != -1);
          }
        }
        /// cout << some_edge_a << " and " << some_edge_b << " : " << ok << "\n";
        for (int x = 1; x <= n && ok; x++) {
          for (int y = x + 1; y <= n && ok; y++) {
            for (int z = 1; z <= n && ok; z++) {
              ok &= ((d[x][z] == d[y][z]) == (eq[x][y][z]));
            }
          }
        }
        if (!ok) {
          continue;
        }
        found = 1;
        cout << "Yes\n";
        for (auto &it : edges) {
          cout << it.first << " " << it.second << "\n";
        }
      }
    }
    if (!found) {
      cout << "No\n";

    }
  }

}