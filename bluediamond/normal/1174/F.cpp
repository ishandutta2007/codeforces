#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n, root = 1, sub[N], dep[N], dep_me;
bool rem[N];
vector<int> nodes;
vector<int> g[N];

void dfs(int a, int p = 0) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (!rem[b] || b == p) continue;
    dep[b] = 1 + dep[a];
    dfs(b, a);
    sub[a] += sub[b];
  }
}

void recalc() {
  nodes.clear();
  dep[root] = 0;
  dfs(root);
}

int find_centroid(int a, int p = 0) {
  int mx = sub[root] - sub[a];
  for (auto &b : g[a]) {
    if (!rem[b] || b == p) continue;
    mx = max(mx, sub[b]);
  }
  if (mx <= sub[root] / 2) {
    return a;
  } else {
    for (auto &b : g[a]) {
      if (sub[b] == mx) {
        return find_centroid(b, a);
      }
    }
  }
  assert(0);
}

map<int, int> memo;

int get_dist(int a) {
  if (memo.count(a)) return memo[a];
  cout << "d " << a << endl;
  cin >> memo[a];
  if (memo[a] == 0) {
    cout << "! " << a << endl;
    exit(0);
  }
  return memo[a];
}

void solve() {
  recalc();
  if (sub[root] == 1) {
    cout << "! " << root << endl;
    exit(0);
  }
  int c = find_centroid(root);
  if (dep[c] + get_dist(c) == dep_me) {
    cout << "s " << c << endl;
    int node;
    cin >> node;
    rem[c] = 0;
    dep_me -= dep[node];
    root = node;
    solve();
    return;
  }
  rem[c] = 0;
  solve();
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) rem[i] = 1, nodes.push_back(i);
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dep_me = get_dist(1);
  solve();

}