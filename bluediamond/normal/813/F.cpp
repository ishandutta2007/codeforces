#include <bits/stdc++.h>

using namespace std;

struct Data {
  bool bip;
  int a, xora, ha;
  int b, xorb, hb;
};

struct dsu {
  int n;
  bool bip = 1;
  vector<int> x, t, h;
  vector<Data> memo;
  dsu(int nn) {
    n = nn;
    x.resize(n + 1);
    t.resize(n + 1);
    h.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      x[i] = 0;
      t[i] = i;
      h[i] = 1;
    }
    bip = 1;
  }
  int root(int a) {
    if (t[a] == a) {
      return a;
    } else {
      return root(t[a]);
    }
  }
  int color(int a) {
    if (t[a] == a) {
      return x[a];
    } else {
      return x[a] ^ color(t[a]);
    }
  }
  void unite(int a, int b) {
    int f = a;
    int s = b;
    a = root(a);
    b = root(b);
    memo.push_back({bip, a, x[a], h[a], b, x[b], h[b]});
    if (a == b) {
      if (color(f) == color(s)) {
        bip = 0;
      }
      return;
    }
    if (h[a] > h[b]) {
      swap(a, b);
    }
    h[b] += (h[a] == h[b]);
    t[a] = b;
    if (color(f) == color(s)) {
      x[a] ^= 1;
    }
  }
  void rev() {
    Data it = memo.back();
    memo.pop_back();
    bip = it.bip;
    int a, b;
    a = it.a;
    b = it.b;
    t[a] = a;
    t[b] = b;
    x[a] = it.xora;
    x[b] = it.xorb;
    h[a] = it.ha;
    h[b] = it.hb;
  }
};

vector<bool> solve(int n, vector<pair<int, int>> operations) {
  int q = (int) operations.size();
  for (auto &it : operations) {
    if (it.second > it.first) {
      swap(it.first, it.second);
    }
  }
  vector<vector<pair<int, int>>> events(4 * q + 7);
  function<void(int, int, int, int, int, int, int)> add = [&] (int v, int tl, int tr, int l, int r, int x, int y) {
    if (tr < l || r < tl) {
      return;
    }
    if (l <= tl && tr <= r) {
      events[v].push_back({x, y});
      return;
    }
    int tm = (tl + tr) / 2;
    add(2 * v, tl, tm, l, r, x, y);
    add(2 * v + 1, tm + 1, tr, l, r, x, y);
  };
  map<pair<int, int>, int> last;
  set<pair<int, int>> s;
  for (int i = 0; i < q; i++) {
    pair<int, int> it = operations[i];
    if (s.count(it) == 0) {
      last[it] = i;
      s.insert(it);
    } else {
      add(1, 0, q - 1, last[it], i - 1, it.first, it.second);
      s.erase(it);
    }
  }
  for (auto &it : s) {
    add(1, 0, q - 1, last[it], q - 1, it.first, it.second);
  }
  vector<bool> ret(q);
  dsu d(n);
  function<void(int, int, int)> dfs = [&] (int v, int tl, int tr) {
    for (auto &it : events[v]) {
      d.unite(it.first, it.second);
    }
    if (tl == tr) {
      ret[tl] = d.bip;
    } else {
      int tm = (tl + tr) / 2;
      dfs(2 * v, tl, tm);
      dfs(2 * v + 1, tm + 1, tr);
    }
    for (auto &it : events[v]) {
      d.rev();
    }
  };
  dfs(1, 0, q - 1);
  return ret;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<pair<int, int>> Operations(q);
  for (int i = 0; i < q; i++) {
    cin >> Operations[i].first >> Operations[i].second;
  }
  vector<bool> x = solve(n, Operations);
  for (int i = 0; i < q; i++) {
    cout << (x[i] ? "YES" : "NO") << "\n";
  }
}