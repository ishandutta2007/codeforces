#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, v[N], under[N], total, root, prefix[N];
vector<int> g[N];
bool del[N];
ll sol;

void dfs1(int a, int p) {
  total++;
  under[a] = 1;
  for (auto &b : g[a]) {
    if (del[b] == 0 && b != p) {
      dfs1(b, a);
      under[a] += under[b];
    }
  }
}

void find_root(int a, int p) {
  bool is_root = (total - under[a]) <= total / 2;
  for (auto &b : g[a]) {
    if (del[b] == 0 && b != p) {
      is_root &= (under[b] <= total / 2);
      find_root(b, a);
    }
  }
  if (is_root) {
    root = a;
  }
}

ll t[30][2];
ll c[30][2];

void dfs2(int a, int p) {
  for (int j = 0; j < 30; j++) {
    int now = 0;
    if (prefix[a] & (1 << j)) {
      now = 1;
    }
    if (prefix[root] & (1 << j)) {
      now ^= 1;
    }
    sol += (1LL << j) * t[j][1 ^ now];
    if (prefix[root] & (1 << j)) {
      now ^= 1;
    }
    c[j][now]++;
  }
  sol += prefix[a];
  for (auto &b : g[a]) {
    if (del[b] == 0 && b != p) {
      prefix[b] = prefix[a] ^ v[b];
      dfs2(b, a);
    }
  }
}

void solve(int a) {
  total = 0;
  dfs1(a, -1);
  find_root(a, -1);
  prefix[root] = v[root];
  sol += prefix[root];
  for (int j = 0; j < 30; j++) {
    t[j][0] = t[j][1] = 0;
  }
  for (auto &b : g[root]) {
    if (del[b] == 0) {
      for (int j = 0; j < 30; j++) {
        c[j][0] = c[j][1] = 0;
      }
      prefix[b] = prefix[root] ^ v[b];
      dfs2(b, root);
      for (int j = 0; j < 30; j++) {
        t[j][0] += c[j][0];
        t[j][1] += c[j][1];
      }
    }
  }
  del[root] = 1;
  for (auto &b : g[root]) {
    if (del[b] == 0) {
      solve(b);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  solve(1);
  cout << sol << "\n";
}