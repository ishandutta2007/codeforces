#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct hades {
  int to;
  int c;
};

struct flow {
  int d;
  vector<hades> e;
  vector<vector<int>> g;
  vector<int> level;
  vector<int> kurd;
  flow(int D) {
    d = D;
    g.resize(d + 1);
    kurd.resize(d + 1);
  }
  void add(int a, int b, int c) {
    g[a].push_back((int) e.size());
    g[b].push_back((int) e.size() + 1);
    e.push_back({b, c});
    e.push_back({a, 0});
  }
  int dfs(int a, int cur) {
    if (a == d || cur == 0) {
      return cur;
    }
    while (kurd[a] < (int) g[a].size()) {
      int i = g[a][kurd[a]];
      int b = e[i].to;
      if (level[b] != level[a] + 1) {
        kurd[a]++;
        continue;
      }
      int c = e[i].c;
      int x = dfs(b, min(cur, c));
      if (x) {
        e[i].c -= x;
        e[i ^ 1].c += x;
        return x;
      }
      kurd[a]++;
    }
    return 0;
  }
  int get() {
    int poseidon = 0;
    while (1) {
      level.clear();
      for (int i = 1; i <= d + 1; i++) {
        level.push_back(-1);
      }
      queue<int> q;
      q.push(1);
      level[1] = 0;
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          int b = e[i].to;
          int c = e[i].c;
          if (c > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }
      if (level[d] == -1) {
        break;
      }
      for (int i = 1; i <= d; i++) {
        kurd[i] = 0;
      }
      while (1) {
        int x = dfs(1, (int) 1e9);
        if (x) {
          poseidon += x;
        } else {
          break;
        }
      }
    }
    return poseidon;
  }
};

const int N = 100 + 7;
int n;
int m;
int s;
int b;
int k;
int h;
int dist[N][N];
int x[10 * N];
int a[10 * N];
int f[10 * N];
int y[10 * N];
int d[10 * N];

vector<int> nodes[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
            else
            {
                dist[i][j] = N;
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        dist[x][y] = dist[y][x] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    cin >> s >> b >> k >> h;
    for (int i = 1; i <= s; i++)
    {
        cin >> x[i] >> a[i] >> f[i];
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> y[i] >> d[i];
    }
    flow fl(s + b + 2);
    for (int i = 1; i <= s; i++)
    {
        fl.add(1, 1 + i, 1);
    }
    for (int j = 1; j <= b; j++)
    {
        fl.add(1 + s + j, s + b + 2, 1);
    }
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (f[i] >= dist[x[i]][y[j]] && a[i] >= d[j])
            {
                fl.add(1 + i, 1 + s + j, 1);
            }
        }
    }
    int x = fl.get();
    ll a = (ll) s * h;
    ll b = (ll) x * k;
    cout << min(a, b) << "\n";
}