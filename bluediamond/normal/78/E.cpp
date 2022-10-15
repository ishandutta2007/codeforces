#include <bits/stdc++.h>

using namespace std;

class dinic {
  struct Edge {
    int to, flow, next;
  };
  vector <Edge> edges;
  vector <int> adia, act, h;
  int S, D;

  bool bfs() {
    fill(h.begin(), h.end(), -1);
    h[S] = 0;
    vector <int> q = { S };

    for (int it = 0; it < (int)q.size(); it++) {
      int nod = q[it];
      for (int i = adia[nod]; i != -1; i = edges[i].next)
        if (h[edges[i].to] == -1 && edges[i].flow)
          h[edges[i].to] = 1 + h[nod], q.push_back(edges[i].to);
    }

    return h[D] != -1;
  }

  int dfs(int nod, int cap_max) {
    if (cap_max == 0 || nod == D)
      return cap_max;

    while (act[nod] != -1) {
      Edge& e = edges[act[nod]];
      int d;
      if (h[e.to] == 1 + h[nod] && (d = dfs(e.to, min(cap_max, e.flow))) != 0) {
        e.flow -= d;
        edges[act[nod] ^ 1].flow += d;
        return d;
      }
      act[nod] = edges[act[nod]].next;
    }
    return 0;
  }

public:
  dinic(int n, int S, int D) : adia(n + 1, -1), h(n + 1), S(S), D(D) { }

  int flow() {
    int ans = 0, d;
    while (bfs()) {
      act = adia;
      while ((d = dfs(S, 1e9)) != 0)
        ans += d;
    }
    return ans;
  }

  void add(int a, int b, int c) {
    edges.push_back({ b, c, (int)edges.size() });
    swap(edges.back().next, adia[a]);
    edges.push_back({ a, 0, (int)edges.size() });
    swap(edges.back().next, adia[b]);
  }
};

const int N = 10 + 7;
const int INF = (int) 1e9;
int n;
int t;
int a[N][N];
int b[N][N];
int ord[N][N];
int d[N][N][N][N];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

bool oke(int r, int c) {
  return (1 <= r && 1 <= c && r <= n && c <= n && a[r][c] >= 0);
}

struct T {
  int r;
  int c;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      ord[i][j] = (i - 1) * n + j;
      if (s[j - 1] == 'Z') {
        a[i][j] = -2;
      }
      if (s[j - 1] == 'Y') {
        a[i][j] = -1;
      }
      if (a[i][j] == 0) {
        a[i][j] = s[j - 1] - '0';
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= n; j++) {
      b[i][j] = s[j - 1] - '0';
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= n; c++) {
          d[i][j][r][c] = INF;
        }
      }
    }
  }
  int rx;
  int cx;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == -2) {
        rx = i;
        cx = j;
        d[i][j][i][j] = 0;
        queue<T> q;
        q.push({i, j});
        while (!q.empty()) {
          int r = q.front().r;
          int c = q.front().c;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int rn = r + dr[k];
            int cn = c + dc[k];
            if (oke(rn, cn) && d[i][j][rn][cn] == INF) {
              d[i][j][rn][cn] = 1 + d[i][j][r][c];
              q.push({rn, cn});
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] >= 0) {
        d[i][j][i][j] = 0;
        queue<T> q;
        q.push({i, j});
        while (!q.empty()) {
          int r = q.front().r;
          int c = q.front().c;
          q.pop();
          for (int k = 0; k < 4; k++) {
            int rn = r + dr[k];
            int cn = c + dc[k];
            if (oke(rn, cn) && d[i][j][rn][cn] == INF && 1 + d[i][j][r][c] <= d[rx][cx][rn][cn]) {
              d[i][j][rn][cn] = 1 + d[i][j][r][c];
              if (1 + d[i][j][r][c] != d[rx][cx][rn][cn]) {
                q.push({rn, cn});
              }
            }
          }
        }
      }
    }
  }
  dinic di(2 * n * n + 2, 1, 2 * n * n + 2);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > 0) {
        di.add(1, ord[i][j] + 1, a[i][j]);
      }
      if (a[i][j] >= 0 && b[i][j] > 0) {
        di.add(ord[i][j] + n * n + 1, 2 * n * n + 2, b[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] > 0) {
        for (int r = 1; r <= n; r++) {
          for (int c = 1; c <= n; c++) {
            if (a[r][c] >= 0 && b[r][c] > 0 && d[i][j][r][c] <= t) {
              di.add(ord[i][j] + 1, ord[r][c] + n * n + 1, INF);
            }
          }
        }
      }
    }
  }
  cout << di.flow() << "\n";
}