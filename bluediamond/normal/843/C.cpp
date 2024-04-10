#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2e5 + 7;
int n;
int sub[N];
int par[N];
vector<int> g[N];
bool isSquid[N];
bool vis[N];

vector<vector<int>> sol;

void baga(int a, int b, int c) {
  sol.push_back({a, b, c});
}

void dfs1(int a, int p = -1) {
  par[a] = p;
  sub[a] = 1;
  for (auto &b : g[a]) {
    if (b == p) continue;

    dfs1(b, a);
    sub[a] += sub[b];
  }
}

void solve(int a, int squid) {
  vis[a] = 1;
  queue<int> q;
  vector<int> ord;
  q.push(a);
  while (!q.empty()) {
    int x = q.front();
    ord.push_back(x);
    q.pop();
    for (auto &y : g[x]) {
      if (!vis[y]) {
        q.push(y);
        par[y] = x;
        vis[y] = 1;

      }
    }
  }
  reverse(ord.begin(), ord.end());
  ord.pop_back();
  int last = a;
  for (auto &v : ord) {
    if (par[v] != a) {
      baga(squid, last, v);
      baga(v, par[v], a);
      last = v;
    }
  }
  baga(squid, last, a);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  //freopen ("input", "r", stdin);

  cin >> n;
  for (int i = 1; i < n; i++) {
    int foo, bar;
    cin >> foo >> bar;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  dfs1(1);

  vector<int> squids;
  for (int i = 1; i <= n; i++) {
    int mx = n - sub[i];
    for (auto &j : g[i]) {
      if (j == par[i]) continue;
      mx = max(mx, sub[j]);
    }
    if (mx <= n / 2) {
      squids.push_back(i);
      isSquid[i] = 1;
      vis[i] = 1;
    }
  }

  assert((int) squids.size() == 1 || (int) squids.size() == 2);
  if ((int) squids.size() == 2) {
    assert(n % 2 == 0);
  }

  for (auto &squid : squids) {
    for (auto &x : g[squid]) {
      if (isSquid[x]) continue;

      solve(x, squid);
    }
  }

  cout << (int) sol.size() << "\n";
  for (auto &v : sol) {
    for (auto &x : v) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;

  cout << "squids : ";
  for (auto &squid : squids) {
    cout << squid << " ";
  }
  cout << "\n";

  return 0;
}