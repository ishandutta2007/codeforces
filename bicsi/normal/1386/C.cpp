#include <bits/stdc++.h>

using namespace std;

struct DSU {
  vector<int> rank, link;
  vector<int> stk, chkp;

  DSU(int n) : rank(2 * n, 0), link(2 * n, -1) {}

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
  
  bool Try(int a, int b) {
    if (find(2 * a + 1) == find(2 * b + 1))
      return false;
    return true;
  }
  
  void Unite(int a, int b) {
    chkp.push_back(stk.size());
    unite(2 * a, 2 * b + 1);
    unite(2 * a + 1, 2 * b);
    assert(find(2 * a) != find(2 * a + 1));
  }
  
  void Undo() {
    for (int i = chkp.back(); i < (int)stk.size(); ++i)
      link[stk[i]] = -1;
    stk.resize(chkp.back());
    chkp.pop_back();
  }
};

struct Upd {
  int type, a, b;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, q; cin >> n >> m >> q;
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; ++i) {
    int a, b; cin >> a >> b;
    edges.emplace_back(a - 1, b - 1);
  }
  
  DSU dsu(n);
  vector<Upd> upds, tmp[2];
  int rem_a = 0;
  auto pop = [&]() {
    if (rem_a == 0) {
      reverse(upds.begin(), upds.end());
      for (int i = 0; i < (int)upds.size(); ++i)
        dsu.Undo();
      for (auto& upd : upds) {
        upd.type = 0;
        dsu.Unite(upd.a, upd.b);
      }
      rem_a = upds.size();
    }
    while (upds.back().type == 1) {
      tmp[1].push_back(upds.back());
      dsu.Undo();
      upds.pop_back();
    }
    int sz = (rem_a & (-rem_a));
    for (int i = 0; i < sz; ++i) {
      assert(upds.back().type == 0);
      tmp[0].push_back(upds.back());
      dsu.Undo();
      upds.pop_back();
    }
    for (int z : {1, 0}) {
      for (; tmp[z].size(); tmp[z].pop_back()) {
        auto upd = tmp[z].back();
        dsu.Unite(upd.a, upd.b);
        upds.push_back(upd);
      }
    }
    assert(upds.back().type == 0);
    upds.pop_back();
    dsu.Undo();
    --rem_a;
  };
  auto push = [&](int a, int b) {
    upds.push_back(Upd{1, a, b});
    dsu.Unite(a, b);
  };
  
  vector<int> dp(2 * m);
  int lbound = 0;
  for (int i = 0; i < 2 * m; ++i) {
    auto [a, b] = edges[i % m];
    while (!dsu.Try(a, b)) {
      pop();
      ++lbound;
    }
    push(a, b);
    dp[i] = lbound;
  }

  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b; --a; --b;
    if (dp[a + m - 1] <= b + 1) cout << "NO\n";
    else cout << "YES\n";
  }
}