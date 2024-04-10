#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> link, rank;
  vector<int> stk;
  int ckp = 0;

  DSU(int n) : link(2 * n, -1), rank(2 * n, 0) {}
  
  
  int find(int x) {
    while (link[x] != -1) 
      x = link[x];
    return x;
  }

  void unite(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    if (rank[a] > rank[b]) swap(a, b);
    stk.push_back(a);
    link[a] = b;
    rank[b] += (rank[a] == rank[b]);
  }

  void Checkpoint() {
    ckp = stk.size();
  }

  void Undo() {
    while (stk.size() != ckp) {
      link[stk.back()] = -1;
      stk.pop_back();
    }
  }

  bool AddEdge(int a, int b) {
    if (find(2 * a) == find(2 * b))
      return false;

    unite(2 * a, 2 * b + 1);
    unite(2 * b, 2 * a + 1);
    assert(find(2 * a) != find(2 * a + 1));
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k; cin >> n >> m >> k;
  vector<int> color(n);
  for (int i = 0; i < n; ++i) {
    cin >> color[i];
    --color[i];
  }

  map<pair<int, int>, vector<pair<int, int>>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    if (color[a] > color[b]) swap(a, b);
    edges[make_pair(color[a], color[b])].emplace_back(a, b);
  }

  DSU dsu(n);
  long long answer = 1LL * k * (k - 1) / 2;
  int remain = k;
  vector<bool> bad(k, false);
  for (int i = 0; i < k; ++i) {
    for (auto [a, b] : edges[make_pair(i, i)]) {
      if (!dsu.AddEdge(a, b)) {
        bad[i] = true;
        break;
      }
    }
    if (bad[i]) {
      // cerr << "bad whole: " << i + 1 << endl;
      answer -= remain - 1;
      --remain;
    }
  }

  dsu.Checkpoint();
  for (auto [p, e] : edges) {
    if (p.first == p.second) continue;
    if (bad[p.first] || bad[p.second]) continue;
    
    for (auto [a, b] : e) {
      if (!dsu.AddEdge(a, b)) {
        // cerr << "bad pair: " << p.first + 1 << " " << p.second + 1 << '\n';
        answer -= 1;
        break;
      }
    }
    dsu.Undo();
  }

  cout << answer << endl;
  return 0;
}