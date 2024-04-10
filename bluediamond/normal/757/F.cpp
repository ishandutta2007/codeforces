#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef long double ld;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = (int) 3e5 + 7;
const int INF = (int) 1e18;
int n, m, root;
int dist[N];
vector<pair<int, int>> gg[N];
bool ok[N];

int kek[N];
vector<int> g[N], ig[N];

int dep[N], mn[N], cnt[N], col[N], y, un[N], branch[N], cox[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n >> m >> root;

  for (int i = 1; i <= m; i++) {
    int foo, bar, cod;
    cin >> foo >> bar >> cod;
    gg[foo].push_back({bar, cod});
    swap(foo, bar);
    gg[foo].push_back({bar, cod});
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  dist[root] = 0;
  priority_queue<pair<int, int>> pq;
  pq.push({-dist[root], root});
  while (!pq.empty()) {
    int node = pq.top().second;
    pq.pop();
    for (auto &it : gg[node]) {
      int nw = it.first;
      int nwd = it.second + dist[node];
      if (nwd < dist[nw]) {
        dist[nw] = nwd;
        pq.push({-nwd, nw});
      }
    }
  }

  vector<pair<int, int>> o;
  for (int i = 1; i <= n; i++) {
    for (auto &it : gg[i]) {
      if (dist[i] == dist[it.first] + it.second) {
        g[it.first].push_back(i);
        ig[i].push_back(it.first);
      }
    }
    if (dist[i] != INF) {
      o.push_back({dist[i], i});
    }
  }
  sort(o.begin(), o.end());


  vector<int> nodes;
  for (auto &it : o) {
    nodes.push_back(it.second);
  }

  assert(nodes[0] == root);
  branch[root] = root;
  for (auto &x : g[root]) {
    branch[x] = x;
  }

  for (auto &x : nodes) {
    if (branch[x]) continue;
    set<int> branches;
    for (auto &y : ig[x]) {
      branches.insert(branch[y]);
    }
    if ((int) branches.size() == 1) {
      branch[x] = branch[*branches.begin()];
    } else {
      branch[x] = x;
    }
  }

  for (auto &x : nodes) {
    cox[branch[x]]++;
  }
  cox[root]--;
  int sol = 0;
  for (auto &x : nodes) {
    sol = max(sol, cox[branch[x]]);
  }
  cout << sol << "\n";
}