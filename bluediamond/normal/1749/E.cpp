#include <bits/stdc++.h>

using namespace std;

int dr[] = { 1,0,-1,0 }, dc[] = { 0,1,0,-1 };
int dr2[] = { 1,1,-1,-1 }, dc2[] = { 1,-1,1,-1 };

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif // ONLINE_JUDGE
#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<int>> okpl(n, vector<int>(m, 1));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> pr(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      assert((int)s.size() == m);
      for (int j = 0; j < m; j++) {
        char ch = s[j];
        assert(ch == '.' || ch == '#');
        if (ch == '#') {
          a[i][j] = 1;
        }
        else {
          a[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
          int rn = i + dr[k], cn = j + dc[k];
          if (0 <= rn && 0 <= cn && rn < n && cn < m && a[rn][cn]) {
            okpl[i][j] = 0;
          }
        }
      }
    }
    vector<queue<pair<int, int>>> q(2);
    int md = 0;

    for (int i = 0; i < n; i++) {
      if (okpl[i][0]) {
        dist[i][0] = !a[i][0];
        q[dist[i][0] % 2].push({ i, 0 });
        md = max(md, dist[i][0]);
      }
    }

    for (int d = 0; d <= md; d++) {
      while (!q[d % 2].empty()) {
        pair<int, int>it = q[d % 2].front();
        q[d % 2].pop();
        int r = it.first, c = it.second;
        for (int k = 0; k < 4; k++) {
          int rn = r + dr2[k], cn = c + dc2[k];
          if (0 <= rn && 0 <= cn && rn < n && cn < m && okpl[rn][cn] && dist[rn][cn] == -1) {
            pr[rn][cn] = { r, c };
            dist[rn][cn] = dist[r][c] + !a[rn][cn];
            q[dist[rn][cn] % 2].push({ rn,cn });
            md = max(md, dist[rn][cn]);
          }
        }
      }
    }
    const int INF = (int)1e9 + 7;
    int best = INF, rn, cn;
    for (int i = 0; i < n; i++) {
      if (dist[i][m - 1] != -1) {
        if (dist[i][m - 1] < best) {
          best = dist[i][m - 1];
          rn = i;
          cn = m - 1;
        }
      }
    }
    if (best == INF) {
      cout << "NO\n";
    }
    else {
      int tt = 0;
      while (1) {
        int init = a[rn][cn];
        a[rn][cn] = 1;
        if (cn == 0) {
          break;
        }
        pair<int, int> it = pr[rn][cn];
        rn = it.first;
        cn = it.second;
      }
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        string s;
        for (int j = 0; j < m; j++) {
          if (a[i][j] == 1) {
            s += '#';
          }
          else {
            s += '.';
          }
        }
        assert((int)s.size() == m);
        cout << s << "\n";
      }
    }
  }
}