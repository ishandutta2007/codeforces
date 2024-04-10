#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 500000 + 7;
int n;
int m;
int k;
int t[N];
int h[N];
int v[N];
int c[N];
bool bipartite;
bool good_color[N];
vector<pair<int, int>> same[N];

struct Data {
  int x;
  int hx;
  int vx;
  int y;
  int hy;
  int vy;
  bool bipartite;
};

vector<Data> memory;

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return root(t[x]);
  }
}

int color(int x) {
  if (t[x] == x) {
    return v[x];
  } else {
    return v[x] ^ color(t[x]);
  }
}

void unite(int x, int y) {
  int a = x;
  int b = y;
  x = root(x);
  y = root(y);
  memory.push_back({x, h[x], v[x], y, h[y], v[y], bipartite});
  if (x == y) {
    if (color(a) == color(b)) {
      bipartite = 0;
    }
    return;
  }
  if (h[x] > h[y]) {
    swap(x, y);
  }
  t[x] = y;
  h[y] += (h[x] == h[y]);
  if (color(a) == color(b)) {
    v[x] ^= 1;
  }
  assert(color(a) != color(b));
}

void undo() {
  assert(!memory.empty());
  Data it = memory.back();
  memory.pop_back();
  t[it.x] = it.x;
  h[it.x] = it.hx;
  v[it.x] = it.vx;
  t[it.y] = it.y;
  h[it.y] = it.hy;
  v[it.y] = it.vy;
  bipartite = it.bipartite;
}

struct Edge {
  int x;
  int y;
};

bool operator < (Edge a, Edge b) {
  return make_pair(c[a.x], c[a.y]) < make_pair(c[b.x], c[b.y]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  bipartite = 1;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    t[i] = i;
    v[i] = 0;
  }
  vector<Edge> edges, edges2;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    if (c[x] == c[y]) {
      same[c[x]].push_back({x, y});
      continue;
    }
    edges.push_back({x, y});
  }
  int good_colors = 0;
  for (int c = 1; c <= k; c++) {
    for (int i = 0; i < (int) same[c].size(); i++) {
      unite(same[c][i].first, same[c][i].second);
    }
    good_color[c] = bipartite;
    good_colors += good_color[c];
    for (int i = 0; i < (int) same[c].size(); i++) {
      undo();
    }
  }
  for (int c = 1; c <= k; c++) {
    if (good_color[c]) {
      for (int i = 0; i < (int) same[c].size(); i++) {
        unite(same[c][i].first, same[c][i].second);
      }
    }
  }
  int bad = 0;
  for (auto &it : edges) {
    if (good_color[c[it.x]] && good_color[c[it.y]]) {
      if (c[it.x] > c[it.y]) {
        swap(it.x, it.y);
      }
      edges2.push_back(it);
    }
  }
  edges = edges2;
  sort(edges.begin(), edges.end());
  int l = 0;
  while (l < (int) edges.size()) {
    int r = l;
    while (r + 1 < (int) edges.size() && c[edges[r].x] == c[edges[r + 1].x] && c[edges[r].y] == c[edges[r + 1].y]) {
      r++;
    }
    for (int j = l; j <= r; j++) {
      unite(edges[j].x, edges[j].y);
    }
    if (bipartite == 0) {
      bad++;
    }
    for (int j = l; j <= r; j++) {
      undo();
    }
    l = r + 1;
  }
  ll sol = (ll) good_colors * (good_colors - 1) / 2 - bad;
  cout << sol << "\n";
}
/**
if a certain color is bad, you literally don't care about it because in every pair it will be bad
for now on, let's only focus on good colors
how to check if the pair c1, c2 is bipartite
(1) if they don't have edges, it will be bipartite
(2) if they do have edges we try them
**/