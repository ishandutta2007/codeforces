#include <bits/stdc++.h>

using namespace std;

bool home = 1;
typedef long long ll;
#define int ll
typedef long double ld;
typedef unsigned long long ull;

signed realMain();

mt19937 rng_home(0);
mt19937 rng_oj((long long) (new char));

int rng() {
  if (home) {
    return rng_home();
  } else{
    return rng_oj();
  }
}

ull rng_ull() {
  return (ull) rng() * rng() ^ ((ull) rng() * rng());
}

int rng_range(int l, int r) {
  return l + abs(rng()) % (r - l + 1);
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }
  realMain();
}

const int N = (int) 3e5 + 7;
const int INF = (int) 1e18;
int n, m, k, q, best[N], t[N], ret[N];
vector<int> nodes[N];
vector<pair<int, int>> ask[N];

struct state {
  int node;
  int best;
};

bool operator < (state a, state b) {
  return a.best > b.best;
}

struct edge {
  int from;
  int to;
  int w;
};

bool operator < (edge a, edge b) {
  return a.w < b.w;
}

int now;
vector<edge> g[N];
bool act[N];

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return t[x] = root(t[x]);
  }
}

int steps, nxt = 1;

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) {
    return;
  }
  if ((int) nodes[x].size() > (int) nodes[y].size()) {
    swap(x, y);
  }
  t[x] = y;
  for (auto &it : nodes[x]) {
    steps++;
    nodes[y].push_back(it);
    for (auto &kek : ask[it]) {
      int j = kek.first;
      int id = kek.second;
      if (ret[id] == -1 && root(j) == y) {
        ret[id] = now;
      }
    }
  }
  nodes[x].clear();
}

signed realMain() {
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    g[x].push_back({x, y, z});
    g[y].push_back({y, x, z});
  }
  for (int i = 1; i <= q; i++) {
    int x, y;
    cin >> x >> y;
    ask[x].push_back({y, i});
    ask[y].push_back({x, i});
    ret[i] = -1;
  }
  priority_queue<state> pq;
  for (int i = k + 1; i <= n; i++) {
    best[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    pq.push({i, 0});
  }
  while (!pq.empty()) {
    auto it = pq.top();
    pq.pop();
    if (best[it.node] != it.best) {
      continue;
    }
    int a = it.node;
    for (auto &edg : g[a]) {
      int b = edg.to, relax = edg.w + best[a];
      if (relax < best[b]) {
        best[b] = relax;
        pq.push({b, best[b]});
      }
    }
  }
  vector<edge> edges;
  for (int i = 1; i <= n; i++) {
    for (auto &it : g[i]) {
      int j = it.to, w = it.w;
      if (i > j) continue;
      edges.push_back({i, j, best[i] + best[j] + w});
    }
  }
  sort(edges.begin(), edges.end());
  for (int i = 1; i <= n; i++) {
    t[i] = i;
    if (i <= k) {
      nodes[i] = {i};
    }
  }
  for (auto &it : edges) {
    now = it.w;
    unite(it.to, it.from);
  }
  for (int i = 1; i <= q; i++) {
    cout << ret[i] << "\n";
  }
  return 0;
}