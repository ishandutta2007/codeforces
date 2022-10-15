#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct E {
  int to;
  int l;
  bool cycle;
};

bool operator < (E a, E b) {
  return a.to < b.to;
}

const int N = (int) 2e5 + 7;
const ll INF = (ll) 1e18;
int n;
int nodes[N];
int dep[N];
ll maxs[N];
ll diam[N];
bool vis[N];
bool on_cycle[N];
vector<E> g[N];
vector<int> cycle;

int get_len(int x, int y) {
  int l = 0, r = (int) g[x].size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (g[x][m].to == y) {
      return g[x][m].l;
    }
    if (g[x][m].to < y) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  cout << "error on get_len(" << x << ", " << y << ")\n";
  exit(0);
}

void clr() {
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
  }
}

void detect_cycle(int a, int level) {
  vis[a] = 1;
  dep[a] = level;
  nodes[level] = a;
  for (auto &it : g[a]) {
    int b = it.to;
    if (vis[b] == 0) {
      detect_cycle(b, level + 1);
      continue;
    }
    if (dep[b] >= dep[a] - 1) {
      continue;
    }
    for (int j = dep[b]; j <= dep[a]; j++) {
      cycle.push_back(nodes[j]);
      on_cycle[nodes[j]] = 1;
    }
  }
}

void in_tree(int a) {
  vis[a] = 1;
  for (auto &it : g[a]) {
    int b = it.to;
    if (it.cycle || vis[b] == 1) {
      continue;
    }
    in_tree(b);
    diam[a] = max(diam[a], maxs[a] + maxs[b] + it.l);
    diam[a] = max(diam[a], diam[b]);
    maxs[a] = max(maxs[a], maxs[b] + it.l);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y, l;
    cin >> x >> y >> l;
    g[x].push_back({y, l, 0});
    g[y].push_back({x, l, 0});
  }
  for (int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }

  detect_cycle(1, 0);
  for (int i = 1; i <= n; i++) {
    if (on_cycle[i]) {
      for (auto &it : g[i]) {
        int j = it.to;
        if (on_cycle[j]) {
          it.cycle = 1;
        }
      }
    }
  }
  clr();
  for (auto &x : cycle) {
    in_tree(x);
  }
  int sz = (int) cycle.size();
  vector<int> cost(sz);
  vector<ll> first(sz);
  vector<ll> second(sz);
  vector<ll> prefix1(sz);
  vector<ll> prefix2(sz);
  vector<ll> sufix1(sz);
  vector<ll> sufix2(sz);
  ll sol = INF, sum = 0;
  for (int i = 0; i < sz; i++) {
    int j = (i + 1) % sz;
    cost[i] = get_len(cycle[i], cycle[j]);
  }
  for (int i = 0; i < sz; i++) {
    first[i] = maxs[cycle[i]] + sum;
    second[i] = maxs[cycle[i]] - sum;
    sum += cost[i];
  }
  ll now = -INF, mx = -INF;
  for (int i = 0; i < sz; i++) {
    now = max(now, first[i] + mx);
    mx = max(mx, second[i]);
  }
  sol = min(sol, now);
  now = mx = -INF;
  for (int j = 0; j < sz; j++) {
    now = max(now, first[j] + mx);
    mx = max(mx, second[j]);
    prefix1[j] = now;
  }
  now = mx = -INF;
  for (int i = sz - 1; i >= 0; i--) {
    now = max(now, second[i] + mx);
    mx = max(mx, first[i]);
    sufix1[i] = now;
  }
  now = -INF;
  for (int i = 0; i < sz; i++) {
    now = max(now, first[i]);
    prefix2[i] = now;
  }
  now = -INF;
  ll cur = 0;
  for (int i = sz - 1; i >= 0; i--) {
    now = max(now, maxs[cycle[i]] + cur);
    if (i - 1 >= 0) {
      cur += cost[i - 1];
    }
    sufix2[i] = now;
  }
  for (int i = 0; i < sz - 1; i++) {
    /// skip cycle[i], cycle[i + 1]
    ll now = prefix1[i];
    now = max(now, sufix1[i + 1]);
    ll mx1 = prefix2[i], mx2 = sufix2[i + 1];
    now = max(now, mx1 + mx2 + cost.back());
    sol = min(sol, now);
  }
  for (int i = 1; i <= n; i++) {
    sol = max(sol, diam[i]);
  }
  cout << sol << "\n";
}