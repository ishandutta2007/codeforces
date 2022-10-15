#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 7;
const int R = 333;
int n, m, maxcol, q;
vector<int> t = {0};

int addNode() {
  t.push_back((int) t.size());
  return t.back();
}

int root(int a) {
  if (t[a] == a) return a;
  return t[a] = root(t[a]);
}


set<int> g[N], ginv[N];
map<pair<int, int>, int> mp;

void ins(int a, int b) {
  assert(1 <= a && 1 <= root(b) && a <= n && root(b) <= n);
  g[a].insert(root(b));
  ginv[root(b)].insert(a);
}

void unite(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return;
  if (max(a, b) > n) {
    t[max(a, b)] = min(a, b);
    return;
  }
  if ((int) ginv[b].size() > (int) ginv[a].size()) swap(a, b);
  for (auto &node : ginv[b]) {
    assert(g[node].count(b));
    g[node].erase(b);
    ins(node, a);
  }
  ginv[b].clear();
  t[b] = a;
}

void add(int a, int b, int col) {
  if (!mp.count({b, col})) {
    mp[{b, col}] = addNode();
  }
  unite(a, mp[{b, col}]);
}


bool ok(int a, int b) {
  if (root(a) == root(b)) return 1;

  return g[b].count(root(a));
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> n >> m >> maxcol >> q;

  for (int i = 1; i <= n; i++) {
    addNode();
  }

  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
    add(b, a, c);
    ins(a, b);
    ins(b, a);
  }

  while (q--) {
    string type;
    cin >> type;
    if (type == "+") {
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, c);
      add(b, a, c);
      ins(a, b);
      ins(b, a);
    } else {
      int a, b;
      cin >> a >> b;
      cout << (ok(a, b) ? ("Yes") : ("No")) << "\n";
    }
  }

  return 0;
}