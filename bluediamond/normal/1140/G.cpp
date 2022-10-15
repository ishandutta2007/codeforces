#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = (int)6e5 + 7;
const int INF = (int)1e18 + 7;
int n, change[N], print[N];

struct Q {
  int a, b, i, typea, typeb;
};

struct Edge {
  int from, to;
  int c[2];
};

struct T {
  int a;
  int dp;
};

bool operator < (T f, T s) {
  return f.dp > s.dp;
}

priority_queue<T> pq;
vector<Q> asking[N];
vector<Edge> g[N];

bool blocked[N];

int sub[N];

void dfsbuild(int a, int p = -1) {
  sub[a] = (int)asking[a].size() + 1;
  for (auto& it : g[a]) {
    int b = it.to;
    if (blocked[b] || b == p) continue;
    dfsbuild(b, a);
    sub[a] += sub[b];
  }
}

int ttl;

int fnd(int a, int p = -1) {
  int mx = ttl - sub[a];
  for (auto& it : g[a]) {
    int b = it.to;
    if (blocked[b] || b == p) continue;
    mx = max(mx, sub[b]);
  }
  if (2 * mx <= ttl) {
    return a;
  }
  for (auto& it : g[a]) {
    int b = it.to;
    if (blocked[b] || b == p) continue;
    if (sub[b] == mx) return fnd(b, a);
  }
}

vector<int> curnodes;

void place(int a, int p) {
  curnodes.push_back(a);
  for (auto& it : g[a]) {
    int b = it.to;
    if (blocked[b] || b == p) continue;
    place(b, a);
  }
}

int type[N];
int best[N][2][2];
int wh[N];

void dfs(int a, int p = -1) {
  for (int init = 0; init < 2; init++) {
    for (int now = 0; now < 2; now++) {
      best[a][init][now] = min(best[a][init][now], best[a][init][now ^ 1] + change[a]);
    }
  }
  for (auto& it : g[a]) {
    int b = it.to;
    if (blocked[b] || b == p) continue;
    for (int init = 0; init < 2; init++) {
      for (int now = 0; now < 2; now++) {
        best[b][init][now] = min(best[b][init][now], best[a][init][now] + it.c[now]);
      }
    }
    dfs(b, a);
  }
}

bool sn[N];

void rec(int a) {
  dfsbuild(a);
  ttl = sub[a];
  a = fnd(a);
  vector<vector<int>> all;
  for (auto& it : g[a]) {
    int b = it.to;
    if (!blocked[b]) {
      curnodes.clear();
      place(b, a);
      all.push_back(curnodes);
    }
  }

  for (auto& nodes : all) {
    for (auto& x : nodes) {
      type[x] = nodes[0];
      best[x][0][0] = best[x][0][1] = best[x][1][0] = best[x][1][1] = INF;
    }
  }
  best[a][0][0] = best[a][1][1] = 0;
  best[a][0][1] = best[a][1][0] = INF;

  dfs(a, -1);

  assert(!sn[a]);
  sn[a] = 1;

  type[a] = a;
  all.push_back({ a });


  for (auto& nodes : all) {
    for (auto& x : nodes) {
      for (auto& it : asking[x]) {
        int y = it.b;
        if (type[y] && type[y] != type[x]) {
          wh[it.i] = a;
          int sol = INF;
          for (int mid = 0; mid < 2; mid++) {
            sol = min(sol, best[x][mid][it.typea ^ 1] + best[y][mid][it.typeb ^ 1]);
          }
          print[it.i] = sol;
        }
      }
    }
  }


  for (auto& nodes : all) {
    for (auto& x : nodes) type[x] = 0;
  }

  blocked[a] = 1;

  for (auto& it : g[a]) {
    int b = it.to;
    if (!blocked[b]) {
      rec(b);
    }
  }
}

int specx[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)cin >> change[i];

  for (int i = 1; i < n; i++) {
    int a, b, c1, c2;
    cin >> a >> b >> c1 >> c2;
    Edge edge;
    edge.from = a;
    edge.to = b;
    edge.c[0] = c1;
    edge.c[1] = c2;
    g[a].push_back(edge);
    swap(edge.from, edge.to);
    g[b].push_back(edge);
  }

  for (int i = 1; i <= n; i++) {
    pq.push({ i, change[i] });
  }

  while (!pq.empty()) {
    int a;
    {
      auto it = pq.top();
      pq.pop();
      a = it.a;
      if (change[a] != it.dp) continue;
    }
    for (auto& it : g[a]) {
      int b = it.to, dp = change[a] + it.c[0] + it.c[1];
      if (dp < change[b]) {
        change[b] = dp;
        pq.push({ b, change[b] });
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    print[i] = -1;
    int a, b;
    cin >> a >> b;
    if (a == b) {
      print[i] = 0;
      continue;
    }
    if ((a + 1) / 2 == (b + 1) / 2) {
      print[i] = -2;
      specx[i] = (a + 1) / 2;
      continue;
    }
    asking[(a + 1) / 2].push_back({ (a + 1) / 2, (b + 1) / 2, i, a % 2, b % 2 });
  }


  rec(1);

  for (int i = 1; i <= q; i++) {
    if (print[i] == -2) {
      cout << change[specx[i]] << "\n";
      continue;
    }
    cout << print[i] << "\n";
  }

  return 0;
}