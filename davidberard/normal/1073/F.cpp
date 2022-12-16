#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 200200;
int par[N];
int dep[N];
bool bad[N];
vector<pair<int, int>> deepest[N];
vector<int> adj[N];
int n;

template<typename T>
struct Max2 {
  pair<T, int> first, second;
  Max2(T init) : first(init, -1), second(init, -1) {}
  void insert(T v, int idx) {
    if (v > first.first) {
      second = first;
      first = {v, idx};
    } else if (v > second.first) {
      second = {v, idx};
    }
  }
  T other(int idx) {
    if (first.second == idx) {
      return second.first;
    }
    return first.first;
  }
};

void dfs(int u, int p, int d) {
  par[u] = p;
  dep[u] = d;
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, d+1);
  }
}

pair<int, int> farthest(int u, int p, int d) {
  if (bad[u]) {
    return {-1, -1};
  }
  pair<int, int> ans = {d, u};
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    ans = max(ans, farthest(v, u, d+1));
  }
  return ans;
}

void solve(int u, int v) {
  //cerr << "! " << u << " " << v << endl;
  sort(deepest[u].rbegin(), deepest[u].rend());
  sort(deepest[v].rbegin(), deepest[v].rend());
  int x1 = deepest[u][0].second;
  int x2 = deepest[v][0].second;
  int y1 = deepest[u][1].second;
  int y2 = deepest[v][1].second;
  cout << x1 << " " << x2 << "\n";
  cout << y1 << " " << y2 << "\n";
}

tuple<int, int, int> dfs2(int u, int p, int d) {
  tuple<int, int, int> ans = {0, 0, 0};
  if (deepest[u].size() >= 2) {
    ans = {d, deepest[u][0].first + deepest[u][1].first, u};
  }
  for (auto& v : adj[u]) {
    if (v == p) {
      continue;
    }
    ans = max(ans, dfs2(v, u, d+1));
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i=0; i<n-1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int r = 0;
  for (int u=1; u<=n; ++u) {
    if (adj[u].size() > 2) {
      r = u;
    }
  }
  dfs(r, 0, 1);
  for (int u=1; u<=n; ++u) {
    if (adj[u].size() != 1) {
      continue;
    }
    int v = u;
    while (adj[v].size() < 3) {
      //cerr << " BAD " << v << endl;
      bad[v] = true;
      v = par[v];
    }
    deepest[v].push_back({dep[u] - dep[v], u});
  }
  int w1 = farthest(r, 0, 0).second;
  int w2 = farthest(w1, 0, 0).second;
  dfs(w1, 0, 0);
  vector<int> path;
  path.push_back(w2);
  int x = w2;
  while (x != w1) {
    x = par[x];
    path.push_back(x);
  }
  
  r = path[path.size()/2];
  dfs(r, 0, 0);
  vector<int> ch;
  for (auto& v : adj[r]) {
    if (bad[v]) {
      continue;
    }
    //cerr << " . " << v << endl;
    ch.push_back(v);
  }
  if (ch.size() == 1) {
    solve(ch[0], r);
    return 0;
  }
  for (int i=1; i<=n; ++i) {
    sort(deepest[i].rbegin(), deepest[i].rend());
  }
  Max2<tuple<int, int, int>> mx({-1, -1, -1});
  for (auto& v : ch) {
    mx.insert(dfs2(v, r, 1), v);
  }
  solve(get<2>(mx.first.first), get<2>(mx.second.first));
  return 0;
}