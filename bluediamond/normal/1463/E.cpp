#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int n;
int k;
int p[N];
int x[N];
int y[N];
int t[N];
bool ok[N];
vector<int> bef[N];
vector<int> ord;
vector<int> members[N];
vector<int> g[N];
bool vis[N];
int pz[N];

int root(int x) {
  if (t[x] == x) {
    return x;
  } else {
    return t[x] = root(t[x]);
  }
}

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  t[x] = y;
}

void pune(int x) {
  vis[x] = 1;
  for (auto &y : bef[x]) {
    if (vis[y] == 0) {
      pune(y);
    }
  }
  ord.push_back(x);
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

///  freopen ("input", "r", stdin);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    t[i] = i;
  }
  map<pair<int, int>, int> mp;
  for (int i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
    mp[{x[i], y[i]}] = i;
    unite(x[i], y[i]);
  }
  for (int i = 1; i <= n; i++) {
    int j = p[i];
    /// j ... i
    if (j > 0 && root(j) != root(i)) {
      bef[root(i)].push_back(root(j));
    }
  }
  for (int i = 1; i <= n; i++) {
    if (t[i] == i && vis[i] == 0) {
      pune(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    members[root(i)].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    vis[i] = 0;
    bef[i].clear();
  }
  for (int i = 1; i <= k; i++) {
    bef[y[i]].push_back(x[i]);
  }
  vector<int> all = ord;
  for (int i = 1; i <= n; i++) {
    ord.clear();
    for (auto &j : members[i]) {
      if (vis[j] == 0) {
        pune(j);
      }
    }
    members[i] = ord;
  }
  vector<int> sol;
  for (auto &i : all) {
    for (auto &j : members[i]) {
      sol.push_back(j);
    }
  }
  int yy = -1;
  for (auto &xx : sol) {
    ok[mp[{yy, xx}]] = 1;
    yy = xx;
  }
  for (int i = 1; i <= k; i++) {
    if (!ok[i]) {
      cout << "0\n";
      return 0;
    }
  }
  int id = 0;
  for (auto &x : sol) {
    pz[x] = ++id;
  }
  for (int i = 1; i <= n; i++) {
    if (pz[p[i]] > pz[i]) {
      cout << "0\n";
      return 0;
    }
  }
  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
}