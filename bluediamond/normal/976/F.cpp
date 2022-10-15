#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int id[2007][2007];
int cntt[2007];
int cnt[2007];
vector<int> ids[2007];
int yy;

struct flow {
  struct E {
    int to;
    int cap;
  };
  const int INF = (int) 1e9;
  int n;
  int n1;
  int n2;
  int m;
  vector<vector<int>> g;
  vector<E> edges;
  vector<int> level;
  vector<int> pos;
  vector<int> loli;
  void init(int nn) {
    n = nn;
    g.clear();
    edges.clear();
    level.clear();
    pos.clear();
    level.resize(n + 1);
    g.resize(n + 1);
    pos.resize(n + 1);
    for (int i = 0; i <= yy; i++) {
      cnt[i] = 0;
    }
  }
  void add(int a, int b, int c, int keki) {
    g[a].push_back((int) edges.size());
    g[b].push_back((int) edges.size() + 1);
    loli.push_back(keki);
    loli.push_back(0);
    edges.push_back({b, c});
    edges.push_back({a, 0});
  }
  int dfs(int a, int cap) {
    if (a == n || cap == 0) {
      return cap;
    }
    while (pos[a] < (int) g[a].size()) {
      int i = g[a][pos[a]++];
      int b = edges[i].to;
      int c = edges[i].cap;
      if (c == 0 || level[b] != level[a] + 1) {
        continue;
      }
      int x = dfs(b, min(cap, c));
      if (x == 0) {
        continue;
      }
      if (i % 2 == 0) {
        cnt[loli[i]] += x;
      } else {
        cnt[loli[i ^ 1]] -= x;
      }
      edges[i].cap -= x;
      edges[i ^ 1].cap += x;
      return x;
    }
    return 0;
  }
  int get() {
    int ret = 0;
    while (1) {
      level[1] = pos[1] = 0;
      for (int i = 2; i <= n; i++) {
        level[i] = -1;
        pos[i] = 0;
      }
      queue<int> q;
      q.push(1);
      while (!q.empty()) {
        int a = q.front();
        q.pop();
        for (auto &i : g[a]) {
          int b = edges[i].to;
          int c = edges[i].cap;
          if (c > 0 && level[b] == -1) {
            level[b] = 1 + level[a];
            q.push(b);
          }
        }
      }
      if (level[n] == -1) {
        break;
      }
      while (1) {
        int x = dfs(1, INF);
        if (x == 0) {
          break;
        }
        ret += x;
      }
    }
    return ret;
  }
  void print() {
    cout << m - get() << " ";
    for (int i = 1; i <= yy; i++) {
      for (int j = 0; j < cntt[i] - cnt[i]; j++) {
        cout << ids[i][j] << " ";
      }
    }
    cout << "\n";
  }
};

const int N = 2000 + 7;
int n1;
int n2;
int m;
int x[N];
int y[N];
int d1[N];
int d2[N];
bool lmao[N];
int wx[N];
int wy[N];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n1 >> n2 >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
    if (id[x[i]][y[i]] == 0) {
      id[x[i]][y[i]] = ++yy;
      wx[yy] = x[i];
      wy[yy] = y[i];
    }
    cntt[id[x[i]][y[i]]]++;
    ids[id[x[i]][y[i]]].push_back(i);
    d1[x[i]]++;
    d2[y[i]]++;
  }
  int degmin = d1[1];
  for (int i = 1; i <= n1; i++) {
    degmin = min(degmin, d1[i]);
  }
  for (int i = 1; i <= n2; i++) {
    degmin = min(degmin, d2[i]);
  }
  cout << "0\n";
  for (int d = 1; d <= degmin; d++) {
    flow f;
    f.n1 = n1;
    f.n2 = n2;
    f.m = m;
    f.init(2 + n1 + n2);
    for (int i = 1; i <= n1; i++) {
      f.add(1, 1 + i, d1[i] - d, 0);
    }
    for (int i = 1; i <= n2; i++) {
      f.add(1 + n1 + i, 2 + n1 + n2, d2[i] - d, 0);
    }
    for (int i = 1; i <= yy; i++) {
      f.add(1 + wx[i], 1 + n1 + wy[i], cntt[i], i);
    }
    f.print();
  }
}