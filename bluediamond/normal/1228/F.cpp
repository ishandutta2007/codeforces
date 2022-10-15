#include <bits/stdc++.h>


using namespace std;

const int N = (1 << 17) + 7;
int n, dim, sub[N], temp[N], who, pr[N];
bool pot[N];
vector<int> g[N];

int sz(int x) {
  assert(x >= 1);
  return (1 << x) - 1;
}

bool is_tree(int a, int x, int p = 0) {
  vector<int> kids;
  for (auto &b : g[a]) {
    if (b != p) kids.push_back(b);
  }
  if (x == 1) {
    return kids.empty();
  }
  if ((int) kids.size() != 2) return 0;
  if (!is_tree(kids[0], x - 1, a)) return 0;
  return is_tree(kids[1], x - 1, a);
}

void build(int a, int p = 0) {
  pr[a] = p;
  if (!p) pr[a] = -1;
  temp[a] = 1;
  for (auto &b : g[a]) {
    if (b != p) {
      build(b, a);
      temp[a] += temp[b];
    }
  }
}

bool is_half_tree(int a, int x, int p = 0) {
  assert(temp[a] == sz(x) - 1);
  vector<int> kids;
  vector<pair<int, int>> dims;
  for (auto &b : g[a]) {
    if (b != p) kids.push_back(b), dims.push_back({temp[b], b});
  }
  sort(dims.begin(), dims.end());
  if (x == 2) {
    if ((int) kids.size() != 1) return 0;
    who = a;
    return (dims[0].first == 1);
  }
  if ((int) kids.size() != 2) return 0;
  if (dims[0].first == sz(x - 1) - 1 && dims[1].first == sz(x - 1)) {
    return is_half_tree(dims[0].second, x - 1, a) && is_tree(dims[1].second, x - 1, a);
  }
  return 0;
}

void dfs(int a, int p = 0) {
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;
    dfs(b, a);
    sub[a] += sub[b];
  }
  vector<pair<int, int>> dims;
  for (auto &b : g[a]) if (b != p) dims.push_back({sub[b], b});
  if (p) {
    dims.push_back({dim - sub[a], p});
  }
  if ((int) dims.size() == 3) {
    sort(dims.begin(), dims.end());
    if (dims[0].first == sz(n - 2) && dims[1].first == sz(n - 2) && dims[2].first == sz(n - 1)) {
      pot[a] |= (is_tree(dims[0].second, n - 2, a) && is_tree(dims[1].second, n - 2, a) && is_tree(dims[2].second, n - 1, a));
    }
  }
  if ((int) dims.size() == 2) {
    sort(dims.begin(), dims.end());
    if (dims[0].first == sz(n - 1) - 1 && dims[1].first == sz(n - 1)) {
      who = -1;
      build(a);
      if (is_half_tree(a, n)) {
        assert(who != -1);
        pot[who] = 1;
      }
    }
  }
}

bool is(int a, int vert, int x = n, int p = 0) {
  assert(temp[a] == sz(x) - 1);
  vector<pair<int, int>> dims;
  for (auto &b : g[a]) {
    if (b != p) dims.push_back({temp[b], b});
  }
  sort(dims.begin(), dims.end());
  if (a == vert) {
    if ((int) dims.size() != 3) return 0;
    if (dims[0].first == sz(x - 2) && dims[1].first == sz(x - 2) && dims[2].first == sz(x - 1)) {
      return is_tree(dims[0].second, x - 2, a) && is_tree(dims[1].second, x - 2, a) && is_tree(dims[2].second, x - 1, a);
    }
    return 0;
  }
  if ((int) dims.size() != 2) return 0;
  if (dims[0].first == sz(x - 1) - 1 && dims[1].first == sz(x - 1)) {
    return is(dims[0].second, vert, x - 1, a) && is_tree(dims[1].second, x - 1, a);
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ///freopen ("input", "r", stdin);
  cin >> n;
  dim = (1 << n) - 2;
  for (int i = 1; i < dim; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  if (dim == 2) {
    cout << "2\n1 2\n";
    return 0;
  }
  /**
  daca se sterge radacina avem :
  un tree de n-1 si doi de n-2
  **/
  dfs(1);
  vector<int> g4;
  for (int i = 1; i <= dim; i++) {
    if ((int) g[i].size() > 4) {
      cout << "0\n";
      return 0;
    }
    if ((int) g[i].size() == 4) {
      g4.push_back(i);
    }
  }
  if ((int) g4.size() > 1) {
    cout << "0\n";
    return 0;
  }
  if (!g4.empty()) {
    int vert = g4[0], root = -1;
    build(vert);
    for (int i = 1; i <= dim; i++) {
      if (temp[i] == sz(n - 1)) root = pr[i];
    }
    if (root != -1) {
      build(root);
      if (is(root, vert)) {
        pot[vert] = 1;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= dim; i++) {
    if (pot[i]) cnt++;
  }
  cout << cnt << "\n";
  for (int i = 1; i <= dim; i++) {
    if (pot[i]) {
      cout << i << " ";
    }
  }
  cout << "\n";
}