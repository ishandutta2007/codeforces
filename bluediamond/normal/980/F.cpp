#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 7;
int n;
int m;
int dep[N];
int col[N];
int par[N];
int distbfs[N];
int dist[N];
int y;
vector<int> g[N];
vector<int> reps[N];
vector<int> gdown[N];
vector<int> bri[N];
void build(int a) {
  for (auto& b : g[a]) {
    if (dep[b] == -1) {
      par[b] = a;
      dep[b] = 1 + dep[a];
      build(b);
      gdown[a].push_back(b);
    }
    else {
      if (dep[b] < dep[a] - 1) {
        y++;
        int vertex = a;
        while (vertex != b) {
          col[vertex] = y;
          reps[y].push_back(vertex);
          vertex = par[vertex];
        }
        col[vertex] = y;
        reps[y].push_back(vertex);
      }
    }
  }
}
int sol[N], extra[N];
void bfs() {
  for (int i = 1; i <= n; i++) {
    distbfs[i] = -1;
  }
  for (auto& V : reps[col[1]]) {
    queue<int> q;
    q.push(V);
    distbfs[V] = 0;
    vector<int> O;
    while (!q.empty()) {
      int a = q.front();
      O.push_back(a);
      q.pop();
      for (auto& b : g[a]) {
        if (col[a] == col[1] && col[b] == col[1]) continue;

        if (distbfs[b] == -1) {
          distbfs[b] = 1 + distbfs[a];
          q.push(b);
        }
      }
    }
    reverse(O.begin(), O.end());
    for (auto& a : O) {
      dist[a] = 0;
      for (auto& b : g[a]) {
        if (col[a] == col[1] && col[b] == col[1]) continue;
        if (distbfs[b] == 1 + distbfs[a]) {
          dist[a] = max(dist[a], 1 + dist[b]);
        }
      }
    }
    sol[V] = dist[V];
  }
}
void solve(int color, int fa = -1, int value_up = -1, int father = -1) {
  vector<int> guys = reps[color];
  int y = (int)guys.size();
  if (fa != -1) {
    for (auto& V : guys) {
      dist[V] = 0;
      for (auto& Other : bri[V]) {
        if (Other != fa) {
          dist[V] = max(dist[V], 1 + dist[Other]);
        }
      }
    }
    dist[fa] = max(dist[fa], value_up);
    extra[fa] = max(extra[fa], value_up);
  }
  for (int Step = 1; Step <= 2; Step++) {
    deque<int> d;
    for (int i = 0; i < 2 * y; i++) {
      if (!d.empty() && d.front() < i - y / 2) {
        d.pop_front();
      }
      if (!d.empty()) {
        int j = d.front();
        extra[guys[i % y]] = max(extra[guys[i % y]], dist[guys[j % y]] + (i - j));
      }
      while (!d.empty()) {
        int last = d.back();
        int v_last = dist[guys[last % y]] - last;
        int v_i = dist[guys[i % y]] - i;
        if (v_i > v_last) {
          d.pop_back();
        }
        else {
          break;
        }
      }
      d.push_back(i);

    }
    reverse(guys.begin(), guys.end());
  }

  for (auto& V : guys) {
    sol[V] = max(extra[V], dist[V]);
  }
  for (auto& V : guys) {
    int sz = (int)bri[V].size();
    vector<int> pr(sz), sf(sz);
    for (int j = 0; j < sz; j++) {
      int Other = bri[V][j];
      pr[j] = sf[j] = 2 + dist[Other];
    }
    for (int j = 1; j < sz; j++) pr[j] = max(pr[j - 1], pr[j]);
    for (int j = sz - 2; j >= 0; j--) sf[j] = max(sf[j + 1], sf[j]);
    for (int j = 0; j < sz; j++) {
      int Other = bri[V][j];
      int big = 1 + extra[V];
      if (j - 1 >= 0) big = max(big, pr[j - 1]);
      if (j + 1 < sz) big = max(big, sf[j + 1]);
      solve(col[Other], Other, big, V);
    }
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    dep[i] = -1;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  build(1);
  for (int i = 1; i <= n; i++) {
    if (!col[i]) {
      col[i] = ++y;
      reps[y].push_back(i);
    }
    sol[i] = -1;
  }
  bfs();
  for (int i = 1; i <= n; i++) {
    for (auto& j : gdown[i]) {
      if (col[i] != col[j]) {
        bri[i].push_back(j);
      }
    }
  }
  solve(col[1]);
  for (int i = 1; i <= n; i++) {
      cout << sol[i] << " ";
  }
  cout << "\n";
}