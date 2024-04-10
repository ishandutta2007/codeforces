#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int M = (int) 1e9 + 9;
const int B = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}


const int N = (int) 1e5 + 7;

int n, dist[N], sol[N], grad[N];
vector<int> g[N];
multiset<int> kids[N];

void algo(int a, int p, bool need = 1) {
  sol[a] = 0;
  if (need) {
    kids[a].clear();
    for (auto &b : g[a]) if (b != p) kids[a].insert(sol[b]);
  }
  if (kids[a].empty()) {
    sol[a] = 3333;
  } else {
    auto bg = kids[a].begin(), nd = kids[a].end();
    nd--;
    if (*bg != *nd || *bg == -1) {
      sol[a] = -1;
    } else {
      sol[a] = add(mul(*bg, B), grad[a]);
    }
  }
}

void dfs(int a, int p = -1) {
  for (auto &b : g[a]) if (b != p) dfs(b, a);

  algo(a, p);
}

void reroot(int a, int p) {
  kids[a].erase(kids[a].find(sol[p]));
  algo(a, p, 0);
  kids[p].insert(sol[a]);
  algo(p, -1, 0);
}

void go(int a, int p = -1) {
  if (sol[a] != -1) {
    cout << a << "\n";
    exit(0);
  }
  for (auto &b : g[a]) {
    if (b != p) {
      reroot(a, b);
      go(b, a);
      reroot(b, a);
    }
  }
}


signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    grad[x]++;
    grad[y]++;
  }

  int root = 2;
  root = min(root, n);
  dfs(root);
  go(root);
  cout << "-1\n";

  return 0;
}